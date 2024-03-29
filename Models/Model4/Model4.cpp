/*
 *
 *  This file is part of the Virtual Leaf.
 *
 *  The Virtual Leaf is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  The Virtual Leaf is distributed in the hope that it will be useful,
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



#include <QObject>
#include <QtGui>
#include <fstream>

#include "simplugin.h"
#include "parameter.h"
#include "wallbase.h"
#include "cellbase.h"
#include "flux_function.h"

#include "node.h"
#include "Model4.h"


static const std::string _module_id("$Id$");


QString Model4::ModelID(void) { return QString( "Model 4" ); }


int Model4::NChem(void) { return 9; }

// To be executed after cell division
void Model4::OnDivide(ParentInfo *parent_info, CellBase *daughter1, CellBase *daughter2) {
	daughter1->SetChemical(7, 1);
	daughter2->SetChemical(7, 1);
	daughter1->SetChemical(8, daughter1->Chemical(8)*0.75);
	daughter2->SetChemical(8, daughter2->Chemical(8)*0.75);
}
void Model4::SetCellColor(CellBase *c, QColor *color) { 
    double i2 = 0.0001;
	double i3 = 1;
    double i4 = 0.0001;

    double col = c->Chemical(6)/(i2 + c->Chemical(6));
    double blue = c->Chemical(1)/(i3 + c->Chemical(1));
    double PXYa_green = 0.6* c->Chemical(2)/(i4 + c->Chemical(2));
    double PXYa_blue = 0.4* c->Chemical(2)/(i4 + c->Chemical(2));

    color->setRgbF(0,col,blue);
    //color -> setRgbF(0, PXYa_green, blue);
    // 0 xylem

    if((c->CellType())==0)
    {
        color->setRgbF(0.5 ,0,0);
    }
	
	// 2 phloem poles
    else if((c->CellType())==2)
    {
        color->setRgbF(0.6,0.5,0.6);
    }
	
    else if((c->CellType()==3) || (c->CellType()==1) )
    {
        //color->setRgbF(0,0,1);
    }
	
    // 4 phloem parenchyma
    else if((c->CellType())==4)
    {
        color->setRgbF(0.79,0.78,0.79);
    }


    //double red = c->Chemical(7)/(0.1+ c->Chemical(7));
    //color->setRgbF(red,0,0);  //uncomment this line to visualize divisions
	 
    //double red = c->Chemical(0)/(1 + c->Chemical(0)); 	//uncomment this line to visualize CLE41
    //color->setRgbF(red,red,0);									//uncomment this line to visualize CLE41

	// color->setRgbF(0,col,blue);
	 
	//double red  = c->Chemical(8);
	//color->setRgbF(red,0,0);

    /*
    if((c->CellType())==0) {color->setRgbF(0,0.6,0.8);}
    if((c->CellType())==1) {color->setRgbF(0.7,0.2,0.2);}
    if((c->CellType())==2) {color->setRgbF(0.2,0.2,1);}
    if((c->CellType())==3) {color->setRgbF(0.5,0.8,0.8);}
    if((c->CellType())==4) {color->setRgbF(0.8,0.5,0.2);}
    if((c->CellType())==5) {color->setRgbF(0,0.5,0.6);}
    if((c->CellType())==6) {color->setRgbF(0.5,0.2,0.5);}
    if((c->CellType())==7) {color->setRgbF(0.65,0.5,0.55);}
    if((c->CellType())==8) {color->setRgbF(0.1,0.1,0.6);}
    if((c->CellType())==9) {color->setRgbF(0.5,0.5,0);}
    */
}
/*
void Model4::SetCellColor(CellBase *c, QColor *color) { 
	  double i2 = 0.0001;
	  double i3 = 1;
    double col = c->Chemical(9)/(i2 + c->Chemical(9));
    double blue = c->Chemical(1)/(i3 + c->Chemical(1));
    color->setRgbF(0,col,blue);
	double i2 = 0.0001;
  double col = c->Chemical(1)/(i2 + c->Chemical(1));
        color->setRgbF(col,0,0);
}
*/
void Model4::CellHouseKeeping(CellBase *c) {
      //cout << c->Index() << "\t" <<
              //c->CellType() << "\t" <<
              //c->Area() << "\t" <<
              //c->CalcLumenArea() << "\t" <<
              //c->ExactLumenCircumference() << "\t" <<
              //c->NNodes() << "\t" <<
              //c->Chemical(0) << "\t" <<
              //c->Chemical(1) << "\t" <<
              //c->Chemical(2) << "\t" <<
              //c->Chemical(3) << "\t" <<
              //c->Chemical(4) << "\t" <<
              //c->Chemical(5) << "\t" <<
              //c->Chemical(6) << "\t" <<
              //c->Chemical(7) << "\t" <<
              //c->Chemical(8) << "\t" <<
              //c->Length() << "\n" <<
              //c->GetWallStiffness() << "\t" <<

    double stab_xylem;
    stab_xylem = 2 * par->k3;
      // mature xylem
	if (c->CellType()==0) {
        c->SetWallStiffness(stab_xylem);
    //old, good c->SetChemical(2, 1.20);

		// cell should not grow unlimited
		if((c->Area() < par->k1 * c->BaseArea()))
		{
			c->EnlargeTargetArea(par->k2);
		}
	}
    // cell type 5 is untaken yet
    else if (c->CellType()==5) {
    }
	
	// phloem parenchyma
    else if (c->CellType()==4) {
        c->SetWallStiffness(2);
        // cell should not grow unlimited
        if((c->Area() < par->k7 * c->BaseArea()))
        {
			      c->EnlargeTargetArea(par->k2);
        }
        if (c->Area() > par->k8 * c->BaseArea() && c->Chemical(5) < par->k4 && !c->AtBoundaryP() )
		{
            c->SetCellType(2);
        }

        if ( c->Area() > c->BaseArea() * par->k15 && c->Chemical(6) > par->k0 )
        {
             c->Divide();
        }
    }
	//phloem poles
    else if (c->CellType()==2)
    {
    c->SetWallStiffness(2);
        // cell should not grow unlimited
        if(c->Area() <  par->k9 * c->BaseArea())
        {
			      c->EnlargeTargetArea(par->k2);
        }
    }
	
	// the rest of the cells are cambium
    else
    {
        //c->SetWallStiffness(1);
        // cell should not grow unlimited
        if((c->Area() < par->k10  * c->BaseArea())) {
			
			      c->EnlargeTargetArea(par->k2);
        }
        //Divide when at certain size and there is enough of PXY-active k6
         if ( c->Area() > c->BaseArea() * par->k16 && c->Chemical(6) > par->k6 ) {
			
            c->Divide();
        }
		
        else if (c->Chemical(6) > par->k5 ) {
			
			c->SetCellType(4);
        }
        else if ( c->Area() > par->k11  * c->BaseArea() && c->Chemical(1)  > par->k12 ) {
            c->SetCellType(0);
        }
    }
}
void Model4::CelltoCellTransport(Wall *w, double *dchem_c1, double *dchem_c2) {
    double phi, phi_2, phi_4, phi_5,  phi_6;

    // definition of correction factors to ensure mass conservation
    double A_tot = w->C1()->Area() + w->C2()->Area();
    double diff_cor1 = w->C2()->Area()/A_tot;
    double diff_cor2 = w->C1()->Area()/A_tot;

    if (w->C1()->BoundaryPolP() || w->C2()->BoundaryPolP()){
        phi   = 0.0;
        phi_2 = 0.0;
        phi_4 = 0.0;
        phi_5 = 0.0;
        phi_6 = 0.0;
    }
    else{
        phi    =  w->Length() * par->k21 * ( w->C2()->Chemical(0) - w->C1()->Chemical(0) );
        phi_2  =  w->Length() * par->D[0] * ( w->C2()->Chemical(3) - w->C1()->Chemical(3) );
        phi_4  =  w->Length() * par->D[0] * ( w->C2()->Chemical(4) - w->C1()->Chemical(4) );
        phi_5  =  w->Length() * par->D[0] * ( w->C2()->Chemical(5) - w->C1()->Chemical(5) );
        phi_6  =  w->Length() * par->D[0] * ( w->C2()->Chemical(6) - w->C1()->Chemical(6) );
    }
    dchem_c1[0]+=diff_cor1 * phi;
    dchem_c2[0]-=diff_cor2 * phi;
    dchem_c1[3]+=diff_cor1 * phi_2;
    dchem_c2[3]-=diff_cor2 * phi_2;
    dchem_c1[4]+=diff_cor1 * phi_4;
    dchem_c2[4]-=diff_cor2 * phi_4;
    dchem_c1[5]+=diff_cor1 * phi_5;
    dchem_c2[5]-=diff_cor2 * phi_5;
    dchem_c1[6]+=diff_cor1 * phi_6;
    dchem_c2[6]-=diff_cor2 * phi_6;
  
}
void Model4::WallDynamics(Wall *w, double *dw1, double *dw2) {
  // add biochemical networks for reactions occuring at walls here
}
void Model4::CellDynamics(CellBase *c, double *dchem) { 
  // add biochemical networks for intracellular reactions here
	
	// this sum allows additive effect from PXY-ACTIVE and chemical 3
    double sum = c->Chemical(3) + par->k14 * c->Chemical(2) ;
    double kuda = par->k17 ;
    double k   =  par->k18 ;
	//////////////////////////////////////////////////////////////////////////////////
	// rules which apply to all chemicals in any cell type are listed here ///////////
	//////////////////////////////////////////////////////////////////////////////////
	// CLE41
    dchem[0] = - par->k22 * c->Chemical(0) - 1 * c->Chemical(0) * c->Chemical(1);
	// PXY FREE
    dchem[1] = -1 * c->Chemical(0) * c->Chemical(1) - 0.1 * c->Chemical(1);
	// PXY ACTIVE
    dchem[2] =  1 * c->Chemical(0) * c->Chemical(1) - 0.1  * c->Chemical(2);
	// PROMOTES DIVISION CHEMICAL	(COMES FROM PHLOEM POLES)
    dchem[3] =  -0.1  * c->Chemical(3);
	// SUPRESSES PXY EXPRESSION	(COMES FROM ALL PHLOEM CELLS)
	dchem[4] =  -0.1  * c->Chemical(4);
	// SUPRESSES PHLOEM POLE FORMATION	(COMES FROM PHLOEM POLES)
	dchem[5] =  -0.1 * c->Chemical(5);
	// DIVISION CHEMICAL
	dchem[6] =  -0.1  * c->Chemical(6);
	// chemical 7 IS USED TO VISUALIZE CELL DIVISION -- HAS NO EFFECT ON THE MODEL
	dchem[7] = -0.01 * c->Chemical(7) ;
	//////////////////////////////////////////////////////////////////////////////
	/////////////////////////////
	// cell specific rules //////
	/////////////////////////////
    // vessels
    if(c->CellType()==0) {
		//dchem[0] = dchem[0] + 1 ;
        
    }
    
    else if(c->CellType()==5) {
		// cell type 5 is not taken yet
    }
    //phloem poles
    else if(c->CellType()==2)
    {
        dchem[0] = dchem[0] + par->k20 ;
        dchem[3] = dchem[3] + 1 ;
        dchem[4] = dchem[4] + 1 ;
        dchem[5] = dchem[5] + 1 ;
    }
    //phloem parenchyma
    else if(c->CellType()==4)
    {
        dchem[0] = dchem[0] + par->k19;
        dchem[4] = dchem[4] + 1 ;
        dchem[6] = dchem[6] + kuda * sum / (k+sum);
    }
	
	//cambium
    else
    {
        dchem[1] = dchem[1] + 1/(1 + par->k13 *c->Chemical(4));
        dchem[6] = dchem[6] + kuda * sum / (k+sum);
    }
}
