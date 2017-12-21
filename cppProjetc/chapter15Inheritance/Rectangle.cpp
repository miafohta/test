#include "Rectangle.h"

//calcArea—calculates the area of the rectangle(area = length* width) 
//and stores the result in the inherited member area.
void Rectangle::calcArea()
{
	double a = length * width;
	setArea(a);
}
