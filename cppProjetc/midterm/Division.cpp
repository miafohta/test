#include <string> 
#include <iostream> 
#include <vector>
#include <cctype>
#include "Division.h"
using namespace std;

//Overload the stream insertion and extraction operators
ostream& operator<< (ostream &ostrm, const Division &obj)
{
	ostrm << obj.num1 << " / " << obj.num2 << " = ";

	return ostrm;
}

//default constructor
//Postcondition: theAnswer=0; userResponse=0; 
//invokes randomize(); 
Division::Division()
{
	theAnswer = 0;
	userResponse = 0;
	randomize();
}

//Function to generate two random numbers between 1 and 10.
//Postcondition: num1 and num2 are equal to between 1 and 10;
//and theAnswer = num1 / num2;
void Division::randomize()
{
	num1 = rand() % 10 + 1;
	vector<int> div;

	if (num1 == 1)
		num2 = 1;
	else if (num1 = 2 || num1 == 3 || num1 == 5 || num1 == 7)
		div = { 1,num1 };
	else if (num1 == 4)
		div = { 1,2,4 };
	else if (num1 == 6)
		div = { 1,2,3,6 };
	else if (num1 == 8)
		div = { 1,2,4,8 };
	else if (num1 == 9)
		div = { 1,3,9 };
	else
		div = { 1, 2, 5, 10 };

	int r = rand() % div.size() + 1;
	num2 = div[r - 1];
	theAnswer = num1 / num2;
}

//Function to check userAnswer with problem answer (theAnswer)
//Postcondition: if theAnswer==userResponse appropriate feedback is displayed
// returns true if user answer is correct or returns false if user answer is incorrect;
bool Division::checkAnswer()
{
	if (theAnswer == userResponse)
		return true;

	return false;
}

//Function to validate user response
//Postcondition: function accepts a string, validates it to be an int;
void Division::validate(string str1)
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

