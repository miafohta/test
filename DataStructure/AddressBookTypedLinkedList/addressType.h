#pragma once
#include <string>
using namespace std;

class addressType
{
public:
	//constructors
	addressType();
	addressType(const string& new_streetAddress, const string& new_city, const string& new_state, const string& new_zipCode);

	//accessors
	void getAddress(string& new_streetAddress, string& new_city, string& new_state, string& new_zipCode) const;
	string getStreetAddress() const;
	string getCity() const;
	string getState() const;
	string getZipCode() const;
	void addressType::printAddress() const;

	//mutators
	void setAddress(const string& new_streetAddress, const string& new_city, const string& new_state, const string& new_zipCode);
	void setStreetAddress(const string& new_streetAddress);
	void setCity(const string& new_city);
	void setState(const string& new_state);
	void setZipCode(const string& new_zipCode);

private:
	string _streetAddress;
	string _city;
	string _state;
	string _zipCode;
};

