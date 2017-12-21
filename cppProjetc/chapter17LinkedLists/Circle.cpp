#include "Circle.h"

Circle::Circle()
{
	circleCount++;
	circleRadius = 0;
}
Circle::Circle(int radius)
{
	if (radius >= 0)
	{
		circleCount++;
		setCircleRadius(radius);
	}
	else
		throw ErrorAllocatingMemory(radius);
}
Circle::~Circle()
{
	nextNodeLink = nullptr;
	delete nextNodeLink;
}
int Circle::getCircleCount() const
{
	return circleCount;
}//return the number of circle objects
int Circle::getCircleRadius() const
{
	return circleRadius;
}//return the radius of the circle
 //setters
void Circle::setCircleRadius(int radius)
{
	if (radius > 0)
		circleRadius = radius;
	else
		throw ErrorAllocatingMemory(radius);
}
int Circle::circleCount = 0;