#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
using namespace std;

class Date;

//function prototype..is this needed??
ostream &operator <<(ostream &, Date &); // Overloaded << operator
istream &operator >>(istream &, Date &); // Overloaded >> operator

// Constants
const int NUM_MONTHS = 12;

// Declaration of the Date class
class Date
{
public:
	// Constructors
	Date();
	Date(int, int, int);

	// Mutators
	void setMonth(int m);
	void setDay(int d);
	void setYear(int y);

	// Other member functions
	void showDate1();
	void showDate2();
	void showDate3();
	bool isLeapYear(int);

	// Overloaded operators
	Date operator ++();				// Prefix ++
	Date operator ++(int);			// Postfix ++
	Date operator --();				// Prefix --
	Date operator --(int);			// Postfix --
	bool operator >(const Date &);   // Greater-than operator
	int operator -(const Date &);	// Subtraction operator
	bool operator <(const Date &);   // Greater-than operator
	friend ostream &operator <<(ostream &, Date &); // Overloaded << operator
	friend istream &operator >>(istream &, Date &); // Overloaded >> operator

private:
	int month;  // To hold the month
	int day;    // To hold the day
	int year;   // To hold the year

	// An array of strings to hold
	// the names of the months
	string names[NUM_MONTHS];

	// An array to hold the number of days
	// that each month has.
	int numDays[NUM_MONTHS];

	// Private member function to assign
	// the month names to the names array
	void setNames();

	// Private member function to assign
	// the numbers of days to the numDays array
	void setDays();

	// Private member function to validate 
	// the date/month/year
	void simplify();
};
#endif
