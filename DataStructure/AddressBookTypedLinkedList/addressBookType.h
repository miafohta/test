#pragma once
//#include "arrayListType.h"
#include "unorderedLinkedList.h"
#include "extPersonType.h"
using namespace std;

class addressBookType : public unorderedLinkedList<extPersonType>
{
public:
	//constructors
	//addressBookType();
	//addressBookType(const string& new_fileName);

	bool find(const string& lastName) const;
	void find(const string& firstName, const string& lastName) const;
	void print(const extPersonType& person) const;
	void print(relationShipType relationship) const;
	void print(const dateType& oldDate, const dateType& newDate) const;
	void print(const string&  highLastName, const string& lowLastName) const;
	void print() const;
	int saveAddressBook(ofstream& outfile, string file_name) const;
private:
	string filename;
};