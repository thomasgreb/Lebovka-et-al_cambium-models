#include "vleafmodel.h"
#include "node.h"
#include "uncoupleCle.h"
static const std::string _module_id("$Id$");
QString uncoupleCle::ModelID(void) { return QString( "Model 3A" ); }
// return the number of chemicals your model uses
// Chemical(2) is thickness for me
// Chemical(3) is lignin for me
// so I have to change values
// 2 -> 9
// 3 -> 10
int uncoupleCle::NChem(void) { return 11; }
// To be executed after cell division
void uncoupleCle::OnDivide(ParentInfo *parent_info, CellBase *daughter1, CellBase *daughter2) {
	daughter1->SetChemical(7, 1);
	daughter2->SetChemical(7, 1);
	daughter1->SetChemical(8, daughter1->Chemical(8)*0.75);
	daughter2->SetChemical(8, daughter2->Chemical(8)*0.75);
}
void uncoupleCle::SetCellColor(CellBase *c, QColor *color) { 
	double i2 = 0.0001;
	double i3 = 1;
	
    double col = c->Chemical(6)/(i2 + c->Chemical(6));
    double blue = c->Chemical(1)/(i3 + c->Chemical(1));
    //double red = c->Chemical(9)/(par->i4 + c->Chemical(9));
    color->setRgbF(0,col,blue);
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
        color->setRgbF(0,0,1);
    }
	
    // 4 phloem parenchyma
    else if((c->CellType())==4)
    {
        color->setRgbF(0.79,0.78,0.79);
    }
	
	//double red = c->Chemical(7)/(0.1+ c->Chemical(7));
	//color->setRgbF(red,0,0);  //uncomment this line to visualize divisions
	 
	 
	// color->setRgbF(0,col,blue);
	 
	//double red  = c->Chemical(8);
	//color->setRgbF(red,0,0);
}
/*
void uncoupleCle::SetCellColor(CellBase *c, QColor *color) { 
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
void uncoupleCle::CellHouseKeeping(CellBase *c) {
      cout << c->Index() << "\t" <<
              c->CellType() << "\t" <<
              c->Area() << "\t" <<
              c->CalcLumenArea() << "\t" <<
              c->ExactLumenCircumference() << "\t" <<
              c->NNodes() << "\t" <<
              c->Chemical(0) << "\t" <<
              c->Chemical(1) << "\t" <<
              c->Chemical(2) << "\t" <<
              c->Chemical(3) << "\t" <<
              c->Chemical(4) << "\t" <<
              c->Chemical(5) << "\t" <<
              c->Chemical(6) << "\t" <<
              c->Chemical(7) << "\t" <<
              c->Chemical(8) << "\t" <<
              c->Chemical(9) << "\t" <<
              c->Chemical(10) << "\t" <<
              c->Length() << "\n";
	// mature xylem
	if (c->CellType()==0) {
    //old, good c->SetChemical(2, 1.20);
    c->SetChemical(2, par->k3);
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
        // cell should not grow unlimited
        if((c->Area() < par->k7 * c->BaseArea()))
        {
			      c->EnlargeTargetArea(par->k2);
        }
        if (c->Area() > par->k8 * c->BaseArea() && c->Chemical(5) < 1.80355e-006 && !c->AtBoundaryP() ) //setinmod is k4
		{
            c->SetCellType(2);
        }
        //mine if ( c->Area() > c->BaseArea() * 1 && c->Chemical(6) > par->wk5 )
        if ( c->Area() > c->BaseArea() * 0.669642 && c->Chemical(6) > par->wk5 ) //setinmod is k15
        {
             c->Divide();
        }
    }
	//phloem poles
    else if (c->CellType()==2)
    {
//c->SetChemical(2,1);
        // cell should not grow unlimited
        if(c->Area() <  par->k9 * c->BaseArea())
        {
			      c->EnlargeTargetArea(par->k2);
        }
    }
	
	// the rest of the cells are cambium
    else
    {
        // cell should not grow unlimited
        if((c->Area() < par->k10  * c->BaseArea())) {
			
			      c->EnlargeTargetArea(par->k2);
        }
        //Divide when at certain size and there is enough of PXY-active k6
         if ( c->Area() > c->BaseArea() * 0.819281 && c->Chemical(6) > par->k6 ) { //setinmod isk16
			
            c->Divide();
        }
		
        else if (c->Chemical(6) > par->k5 ) {
			
			c->SetCellType(4);
        }
        else if ( c->Area() > par->wk7  * c->BaseArea() && c->Chemical(1)  > par->wk9 ) {
            c->SetCellType(0);
        }
    }
}
void uncoupleCle::CelltoCellTransport(Wall *w, double *dchem_c1, double *dchem_c2) {
    double phi, phi_2, phi_4, phi_5,  phi_6;
    if (w->C1()->BoundaryPolP() || w->C2()->BoundaryPolP()){
        phi   = 0.0;
        phi_2 = 0.0;
        phi_4 = 0.0;
        phi_5 = 0.0;
        phi_6 = 0.0;
    }
    else{
        phi    =  w->Length() * par->D[0] * ( w->C2()->Chemical(0) - w->C1()->Chemical(0) );
        phi_2  =  w->Length() * par->D[0] * ( w->C2()->Chemical(10) - w->C1()->Chemical(10) );
        phi_4  =  w->Length() * par->D[0] * ( w->C2()->Chemical(4) - w->C1()->Chemical(4) );
        phi_5  =  w->Length() * par->D[0] * ( w->C2()->Chemical(5) - w->C1()->Chemical(5) );
        phi_6  =  w->Length() * par->D[0] * ( w->C2()->Chemical(6) - w->C1()->Chemical(6) );
    }
    dchem_c1[0]+=phi;
    dchem_c2[0]-=phi;
    dchem_c1[10]+=phi_2;
    dchem_c2[10]-=phi_2;
    dchem_c1[4]+=phi_4;
    dchem_c2[4]-=phi_4;
    dchem_c1[5]+=phi_5;
    dchem_c2[5]-=phi_5;
    dchem_c1[6]+=phi_6;
    dchem_c2[6]-=phi_6;
  
}
void uncoupleCle::WallDynamics(Wall *w, double *dw1, double *dw2) {
  // add biochemical networks for reactions occuring at walls here
}
void uncoupleCle::CellDynamics(CellBase *c, double *dchem) { 
  // add biochemical networks for intracellular reactions here
	
	// this sum allows additive effect from PXY-ACTIVE and chemical 3
	double sum = c->Chemical(10) + 142.761 * c->Chemical(9) ; //setinmod is k21
  double kuda = 0.0235261 ;  //setinmod is k17,  was 0.0142107  
  double k   =  34.4257 ;    //setinmod is k18, was 13.899     
	//////////////////////////////////////////////////////////////////////////////////
	// rules which apply to all chemicals in any cell type are listed here ///////////
	//////////////////////////////////////////////////////////////////////////////////
	// CLE41
	dchem[0] = -0.11 * c->Chemical(0) - 1 * c->Chemical(0) * c->Chemical(1);
	// PXY FREE
  dchem[1] = -1 * c->Chemical(0) * c->Chemical(1) - 0.1 * c->Chemical(1);
	// PXY ACTIVE
	dchem[9] =  1 * c->Chemical(0) * c->Chemical(1) - 0.1  * c->Chemical(9);
	// PROMOTES DIVISION CHEMICAL	(COMES FROM PHLOEM POLES)
	dchem[10] =  -0.1  * c->Chemical(10);
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
        dchem[0] = dchem[0] + 1.8685 ; //setinmod is k20 (was 1)
        dchem[10] = dchem[10] + 1 ;
        dchem[4] = dchem[4] + 1 ;
        dchem[5] = dchem[5] + 1 ;
    }
    //phloem parenchyma
    else if(c->CellType()==4)
    {
        dchem[0] = dchem[0] + 0.101138; //setinmod is k19 (was 0.1)
        dchem[4] = dchem[4] + 1 ;
        dchem[6] = dchem[6] + kuda * sum / (k+sum);
    }
	
	//cambium
    else
    {
        dchem[1] = dchem[1] + 1/(1 + 287.031 *c->Chemical(4)); //setinmod is k13
        dchem[6] = dchem[6] + kuda * sum / (k+sum);
    }
}
Q_EXPORT_PLUGIN2(uncoupleCle, uncoupleCle)
