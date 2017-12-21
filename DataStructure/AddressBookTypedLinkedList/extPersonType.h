#pragma once
#include "dateType.h"
#include "personType.h"
#include "addressType.h"

enum relationShipType {FAMILY, FRIEND, BUSINESS, OTHER};

class extPersonType :
	public personType
{
	friend ostream& operator<< (ostream&, const relationShipType value);
public:
	//constructors
	extPersonType();
	extPersonType(const string& new_firstName, const string& new_lastName, const string& new_telephoneNumber, const dateType& new_dob, relationShipType new_relationship, const addressType& new_address);

	//accessors
	bool checkLastName(string lastname) const;
	bool checkFirstName(string firstname) const;
	void getExtPerson(string& new_firstName, string& new_lastName, string& new_telephoneNumber, dateType& new_dob, relationShipType& new_relationship, addressType& new_address) const;
	string getFirstName() const;
	string getLastName() const;
	string getTelephoneNumber() const;
	dateType getDOB() const;
	relationShipType getRelationShip() const;
	addressType getAddress() const;

	//mutators
	void setExtPerson(const string& new_firstName, const string& new_lastName, const string& new_telephoneNumber, const dateType& new_dob, relationShipType& new_relationship, const addressType& new_address);
	void setName(const string& new_firstName, const string& new_lastName);
	void setTelephoneNumber(const string& new_telephoneNumber);
	void setDOB(const dateType& new_dob);
	void setRelationShip(relationShipType new_relationShip);
	void setAddress(const addressType& new_address);

	//custom method
	void print() const;
	bool extPersonType::operator==(const extPersonType& other) const;
	bool extPersonType::operator!=(const extPersonType& other) const;

private:
	string _telephoneNumber;
	relationShipType _relationship;
	dateType dob;
	addressType _address;
};