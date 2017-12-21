#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <string>
using namespace std;

//The Circle template class
template <class Item>
class Circle
{
private:
	Item circleRadius;//store the value for the radius of the circle
	static int circleCount;//keep track of the number of circles
						   //I KNOW this is redundant since the number of circle objects is equal to the size of the vector,
						   //do it anyway!
public:
	//constructor
	Circle()
	{
		circleCount++;
		circleRadius = 0;
	}
	//post condition
	//increment circleCount by 1
	//circleRadius = 0

	//overloaded constructor
	Circle(Item radius);//you will create a class template which results in the creation of objects of type “Item”

	//getters
	int getCircleCount() const
	{
		return circleCount;
	}//return circleCount
	Item getCircleRadius() const
	{
		return circleRadius;
	}//return circleRadius;

	//setters
	void setCircleRadius(Item radius)
	{
		if (radius > 0)
			circleRadius = radius;
		else
			throw ErrorAllocatingMemory(radius);

	}//assigns the value of radius to circleRadius

	//exception
	//the purpose of this class is to catch potential errors caused by negative values for the radius of the circle
	class ErrorAllocatingMemory
	{
	private:
		Item value;
	public:
		ErrorAllocatingMemory(Item val)
		{
			value = val;
		}
		Item getValue()const 
		{
			return value;
		}
	};
};
#endif
//you will create a class template which results in the creation of objects of type “Item”
//post condition
//the radius may be an integer or a double
//radius >=0 and increment circleCount by 1
//in addition, if radius < 0, then throw ErrorAllocatingMemory exception
template <class Item>
Circle<Item>::Circle(Item radius)
{
	if (radius >= 0)
		circleCount++;
	else
		throw ErrorAllocatingMemory(radius);
}
template <class Item>
 int Circle<Item>::circleCount = 0;