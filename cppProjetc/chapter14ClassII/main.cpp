#include <iostream>
#include <string>
using namespace std;
#include "Date.h"
#include <iostream>
using namespace std;
//*************************************
// Function main                      *
//*************************************

int main()
{
	// Demonstrate the overloaded - and << operators. 
	Date d1(2, 2, 2006);
	Date d2(11, 10, 2003);
	int days = d1 - d2;
	cout << d1 << " minus " << d2 << " equals " << days << " days\n\n";

	// Demonstrate the overloaded ++ operators.
	cout << ++d1 << endl;
	cout << d1++ << endl;
	cout << d1 << endl;

	d1.setDay(31);
	d1.setMonth(12);
	cout << ++d1 << endl << endl;

	// Demonstrate the overloaded -- operators.
	d1.setDay(10);
	d1.setMonth(7);
	d1.setYear(2003);
	cout << --d1 << endl;
	cout << d1-- << endl;
	cout << d1 << endl;

	d1.setDay(1);
	d1.setMonth(1);
	d1.setYear(2004);
	cout << --d1 << endl;

	// Demonstrate the overloaded >> operator.
	cin >> d1;
	cout << "You entered " << d1 << endl;
	system("pause");
	return 0;
}