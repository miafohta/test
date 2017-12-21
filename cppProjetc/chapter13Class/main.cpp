// This program demonstrates the Integers class.
#include <iostream>
#include "Integers.h"
using namespace std;

int main()
{
	char userContinue = 'y';

	while (userContinue == 'y' || userContinue == 'Y')
	{
		Integers intList;
		intList.setUserEntry();
		intList.displayIntegers();
		intList.getLargestSmallestIntegers();
		cout << "Would you like to continue? Press Y to continue, or N to quit." << endl;
		cin >> userContinue;
		cin.ignore();
	}
	return 0;
}