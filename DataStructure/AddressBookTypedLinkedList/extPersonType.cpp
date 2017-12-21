#include "extPersonType.h"
#include <iostream>

ostream& operator<<(ostream& out, const relationShipType value)
{
	const char* s = 0;
#define PROCESS_VAL(p) case(p): s = #p; break;
	switch (value) {
		PROCESS_VAL(FAMILY);
		PROCESS_VAL(FRIEND);
		PROCESS_VAL(BUSINESS);
		PROCESS_VAL(OTHER);
	}
#undef PROCESS_VAL
	return out << s;
}
extPersonType::extPersonType()
	:personType()
{
	_telephoneNumber = "";
	_relationship = OTHER;
	dateType dob;
	addressType _address;
}
extPersonType::extPersonType(const string& new_firstName, const string& new_lastName, const string& new_telephoneNumber, const dateType& new_dob, relationShipType new_relationship, const addressType& new_address)
	:personType(new_firstName, new_lastName)
{
	setExtPerson(new_firstName, new_lastName, new_telephoneNumber, new_dob, new_relationship, new_address);
}
bool extPersonType::checkLastName(string lastname) const
{
	return(lastname == getLastName());
}
bool extPersonType::checkFirstName(string firstname) const
{
	return(firstname == getFirstName());
}
void extPersonType::getExtPerson(string& new_firstName, string& new_lastName, string& new_telephoneNumber, dateType& new_dob, relationShipType& new_relationship, addressType& new_address) const
{
	new_firstName = getFirstName();
	new_lastName = getLastName();
	new_telephoneNumber = _telephoneNumber;
	new_dob = dob;
	new_relationship = _relationship;
	new_address = _address;
}
string extPersonType::getFirstName() const
{
	string first = personType::getFirstName();
	return first;
}
string extPersonType::getLastName() const
{
	string last = personType::getLastName();
	return last;
}
string extPersonType::getTelephoneNumber() const
{
	return _telephoneNumber;
}
dateType extPersonType::getDOB() const
{
	return dob;
}
relationShipType extPersonType::getRelationShip() const
{
	return _relationship;
}
addressType extPersonType::getAddress() const
{
	return _address;
}
void extPersonType::setExtPerson(const string& new_firstName, const string& new_lastName, const string& new_telephoneNumber, const dateType& new_dob, relationShipType& new_relationship, const addressType& new_address) 
{
	personType::setName(new_firstName, new_lastName);
	_telephoneNumber = new_telephoneNumber;
	dob = new_dob;
	_relationship = new_relationship;
	_address = new_address;
}
void extPersonType::setName(const string& new_firstName, const string& new_lastName)
{
	personType::setName(new_firstName, new_lastName);
}
void extPersonType::setTelephoneNumber(const string& new_telephoneNumber)
{
	_telephoneNumber = new_telephoneNumber;
}
void extPersonType::setDOB(const dateType& new_dob)
{
	dob = new_dob;
}
void extPersonType::setRelationShip(relationShipType new_relationShip)
{
	_relationship = new_relationShip;
}
void extPersonType::setAddress(const addressType& new_address)
{
	_address = new_address;
}

bool extPersonType::operator==(const extPersonType& other) const
{
	string ln = getLastName();
	string other_ln = other.getTelephoneNumber();
	return ( ln == other_ln );
}

bool extPersonType::operator!=(const extPersonType& other) const
{
	string ln = getLastName();
	string other_ln = other.getLastName();
	return (ln != other_ln);
}

void extPersonType::print() const
{

	cout << "Name: ";
	personType::print();
	cout << "Phone Number: " << _telephoneNumber << endl;
	int m, d, y;
	dob.getDate(m, d, y);
	cout << "Date of Birth: " << m << "-" << d << "-" << y << endl;
	cout << "Relationship: " << _relationship << endl;
	_address.printAddress();
	cout << endl;
}