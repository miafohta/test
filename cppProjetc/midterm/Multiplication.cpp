#include <string> 
#include <iostream> 
#include <cctype>
#include "Multiplication.h"
using namespace std;

//Overload the stream insertion and extraction operators
ostream& operator<< (ostream &ostrm, const Multiplication &obj)
{
	ostrm << obj.num1 << " x " << obj.num2 << " = ";

	return ostrm;
}

//default constructor
//Postcondition: theAnswer=0; userResponse=0; 
//invokes randomize(); 
Multiplication::Multiplication()
{
	theAnswer = 0;
	userResponse = 0;
	randomize();
}

//Function to generate two random numbers between 1 and 10.
//Postcondition: num1 and num2 are equal to between 1 and 10;
//and theAnswer = num1 * num2;
void Multiplication::randomize()
{
	num1 = rand() % 10 + 1;
	num2 = rand() % 10 + 1;
	theAnswer = num1 * num2;
}

//Function to check userAnswer with problem answer (theAnswer)
//Postcondition: if theAnswer==userResponse appropriate feedback is displayed
// returns true if user answer is correct or returns false if user answer is incorrect;
bool Multiplication::checkAnswer()
{
	if (theAnswer == userResponse)
		return true;

	return false;
}

//Function to validate user response
//Postcondition: function accepts a string, validates it to be an int;
void Multiplication::validate(string str1)
{
	int ln = str1.length();
	int counter = 0;

	while (counter < ln || ln == 0)
	{
		//2. Validates that the entry is a number
		if (!isdigit(str1[counter]) || isspace(str1[counter]))
		{
			cout << "well, that is not number > 0, try again" << endl;
			getline(cin, str1);
			ln = str1.length();
			counter = 0;
		}
		else
		{
			counter++;
		}

	}
	int strint = atoi(str1.c_str());
	userResponse = strint;
}