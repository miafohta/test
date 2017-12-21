#ifndef ARRAYOFOBJECTS_H
#define ARRAYOFOBJECTS_H
#include "Circle.h"
#include "Rectangle.h"
#include <iostream>
#include <string>
using namespace std;

template <class Item>
class ArrayOfObjects
{
private:
	Item *ptrToArrayOfObjects;//pointer to an array of type Item, where Item may be a Circle or Rectangle
	int qtyOfObjects;
public:
	//constructor 	//post condition
	// ptrToArrayOfObjects = 0
	// qtyOfObjects = 0;
	ArrayOfObjects()
	{
		ptrToArrayOfObjects = 0;
		qtyOfObjects = 0;
	}
	//overloaded constructor
	ArrayOfObjects(int arraySize);

	//overload [] operator
	Item& operator[](const int &x);

	class ErrorAllocatingPointerMemory
	{
		//the purpose of this class is to catch potential errors caused by negative values in arraySize
	private:
		int value;
	public:
		ErrorAllocatingPointerMemory(int val)
		{value = val;}
		int getValue() const
		{return value;}
	};
};
#endif

//post condition
// ptrToArrayOfObjects is dynamically allocated memory for an array of size arraySize and type Item.
//in addition, if (arraySize < 0, then throw an ErrorAllocatingPointerMemory  exception
template <class Item>
ArrayOfObjects<Item>::ArrayOfObjects(int arraySize)
{

	if (arraySize > 0)
	{
		ptrToArrayOfObjects = new Item[arraySize];
		qtyOfObjects = arraySize;
	}
	else
		throw ErrorAllocatingPointerMemory(arraySize);
}
//post condition
//Return the object of type Item located at index value x
template <class Item>
Item &ArrayOfObjects<Item>::operator[](const int &x)
{
	if ( x < 0 || x >= qtyOfObjects)
		throw ErrorAllocatingPointerMemory(x);

		return ptrToArrayOfObjects[x];
}

