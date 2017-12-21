#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include <string>
using namespace std;

//The Rectangle template class
template <class Item, class Item2>
class Rectangle
{
private:
	Item rectangleWidth;// store the value for the width of the rectangle
	Item2 rectangleLength;// store the value for the length of the rectangle
	static int rectangleCount;// ;//keep track of the number of rectangles
							  //I KNOW this is redundant since the number of rectangle objects is equal to the size of the vector,
							  //do it anyway!
public: 
    //constructor
	//post condition
	//increment rectangleCount by 1
	// rectangleWidth = 0
	// rectangleLength = 0
	Rectangle()
	{
		rectangleCount++;
		rectangleLength = 0;
		rectangleWidth = 0;
	}

	//overloaded constructor
	Rectangle(Item width, Item2 length);

	//getters
	int getRectangleCount() const
	{
		return rectangleCount;
	} // return rectangleCount

	Item getRectangleWidth() const
	{
		return rectangleWidth;
	}// return rectangleWidth;
	Item2 getRectangleLength() const
	{
		return rectangleLength;
	}// return rectangleLength;

	//setters
	void setRectangleWidth(Item w)
	{
		rectangleWidth = w;
	}// set rectangleWidth to w

	void setRectangleLength(Item2 l)
	{
		rectangleLength = l;
	}// set rectangleWidth to l

	//exception class
	class ErrorAllocatingLengthOrWidth //the purpose of this class is to catch potential errors caused by negative values for the length or width of the rectangle
	{
	private:
		Item value;
	public:
		ErrorAllocatingLengthOrWidth(Item v)
		{value = v;}
		Item getValue() const
		{return value;}
	};

};
#endif
//post condition
//the rectangleWidth may be an integer or a double
//the rectangleLength may be an integer or a double
//increment rectangleCount by 1
// rectangleWidth = 0
// rectangleLength = 0
//in addition, if rectangleWidth  < 0 or if rectangleLength  < 0, then throw ErrorAllocatingLengthOrWidth exception
template <class Item, class Item2>
Rectangle<Item, Item2>::Rectangle(Item width, Item2 length)
{
	if (width < 0 )
		throw ErrorAllocatingLengthOrWidth(width);
	else if(length < 0)
		throw ErrorAllocatingLengthOrWidth(length);
	else
	{
		rectangleWidth = width;
		rectangleLength = length;
		rectangleCount++;
	}
}
template <class Item, class Item2>
int Rectangle<Item, Item2>::rectangleCount = 0;