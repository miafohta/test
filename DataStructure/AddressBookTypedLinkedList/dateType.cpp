#include "dateType.h"
#include <iostream>
#include <string>
using namespace std;

int dateType::dom[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

dateType::dateType()
{
	setDate(1, 1, 1900);
}
dateType::dateType(int new_month, int new_day, int new_year)
{
	setDate(new_month, new_day, new_year);
}
void dateType::getDate(int& new_month, int& new_day, int& new_year) const
{
	new_month = _month;
	new_day = _day;
	new_year = _year;
}
int dateType::getMonth() const
{
	return _month;
}
int dateType::getDay() const 
{
	return _day;
}
int dateType::getYear() const
{
	return _year;
}
void dateType::setDate(int new_month, int new_day, int new_year)
{
	int isLeap = isLeapYear(new_year);
	int dayMax = 0;

	if (new_month == 2)
		dayMax = (isLeap == true) ? 29 : 28;
	else
		dayMax = dom[new_month - 1];

	if ((new_month >= 1 && new_month <= 12)
		&& (new_day >= 1 && new_day <= dayMax)
		&& (new_year >= 1900 && new_year <= 2999))
	{
		setMonth(new_month);
		setDay(new_day);
		setYear(new_year);
	}
	else
	{
		cout << "The date failed valification and not set." << endl;
		_month = _day = _year = 0;
	}
}
void dateType::setMonth(int new_month)
{
	_month = new_month;
}
void dateType::setDay(int new_day)
{
	_day = new_day;
}
void dateType::setYear(int new_year)
{
	_year = new_year;
}
bool dateType::isLeapYear(int y) const
{
	bool leap = false;
	if ((y % 400 == 0 || y % 100 != 0) && (y % 4 == 0))
		leap = true;

	return leap;
}