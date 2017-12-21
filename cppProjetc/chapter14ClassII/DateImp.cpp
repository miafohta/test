#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

//**********************************
// Default constructor             *
//**********************************
Date::Date()
{
	setNames();
	setDays();
}

//**********************************
// Overloaded constructor          *
// Parameters: m is the month      *
//             d is the day        *
//             y is the year       *
//**********************************
Date::Date(int m, int d, int y)
{
	setMonth(m);
	setDay(d);
	setYear(y);
	setNames();
	setDays();
}

//**********************************
// Member function setNames        *
// This function assigns the names *
// of the months to the names      *
// array.                          *
//**********************************
void Date::setNames()
{
	names[0] = "January";
	names[1] = "Febraury";
	names[2] = "March";
	names[3] = "April";
	names[4] = "May";
	names[5] = "June";
	names[6] = "July";
	names[7] = "August";
	names[8] = "September";
	names[9] = "October";
	names[10] = "November";
	names[11] = "December";
}

//**********************************
// Member function setMonth        *
//**********************************
void Date::setMonth(int m)
{
	if (m >= 1 && m <= 12)
		month = m;
	else
	{
		cout << m << " is not a valid "
			<< "value for the month.\n";
		exit(EXIT_FAILURE);
	}
}

//**********************************
// Member function setDay          *
//**********************************

void Date::setDay(int d)
{
	if (d >= 1 && d <= 31)
		day = d;
	else
	{
		cout << d << " is not a valid "
			<< "value for the day.\n";
		exit(EXIT_FAILURE);
	}
}

//**********************************
// Member function setYear         *
//**********************************

void Date::setYear(int y)
{
	if( y >= 1900 && y <= 9999)
		year = y;
	else
	{
		cout << y << " is not a valid "
			<< "value for the year.\n";
		exit(EXIT_FAILURE);
	}
}

//**********************************
// Member function showDate1       *
// Displays the date in the form   *
// MM/DD/YY                        *
// Example: 12/25/2014             *
//**********************************

void Date::showDate1()
{
	cout << month << "/"
		<< day << "/"
		<< year << endl;
}

//*************************************
// Member function showDate2          *
// Displays the date in the following *
// form: December 25, 2014            *
//*************************************

void Date::showDate2()
{
	cout << names[month - 1]
		<< " " << day << ", "
		<< year << endl;
}

//*************************************
// Member function showDate3          *
// Displays the date in the following *
// form: 25 December, 2014            *
//*************************************

void Date::showDate3()
{
	cout << day << " "
		<< names[month - 1]
		<< " " << year << endl;
}

bool Date::isLeapYear(int y)
{
	bool leap = false;
	if ((y % 400 == 0 || y % 100 != 0) && (y % 4 == 0))
		leap = true;

	return leap;
}

void Date::simplify()
{
	int dayMax = (isLeapYear(year) && month == 2) ? 29: (!isLeapYear(year) && month == 2)? 28:numDays[month -1];
	int dayMin = 1;
	int newMonth = 0, newDay = 0;

	if (day > dayMax)
	{
		newDay = day - dayMax;
		setDay(newDay);
		month++;
	}
	else if (day < dayMin)
	{
		newDay = numDays[month-1];
		setDay(newDay);
		month--;
	}

	if (month > 12)
	{
		newMonth = month - 12;
		year++;
		setMonth(newMonth);
	}
	else if (month <= 0)
	{
		newMonth = 12;
		year--;
		setMonth(newMonth);
	}
	
	if (year > 10000)
	{
		cout << year << " is not a valid "
			<< "value for the year.\n";
		exit(EXIT_FAILURE);
	}
}

Date Date::operator ++() // Prefix ++
{
	++day;
	simplify();
	return *this;
}
Date Date::operator ++(int)	// Postfix ++
{
	Date temp(month, day, year);
	day++;
	simplify();
	return temp;
}
Date Date::operator --()// Prefix --
{
	--day;
	simplify();
	return *this;
}

Date Date::operator --(int)	// Postfix --
{
	Date temp(month, day, year);
	day--;
	simplify();
	return temp;
}

// Subtraction operator. If one Date object is subtracted from another, 
// the operator should give the number of days between the two dates.
// For example, if April 10, 2014 is subtracted from April 18, 2014, the result will be 8.
int Date::operator -(const Date &right)	
{
	int days = 0;
	int ltotal = 0;
	int rtotal = 0;

	//get total days of left object
	for (int i = 1900; i < year; i++)
		ltotal += (isLeapYear(i)) ? 366 : 365;

	for (int m = 0; m < month - 1; m++)
	{
		ltotal += numDays[m];
		if (isLeapYear(year) && m == 1)
			ltotal++;
	}
	ltotal += day;

	//get total days of right object
	for (int i = 1900; i < right.year; i++)
		rtotal += (isLeapYear(i)) ? 366 : 365;

	for (int m = 0; m < right.month - 1; m++)
	{
		rtotal += right.numDays[m];
		if (isLeapYear(right.year) && m == 1)
			rtotal++;
	}
	rtotal += right.day;
	//subtract right from left;
	days = ltotal - rtotal;

	return days;
}

bool Date::operator > (const Date &right)  // Greater-than operator
{
	bool status;
	if (year > right.year ||
		(year == right.year && month > right.year) ||
		(year == right.year && month == right.month && day > right.day))
		status = true;
	else
		status = false;

	return status;
}

bool Date::operator <(const Date &right)   // Greater-than operator
{
	bool status;
	if (year < right.year ||
		(year == right.year && month < right.year) ||
		(year == right.year && month == right.month && day < right.day))
		status = true;
	else
		status = false;

	return status;
}
// Overloaded << operator - couts’s stream insertion operator.
// This operator should cause the date to be displayed in the
// form: April 18. 2014
ostream &operator <<(ostream &strm, Date &obj) 
{
	//cout << "obj.month" << obj.month << endl;
	int m = (obj.month - 1 < 0) ? 11: obj.month - 1;
	string outMonth = obj.names[m];
	strm << outMonth << " " << obj.day << ". " << obj.year;
	return strm;
}

// Overloaded >> operator -- cin’s stream extraction operator.
//This operator should prompt the user for a date to be stored
//in a Date object.
istream &operator >>(istream &strm, Date &obj)
{
	cout << "Enter the Month: ";
	strm >> obj.month;
	while (obj.month < 1 || obj.month > 12 )
	{
		cout << "Please entere valid month 1 to 12 :" << endl;
		strm >> obj.month;
	}

	cout << "Enter the Day: ";
    strm >> obj.day;
	while (obj.day < 1 || obj.day > 31)
	{
		cout << "Please entere valid day 1 to 31 :" << endl;
		strm >> obj.day;
	}

	cout << "Year: ";
	strm >> obj.year;
	while (obj.year < 1900 || obj.year > 9999)
	{
		cout << "Enter a 4 digit year such that 1900 <= year <=9999  :" << endl;
		strm >> obj.year;
	}
	
	return strm;
}

// Private member function to assign
// the numbers of days to the numDays array
void Date::setDays()
{
	numDays[0] = 31;
	int m = isLeapYear(year) ? 29: 28;
	numDays[1] = m;
	numDays[2] = 31;
	numDays[3] = 30;
	numDays[4] = 31;
	numDays[5] = 30;
	numDays[6] = 31;
	numDays[7] = 31;
	numDays[8] = 30;
	numDays[9] = 31;
	numDays[10] = 30;
	numDays[11] = 31;
}