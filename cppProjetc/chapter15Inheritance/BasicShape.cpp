#include "BasicShape.h"

BasicShape::BasicShape()
{
	area = 0.00;
}

double BasicShape::getArea() const
{
	return area;
}

void BasicShape::setArea(double d)
{
	if(d > 0.00)
		area = d;
}

