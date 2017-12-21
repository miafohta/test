#ifndef CIRCLE_H
#define CIRCLE_H
#include "BasicShape.h"

using namespace std;

class Circle : public BasicShape
{
private:
	double centerX;
	double centerY;
	double radius;

public:
	//default constructor
	Circle()
	{ centerX = 0.00;
	  centerY = 0.00;
	  radius = 0.00; } 
	//constructor—accepts values for centerX, centerY, and radius.
	//Should call the overridden calcArea function described below.
	Circle(double x, double y, double r)
	{ centerX = x;
	  centerY = y;
	  radius = r;
	  calcArea(); }

	double getCenterX() const
		{return centerX;}
	double getCenterY() const
		{return centerY;}
	double getArea() const
		{return BasicShape::getArea();}
	virtual void calcArea();
};
#endif