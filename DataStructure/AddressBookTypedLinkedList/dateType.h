#pragma once
class dateType
{
public:
	//constructors
	dateType();
	dateType(int new_month, int new_day, int new_year);

	//accessors
	void getDate(int& new_month, int& new_day, int& new_year) const;
	int getMonth() const;
	int getDay() const;
	int getYear() const;
	
	//mutators
	void setDate(int new_month, int new_day, int new_year);
	void setMonth(int new_month);
	void setDay(int new_day);
	void setYear(int new_year);

	//custom methods
	bool isLeapYear(int y) const;
private:
	//data members
	int _month;
	int _day;
	int _year;
	static int dom[];
};

