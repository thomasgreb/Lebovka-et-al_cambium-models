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

#include "simplugin.h"

#include "parameter.h"

#include "wallbase.h"
#include "cellbase.h"
#include "uncoupleCle.h"

static const std::string _module_id("$Id$");

QString uncoupleCle::ModelID(void) {
    // specify the name of your model here
    return QString( "Model 2B" );
}

// return the number of chemicals your model uses
int uncoupleCle::NChem(void) { return 8; }

// To be executed after cell division
void uncoupleCle::OnDivide(ParentInfo *parent_info, CellBase *daughter1, CellBase *daughter2) {

	// chemical 6 is a trick to visualize time passed from division
	daughter1->SetChemical(6, 1);
	daughter2->SetChemical(6, 1);
}

void uncoupleCle::SetCellColor(CellBase *c, QColor *color) {
	
    // add cell coloring rules here
	double blue = c->Chemical(1)/(par->i3 + c->Chemical(1));
	double green = c->Chemical(2)/(par->i4 + c->Chemical(2));

	color->setRgbF(0,green,blue);

	//cell type 0 is xylem
	if((c->CellType())==0) {
		color->setRgbF(0.5,0,0);
	}
	else {
		//cell type 1 is cambium
		if((c->CellType())==1) {
			// cambium is colored according to chemicals above
		}
		else {
			//cell type 2 is phloem
			if((c->CellType())==2) {
				color->setRgbF(0.6,0.5,0.6);
			}
		}
	}
	// double red = c->Chemical(0)/(par->k[14] + c->Chemical(0)); 	//uncomment this line to visualize CLE41
	// color->setRgbF(red,red,0);									//uncomment this line to visualize CLE41
}

void uncoupleCle::CellHouseKeeping(CellBase *c) {

    // add cell behavioral rules here

    // xylem
    if (c->CellType()==0) {
		
        // cell should not grow unlimited
        if((c->Area() < 10 * c->BaseArea())) {
            c->EnlargeTargetArea(par->cell_expansion_rate);
        }
    } 
	else {

		// phloem
		if (c->CellType()==2) {
			
			// cell should not grow unlimited
			if((c->Area() <  10 * c->BaseArea())) {
				c->EnlargeTargetArea(par->cell_expansion_rate);
			}
		}
		// rest is cambium	
		else {
			// cell should not grow unlimited
			if((c->Area() < 10 * c->BaseArea())) {
				c->EnlargeTargetArea(par->cell_expansion_rate);
			}

			//Divide when at certain size and there is enough of PXY-active k[6]
			if ( c->Area() > c->BaseArea() * par->rel_cell_div_threshold && c->Chemical(2) > par->k[6] && c->Chemical(2)< par->k[7]) {

				c->Divide();
			}

		   //if a PXY cell grows grows bigger than certain limit it turns into phloem
			if ( c->Area() > c->BaseArea() * par->rel_cell_div_threshold * 1.2 && c->Chemical(2) < par->i5 ) {

			   c->SetCellType(0);
			}
			// if a cell grows grows bigger than certain limit it turns into phloem
			else if(c->Area() > c->BaseArea() * par->rel_cell_div_threshold * 2  )
			{
				c->SetCellType(2);
			}
		}
	}
}

void uncoupleCle::CelltoCellTransport(Wall *w, double *dchem_c1, double *dchem_c2) {
    // add biochemical transport rules here
    
	// this part allows CLE41 to diffuse
	double phi, phi_2, phi_3;
    if (w->C1()->BoundaryPolP() || w->C2()->BoundaryPolP()) {
		phi = 0.0;
		phi_2 = 0.0;
		phi_3 = 0.0;
	}
	else {
		phi  =  w->Length() * par->D[0] * ( w->C2()->Chemical(0) - w->C1()->Chemical(0) );
    }

    dchem_c1[0]+=phi;
    dchem_c2[0]-=phi;
}
void uncoupleCle::WallDynamics(Wall *w, double *dw1, double *dw2) {
    // add biochemical networks for reactions occuring at walls here
}
void uncoupleCle::CellDynamics(CellBase *c, double *dchem) {
    // add biochemical networks for intracellular reactions here
	
	// chemical 6 is a trick to visualize time passed from division
	// chemical 6 has no effect on the model at all
	dchem[6]  = -0.03* c->Chemical(6) ;
	
	//xylem
	if(c->CellType()==0) {

		//cle41 is produced degraded and is consumed by pxy binding
		dchem[0] =  par->k[2] - par->k[9] * c->Chemical(0) - 1 * c->Chemical(0) * c->Chemical(1);

		//free-pxy is consumed by pxy binding and is degraded
		dchem[1] = -1 * c->Chemical(0) * c->Chemical(1) - par->k[3] * c->Chemical(1);

		//bound-pxy is produced and is degraded
		dchem[2] =  1 * c->Chemical(0) * c->Chemical(1) - par->k[8] * c->Chemical(2);
	} 
	else {

		//phloem
		if(c->CellType()==2) {

			//cle41 is produced, degraded and is consumed by pxy binding
			dchem[0] =  par->k[2] - par->k[9] * c->Chemical(0) - 1 * c->Chemical(0) * c->Chemical(1);

			//free-pxy is consumed by pxy binding and is degraded
			dchem[1] = -1 * c->Chemical(0) * c->Chemical(1) - par->k[3] * c->Chemical(1);

			//bound-pxy is produced and is degraded
			dchem[2] =  1 * c->Chemical(0) * c->Chemical(1) - par->k[8] * c->Chemical(2);
		}
		else
		{
			dchem[0] =  -par->k[9] * c->Chemical(0) - 1 * c->Chemical(0) * c->Chemical(1);

			//free-pxy is consumed by pxy binding and is degraded
			dchem[1] = 1 /(1 + 100*c->Chemical(2))  -  1 * c->Chemical(0) * c->Chemical(1) - par->k[3] * c->Chemical(1);

			//bound-pxy is produced and is degraded
			dchem[2] =  1 * c->Chemical(0) * c->Chemical(1) - par->k[8] * c->Chemical(2);
		}
	}
}

Q_EXPORT_PLUGIN2(uncoupleCle, uncoupleCle)
