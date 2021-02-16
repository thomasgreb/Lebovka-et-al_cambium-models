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

#include <QtGui>
#include <QDoubleValidator>
#include <sstream>
#include "canvas.h"
#include "transporterdialog.h"

static const std::string _module_id("$Id: transporterdialog.cpp,v 15d600891648 2010/06/24 13:22:58 michael $");

TransporterDialog::TransporterDialog(Wall *w, CellBase *c, int wn, QWidget *parent)
  :  QDialog(parent), wall(w), cell(c), wall_num(wn)
{
  int frameStyle = QFrame::Plain | QFrame::NoFrame;
  QPushButton *ok = new QPushButton(tr("Ok"));
  QPushButton *cancel = new QPushButton(tr("Cancel"));
  QGridLayout *t_grid = new QGridLayout; // transporter grid

  // connect the slots
  connect(ok, SIGNAL(clicked()), this, SLOT(setTransporterValues()));
  connect(cancel, SIGNAL(clicked()), this, SLOT(close()));

  // compose a label for the dialog box
  std::stringstream label_text; 
  label_text << "C("<< wall->C1()->Index() << "," << wall->C2()->Index() << "), N(" 
	     << wall->N1()->Index() << "," << wall->N2()->Index() << ")";

  // retrieve the current transporters
  QVector <double> transporters;  // transporter vector
  ntransporters = cell->NChem(); // size of transporter vector
  for (int i=0; i<ntransporters; ++i){
    transporters << ((wall_num == 1) ? wall->Transporters1(i) : wall->Transporters2(i)); // dependent on the wall number of course.
  }

  // iterate over the vector of transporter values making a label/edit line for each
  for (int i=0; i<transporters.size(); ++i) {

    // label
    label = new QLabel;
    label->setFrameStyle(frameStyle);
    label->setText(QString("%1").arg(i+1)); // cardinal numbering

    // line editor
    QLineEdit *editor = new QLineEdit();
    editors << editor;
    editor->setValidator(new QDoubleValidator(editor)); // validator settings

    // assign the current transporter value
    QString n;
    editor->setText(n.setNum(transporters[i]));

    // insert the label and editor into the transporter grid
    t_grid->addWidget(label, i, 0);
    t_grid->addWidget(editor, i, 1);
  }

  // add OK and Cancel buttons
  QGridLayout *b_grid = new QGridLayout; // button grid
  b_grid->addWidget(ok, 0, 0);
  b_grid->addWidget(cancel, 0, 1);

  // add both transporter and button grids to the box layout widget
  QVBoxLayout *layout = new QVBoxLayout;
  layout->addLayout(t_grid);
  layout->addLayout(b_grid);
  setLayout(layout);

  setWindowTitle(tr(label_text.str().c_str()));
}

void TransporterDialog::setTransporterValues()
{
  // iterate over the editor widgets soliciting their values and setting the wall's transporters accordingly.
  for (int i=0; i<ntransporters; ++i){
#ifdef QDEBUG  
    qDebug() << "Transporter(" << i << "): " << editors[i]->text().toDouble() << endl;
#endif
    if (wall_num == 1)
      wall->setTransporters1(i, editors[i]->text().toDouble());
    else 
      wall->setTransporters2(i, editors[i]->text().toDouble());
  }
  editors.resize(0);
  close();
}

/* finis */


