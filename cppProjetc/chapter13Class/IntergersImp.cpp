#include <iostream>
#include <string>
#include <algorithm>
#include "Integers.h"
using namespace std;

Integers::Integers()
{
	list = new int[5];
	for (int i = 0; i < 5;i++)
		list[i] = 0;
}

void Integers::setUserEntry()
{
	int index =0;
	//string userInput;
	string userInput;
	while( index < 5 )
	{
		//1. Prompt the user for an integer
		cout << "Please enter integer. " << "index:" << index + 1 << endl;
		//getline(cin, userInput);
		cin >> userInput;
		//2. Invoke a method called validate which verifies that the entry is in fact an integer, 
		//if the entry is not an integer, the user is NOT allowed to proceed until he/she enters an integer.
		if (!validate(userInput))
		{
			cout << "You didn't entere integer. Please enter valid integer." << endl;
		}
		else
		{
			list[index] = stoi(userInput);
			index++;
		}
	}

}

bool Integers::validate(string userInput)
{
	int counter = 0;
	int strLength = userInput.length();
	//which verifies that the entry is in fact an integer, if the entry is not an integer,
	//the user is NOT allowed to proceed until he/she enters an integer.
	while (counter < strLength || strLength == 0)
	{
		// to take negative intger but not only negative sign.
		if ((counter > 0 || userInput[0] != '-' ) && !isdigit(userInput[counter]) || userInput[0] == '-' && strLength < 2 )
			return false;
		counter++;
	}

	return true;
}

void Integers::displayIntegers() const
{
	cout << "Integers you entered are" << endl;
	for (int i = 0; i < 5; i++)
		cout << list[i] << endl;
}

//The getLargestSmallestIntegers is a public function/method which displays the largest and the smallest integers in the array.
void Integers::getLargestSmallestIntegers() const
{
	sort(list, list + 5);
	cout << "The largest integer is " << list[4] << endl;
	cout << "The smallest integer is " << list[0] << endl;
}

Integers::~Integers()
{
	delete[] list;
}