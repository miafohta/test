
#ifndef BASICSHAPE_H
#define BASICSHAPE_H

#include <iostream>
#include <string>

using namespace std;

class BasicShape
{
public:
	//default constructor
	BasicShape(); 
	double getArea() const; //This function should return the value in the member variable area
	virtual void calcArea() = 0; // Pure virtual function
	void setArea(double); //This function should return the value in the member variable area
private:
	//area, a double used to hold the shape’s area.
	double area;

};
#endif