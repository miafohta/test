#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

//function proto type
double validateUserInput(string);

int main()
{
	string userinput;

	cout << "Please enter the x cordinate of the circle's center." << endl;
	getline(cin, userinput);
	double x = validateUserInput(userinput);

	cout << "Please enter the y cordinate of the circle's center." << endl;
	getline(cin, userinput);
	double y = validateUserInput(userinput);

	cout << "Please enter the radius the circle's center." << endl;
	getline(cin, userinput);
	double r = validateUserInput(userinput);

	Circle c(x, y, r);

	cout << "The area of circle is " << c.getArea() << endl;

	cout << "Please enter the width of the rectangle." << endl;
	getline(cin, userinput);
	double w = validateUserInput(userinput);

	cout << "Please enter the length of the rectangle." << endl;
	getline(cin, userinput);
	double l = validateUserInput(userinput);

	Rectangle rct(w, l);

	cout << "The area of the " << rct.getWidth() << " X ";
	cout << rct.getLength() << " is " << rct.getArea() << endl;

	system("pause");
	return 1;
}

double validateUserInput(string userinput)
{
	bool ok = false;
	double r = 0.00;
	while (!ok)
	{
		int len = userinput.length();
		int id = 0, ng = 0, prd = 0;
		if (len > 0)
		{
			for (int i = 0; i < len; i++)
				if (!isdigit(userinput[i]) && userinput[i] != '.')
					ng++;
				else if (isdigit(userinput[i]))
					id++;
				else if (userinput[i] == '.')
					prd++;
		}
		//conditions to pass the validation
		// 1.length has to be more than 0.
		// 2.input has to be either a digit or period.
		// 3.No more than one period. 
		if (len > 0 && ng == 0 && id > 0 && prd < 2 ) 
		{
			r = stod(userinput);
			if (r > 0) //4. number is more than 0.
				ok = true;
			else
			{
				cout << "You didn't enter valid number such as 0 <. Try again" << endl;
				getline(cin, userinput);
			}

		}
		else
		{
			cout << "You didn't enter valid number such as 0 <. Try again" << endl;
			getline(cin, userinput);
		}
		
	}

	return r;
}
