#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "BasicShape.h"

using namespace std;

class Rectangle : public BasicShape
{
private:
	double width;
	double length;
public:
	//default constructor
	Rectangle()
	{ width = 0;
	  length = 0;}
	// constructor—accepts values for width and length.
	//Should call the overridden calcArea, described below
	Rectangle(double w, double l)
	{ width = w;
	  length = l;
	  calcArea();}
	double getWidth() const
	{ return width; }
	double getLength() const
	{ return length; }
	double getArea() const
	{return BasicShape::getArea();}
	virtual void calcArea();


};

#endif