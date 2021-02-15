/**
@file main.cpp
*/
/*
 *
 *  This file is part of the Virtual Leaf.
 *
 *  VirtualLeaf is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  VirtualLeaf is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with the Virtual Leaf.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Copyright 2010 Roeland Merks.
 *
 */

#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <functional> 
#include <getopt.h>
#include <cerrno>
#include "mesh.h"
#include "parameter.h"
#include "random.h"
#include "pi.h"
#include "cellitem.h"
#include "canvas.h"
#include "cell.h"
#include "output.h"
#include <qwidget.h>
#include <q3process.h>
#include <qapplication.h>
#include <QDesktopWidget>
#include <QGraphicsScene>
#include <QMessageBox>
//Added by qt3to4:
#include <QMouseEvent>

#include <unistd.h>
#include <q3textstream.h> 

#ifdef HAVE_QWT
#include "data_plot.h"
#endif
#include <QPalette>
#include <QBrush>
#include <QToolTip>
#include "simplugin.h"
#include <QPluginLoader>
#include <QDir>
#include "modelcatalogue.h"

static const std::string _module_id("$Id$");

extern Parameter par;

MainBase *main_window = 0;

#ifdef XFIGGRAPHICS
#define TIMESTEP double Graphics::TimeStep(void)
#endif

class PrintNode {
public:
  void operator() (const Node &n) const 
  {
    cerr << n.Index() << ": " << n <<  "\n";
  }
};


class EdgeSource {

public:
  void operator() (Cell &c) {

    if (c.AtBoundaryP()) {
      cerr << "Cell " << c.Index() << " is a source cell.\n";
      //c.SetSource(0,par.source);
    } else {
      cerr << "Cell " << c.Index() << " is _not_ a source cell.\n";
    }
  }
};



class CellInfo {
public:
  void operator() (Cell &c,std::ostream &os) const {
    os << "Cell " << c.index << " says: " << "\n";
    os << "c.nodes.size() = " << c.nodes.size() << "\n";
    for (list<Node *>::iterator i=c.nodes.begin(); i!=c.nodes.end(); ++i) {
      cerr << (*i)->Index() << " ";
    }
    cerr << "\n";
  }
};

double TRANSP0Sum(Cell &c) {
  return c.Chemical(0) + c.SumTransporters(0);// + c.ReduceCellAndWalls<double>( complex_PijAj );
}


class DrawCell {
public:
  void operator() (Cell &c,QGraphicsScene &canvas, MainBase &m) const {
    if (m.ShowBorderCellsP() || c.Boundary()==Cell::None) {
      if (!m.ShowBoundaryOnlyP() && !m.HideCellsP()) {
	if (m.ShowToolTipsP()) {
	  //QString info_string=QString("Cell %1, chemicals: ( %2, %3, %4, %5, %6)\n %7 of TRANSP0 at walls.\n Area is %8\n TRANSP0 sum is %9\n Circumference is %10\n Boundary type is %11").arg(c.Index()).arg(c.Chemical(0)).arg(c.Chemical(1)).arg(c.Chemical(2)).arg(c.Chemical(3)).arg(c.Chemical(4)).arg(c.SumTransporters(1)).arg(c.Area()).arg(PINSum(c)).arg(c.Circumference()).arg(c.BoundaryStr());
		QString info_string=QString("Cell %1, chemicals(%2): ").arg(c.Index()).arg(Cell::NChem());
		for (int i=0;i<Cell::NChem();i++) {
			info_string += QString("%1 ").arg(c.Chemical(i));
		}
		info_string += QString("\nArea is %1\n Circumference is %2\n Boundary type is %3").arg(c.Area()).arg(c.WallCircumference()).arg(c.BoundaryStr());
		
	  info_string += "\nNodes: " + c.printednodelist();
	  c.Draw(&canvas, info_string);
	} else {
	  c.Draw(&canvas);
	}
      }
      if (m.ShowCentersP()){
	c.DrawCenter(&canvas);
      }
      if (m.ShowFluxesP()){
	c.DrawFluxes(&canvas, par.arrowlength);
      }
    }
  }
};

Mesh mesh;
bool batch=false;

void MainBase::Plot(int resize_stride)
{

  clear();

  int count=(int)mesh.getTime();

  if (resize_stride) {
    if ( !((count)%resize_stride) ) {
      FitLeafToCanvas();
    }
  }

  mesh.LoopCells(DrawCell(),canvas,*this);

  if (ShowNodeNumbersP()) 
    mesh.LoopNodes( bind2nd (mem_fun_ref ( &Node::DrawIndex), &canvas ) ) ;
  if (ShowCellNumbersP()) 
    mesh.LoopCells( bind2nd (mem_fun_ref ( &Cell::DrawIndex), &canvas ) ) ;

  if (ShowCellAxesP()) 
    mesh.LoopCells( bind2nd (mem_fun_ref ( &Cell::DrawAxis), &canvas ) );

  if (ShowCellLigniP()) 
    mesh.LoopCells( bind2nd (mem_fun_ref ( &Cell::DrawLigni), &canvas ) );

  if (ShowCellThickP()) 
    mesh.LoopCells( bind2nd (mem_fun_ref ( &Cell::DrawThick), &canvas ) );

  if (ShowCellStrainP()) 
    mesh.LoopCells( bind2nd (mem_fun_ref ( &Cell::DrawStrain), &canvas ) );

  if (ShowWallsP())
    mesh.LoopWalls( bind2nd( mem_fun_ref( &Wall::Draw ), &canvas ) );

  /*  if (ShowApoplastsP()) 
      mesh.LoopWalls( bind2nd( mem_fun_ref( &Wall::DrawApoplast ), &canvas ) );
  */
  if (ShowMeshP()) 
    mesh.DrawNodes(&canvas);

  if (ShowBoundaryOnlyP()) 
    mesh.DrawBoundary(&canvas);

  if ( ( batch || MovieFramesP() )) {
    if ((par.storage_stride !=0) && (count%par.storage_stride == 0)) {
      stringstream fname;
      fname << par.datadir << par.export_fn_prefix;
      fname.fill('0');
      fname.width(6);
      fname << count << ".png";
      // Write high-res PNG snapshot every plot step
      // Use MainBase::Save
      Save(fname.str().c_str(), "PNG", 1000, 1000);
    }
    if ((par.export_interval !=0) && (count%par.export_interval == 0)) {
      stringstream fname;
      fname << par.datadir << par.export_fn_prefix;
      fname.fill('0');
      fname.width(6);
      fname << count << ".csv";
    
      QFile file(QString(fname.str().c_str()));
      if ( file.open( IO_WriteOnly ) ) {
        QTextStream stream( &file );
        mesh.CSVExportCellData(stream);
        mesh.CSVExportWallData(stream);
        mesh.CSVExportMeshData(stream);
        file.close();
      }
    }

    if ((par.xml_storage_stride !=0) && (count%par.xml_storage_stride == 0)) {
      stringstream fname;
      fname << par.datadir << par.export_fn_prefix;
      fname.fill('0');
      fname.width(6);
      fname << count << ".xml";
      // Write XML file every ten plot steps
      mesh.XMLSave(fname.str().c_str(), XMLSettingsTree());
    }
  }
}


INIT {

  //mesh.SetSimPlugin(plugin);
  if (leaffile) { 
    if (qApp->type()==QApplication::Tty) {
      
      xmlNode *settings;
      mesh.XMLRead(leaffile, &settings);
      
      main_window->XMLReadSettings(settings);
      xmlFree(settings);
      main_window->UserMessage(QString("Ready. Time is %1").arg(mesh.getTimeHours().c_str()));
    } else {
      ((Main *)main_window)->readStateXML(leaffile);
    }
    
  } else {
    mesh.StandardInit();
  }
  
  Cell::SetMagnification(1);
  Cell::setOffset(0,0);
  
  FitLeafToCanvas();
  Plot();

}

TIMESTEP {

  static int i=0;
  static int t=0;
  static int ncells;

  if (!batch) {
    UserMessage(QString("Time: %1").arg(mesh.getTimeHours().c_str()),0);
  }

  ncells=mesh.NCells();


  double dh;

  if(DynamicCellsP()) {
    dh = mesh.DisplaceNodes();

    // Only allow for node insertion, cell division and cell growth
    // if the system has equillibrized
    // i.e. cell wall tension equillibrization is much faster
    // than biological processes, including division, cell wall yielding
    // and cell expansion
    mesh.InsertNodes(); // (this amounts to cell wall yielding)
    if ( (-dh) < par.energy_threshold) {

      mesh.IncreaseCellCapacityIfNecessary();
      mesh.DoCellHouseKeeping();
//      mesh.CellTypeDefinitor();
      //mesh.LoopCurrentCells(mem_fun(&plugin->CellHouseKeeping)); // this includes cell division
      // Reaction diffusion	
      mesh.ReactDiffuse(par.rd_dt);
      t++;
      Plot(par.resize_stride);
      //cerr << -dh << "\n";
      //cout <<"  Step " << t << " done" << "\n";
    }
  } else {
    mesh.ReactDiffuse(par.rd_dt);
    Plot(par.resize_stride);
  }
  i++;
      //cerr <<"Iteration" << i << " done" << "\n";
      //cerr << "\n";
      //cout << t << "\t" << i << "\t" << dh << "\n";
  return mesh.getTime();
}



  /* Called if a cell is clicked */
void Cell::OnClick(QMouseEvent *e){
  //cout << e->isAccepted() << "\n";
  //int tipo = this->CellType();
  //cout << this->Index() << "\n";
  //cout << tipo << "\n";
  if (e->button() == Qt::LeftButton) {
  this->Apoptose();
  for (list<Node *>::iterator i=this->nodes.begin(); i!=this->nodes.end(); ++i) {
     (*i)->SetBoundary();
  }
  mesh.TestIllegalWalls();
  mesh.CleanUpCellNodeLists();
  mesh.TestIllegalWalls();
  mesh.RepairBoundaryPolygon();
  mesh.TestIllegalWalls();
  mesh.CleanUpWalls();
  mesh.TestIllegalWalls();
  mesh.CleanUpCellNodeLists();

  //this->SetCellType(4);
  //} else if (e->button() == Qt::MidButton) {
  //this->SetCellType(5);
  } else {
    if (e->button() == Qt::RightButton) {
   //cout << "max-ax:" << this->Length() << "\t" << "min-ax:" << this->Width() << "\n";
    this->SetCellType(4);
    //this->SetChemical(0,10);
  //this->Divide();
    }
  }
  //cout << this->CellType() << "\n";
  //cout << "\r" << "\n";
}

  /* Custom message handler - Default appends a newline character to the end of each line. */ 
void vlMessageOutput(QtMsgType type, const char *msg)
{
  switch (type) {
  case QtDebugMsg:
    //fprintf(stderr, "Debug: %s\n", msg);
    cerr << msg << flush;
    break;
  case QtWarningMsg:
    //fprintf(stderr, "Warning: %s\n", msg);
    cerr << "Warning: " << msg << flush;
    break;
  case QtCriticalMsg:
    fprintf(stderr, "Critical: %s\n", msg);
    cerr << "Critical: " << msg << flush;
    break;
  case QtFatalMsg:
    //fprintf(stderr, "Fatal: %s\n", msg);
    cerr << "Fatal: " << msg << flush;
    abort();
  }
}


Parameter par;

int main(int argc,char **argv) {

  try {
    int c;
    char *leaffile=0;
    char *modelfile=0;

    while (1) {

      //int this_option_optind = optind ? optind : 1;
      int option_index = 0;
      static struct option long_options[] = {
	{"batch", no_argument, NULL, 'b'},
	{"leaffile", required_argument, NULL, 'l'},
	{"model", required_argument, NULL, 'm'} 
      };

      // short option 'p' creates trouble for non-commandline usage on MacOSX. Option -p changed to -P (capital)
      static char *short_options = "bl:m:";
      c = getopt_long (argc, argv, short_options,
		       long_options, &option_index);
      if (c == -1)
	break;


      if (c==0) {
	printf ("option %s", long_options[option_index].name);
	if (optarg)
	  printf (" with arg %s", optarg);
	printf ("\n");

	c = short_options[option_index];
      }

      switch (c) {
      case 'b':
	cerr << "Running in batch mode\n";
	batch=true;
	break;

      case 'l':
	leaffile=strdup(optarg);
	if (!leaffile) {
	  throw("Out of memory");
	}
	printf("Reading leaf state file '%s'\n", leaffile);
	printf("########### REMEMBER YOU'RE USING par.mc_stepsize ###########\n");
	break;

      case 'm':
	modelfile=strdup(optarg);
	if (!modelfile) {
	  throw("Out of memory");
	}
	break;

      case '?':
	break;

      default:
	printf ("?? getopt returned character code 0%o ??\n", c);
      }
    }


    if (optind < argc) {
      printf ("non-option ARGV-elements: ");
      while (optind < argc)
	printf ("%s ", argv[optind++]);
      printf ("\n");
    }

    bool useGUI = !batch;
    qInstallMsgHandler(vlMessageOutput); // custom message handler
    QApplication app(argc,argv,useGUI);



    QPalette tooltippalette = QToolTip::palette();
    QColor transparentcolor = QColor(tooltippalette.brush(QPalette::Window).color());

    tooltippalette.setBrush (QPalette::Window, QBrush (transparentcolor) );
    QToolTip::setPalette( tooltippalette );

    QGraphicsScene canvas(0,0,8000,6000);


    if (useGUI) {
      main_window=new Main(canvas, mesh);
      if ( QApplication::desktop()->width() > ((Main *)main_window)->width() + 10
	   && QApplication::desktop()->height() > ((Main *)main_window)->height() +30 ) {

	((Main *)main_window)->show();
	((Main *)main_window)->resize( ((Main *)main_window)->sizeHint());
      } else {
	((Main *)main_window)->showMaximized();
      }
      
      // show "About" window at start up
      //((Main *)main_window)->about();
    } else {
      main_window=new MainBase(canvas, mesh);
    }

    canvas.setSceneRect(QRectF());
    if (!batch) {
      QObject::connect( qApp, SIGNAL(lastWindowClosed()), qApp, SLOT(quit()) );
    }

    //    main_window->Init(leaffile);

    // Install model or read catalogue of models
    ModelCatalogue model_catalogue(&mesh, main_window,modelfile);


    if (useGUI)
      model_catalogue.PopulateModelMenu();
    model_catalogue.InstallFirstModel();
    main_window->Init(leaffile);
    
    

    /*    Cell::SetMagnification(1);
	  Cell::setOffset(0,0);

	  main_window->FitLeafToCanvas();

	  main_window->Plot();
    */
    if (batch) {
      double t=0.;
      do {
	t = main_window->TimeStep();
      } while (t < par.maxt);
    } else
      return app.exec();

  } catch (const char *message) {
    if (batch) { 
      cerr << "Exception caught:" << "\n";
      cerr << message << "\n";
      abort();
    } else {
      QString qmess=QString("Exception caught: %1").arg(message);
      QMessageBox::critical(0, "Critical Error", qmess);
      abort();
    }
  } catch (ios_base::failure) {
    stringstream error_message;
    error_message << "I/O failure: " << strerror(errno);
    if (batch) {
      cerr << error_message.str().c_str() <<"\n";
      abort();
    } else {
      QString qmess(error_message.str().c_str());
      QMessageBox::critical(0, "I/O Error", qmess );
      abort();
    }
  }
}

/* finis */
