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
#include <sstream>
#ifdef QTGRAPHICS
#include <qstring.h>
#include <QGraphicsSimpleTextItem>
#endif
#include "node.h" 
#include "cell.h"
#include "mesh.h"
#include "random.h"
#include "parameter.h"
#include "sqr.h"
#include "pi.h"
#include "warning.h"

static const std::string _module_id("$Id: node.cpp,v 15d600891648 2010/06/24 13:22:58 michael $");

extern Parameter par;

int Node::nnodes=0;
double Node::target_length=1;

ostream &Edge::print(ostream &os) const {
  return os << "{ " << first->Index() << ", " << second->Index() << " }";
}

ostream &Neighbor::print(ostream &os) const {

  os << " {" << cell->Index() << " " << nb1->Index() << " " << nb2->Index() << "}";
  return os;
}

ostream &operator<<(ostream &os, const Neighbor &n) {
  n.print(os);
  return os;
}


Node::Node(void) : Vector()
{
  index=(nnodes++);
  node_set =0;
  fixed=false;
  boundary=false;
  sam=false;
  dead=false;
}

Node::Node(int ind) : Vector()
{
  node_set =0;
  index=ind;
  fixed=false;
  boundary=false;
  sam=false;
  dead=false;
}

Node::Node(const Vector &src) : Vector(src)
{
  node_set = 0;
  index=(nnodes++);
  fixed=false;
  boundary=false;
  sam=false;
  dead = false;
}

Node::Node(double x,double y, double z) : Vector (x,y,z)
{
  node_set = 0;
  index=(nnodes++);
  fixed=false;
  boundary=false;
  sam=false;
  dead = false;
}

Node::Node(const Node &src) : Vector(src)
{
  node_set=0;
  owners=src.owners;
  m=src.m;
  index=src.index;
  fixed = src.fixed;
  boundary = src.boundary;
  sam=src.sam;
  dead = src.dead;
}


Cell &Node::getCell(const Neighbor &i)
{
  return *i.getCell(); // use accessor!
}


ostream &Node::print(ostream &os) const {

  if (!dead) 
    os << "Node ";
  else
    os << "DEAD NODE ";

  os  << index << "[ {" << x << ", " << y << ", " << z << "}: {";

  os << "Neighbors = { ";

  for (list<Neighbor>::const_iterator i =  owners.begin(); i!=owners.end(); i++) {
    os << " {" << i->cell->Index() << " " << i->nb1->Index() << " " << i->nb2->Index() << "} ";
  }
  os << " } " << endl;

  return os;
}


#ifdef QTGRAPHICS
void Node::DrawIndex(QGraphicsScene *c) const {

  //return DrawOwners(c);
  stringstream text;
  text << index;
  QGraphicsSimpleTextItem *number = new QGraphicsSimpleTextItem ( QString (text.str().c_str()), 0, c );
  number->setFont( QFont( "Helvetica", par.nodenumsize, QFont::Bold) );
  number->setPen( QPen (par.textcolor) );
  number->setZValue(20);
  number->show();
  Vector offs=Cell::Offset();
  number -> setPos(
		   ((offs.x+x)*Cell::Factor()),
		   ((offs.y+y)*Cell::Factor()) );
}

void Node::DrawOwners(QGraphicsScene *c) const {

  stringstream text;
  text << owners.size();

  QGraphicsSimpleTextItem *number = new QGraphicsSimpleTextItem ( QString (text.str().c_str()), 0, c );
  number->setFont( QFont( "Helvetica", par.nodenumsize, QFont::Bold) );
  number->setPen( QPen(par.textcolor) );
  number->setZValue(20);
  number->show();
  Vector offs=Cell::Offset();

  number ->setPos(((offs.x+x)*Cell::Factor()),
		  ((offs.y+y)*Cell::Factor()) );
}


QVector<qreal> Node::NeighbourAngles(void)
{
  QVector<qreal> angles;
  for (list<Neighbor>::iterator i=owners.begin(); i!=owners.end(); i++) {
    Vector v1 = (*this - *i->nb1).Normalised();
    Vector v2 = (*this - *i->nb2).Normalised();	

    double angle = v1.SignedAngle(v2);
    if (angle<0) {
      //cerr << "Changing sign of angle " << angle << endl;
      angle = angle + 2*Pi;
    }
    angles.push_back(angle);

    //cerr << "Cell " << i->cell->Index() << ": " <<  v1 << " and " << v2 
    //     << ": angle = " << angles.back() << ", " << v1.Angle(v2) << endl;

  }

  double sum=0.;
  for (QVector<qreal>::iterator i=angles.begin(); i!=angles.end(); i++) {
    sum+=*i;
  }
  //cerr << "Angle sum = " << sum << endl;
  // Check if the summed angle is different from 2 Pi 
  if (fabs(sum-(2*Pi))>0.0001) {

    MyWarning::warning("sum = %f",sum);
  }
  return angles;
}


#endif

ostream &operator<<(ostream &os, const Node &n) {
  n.print(os);
  return os;
}

/* finis */
