#include "addressBookType.h"
#include <iostream>
#include <string>
#include <fstream>

/*

addressBookType::addressBookType()
	:unorderdLinkedList<extPersonType>(500)
{

}
addressBookType::addressBookType(const string& new_fileName)
	:linkedListType<extPersonType>(500)
{
	filename = new_fileName;
}
*/
//bool operator>= (const string& lhs, const string& rhs)
//{

//}

bool addressBookType::find(const string& lastName) const
{
	bool found = false;
	nodeType<extPersonType> *current;
	current = first; //set current to point to the first node
					 //in the list

	while (current != NULL && !found)     //search the list
	{
		if (current->info.checkLastName(lastName)) //the item is found
		{
			current->info.print();
			found = true;
		}
		else
			current = current->link; //advance current to 
							 //the next node    
	}
	if (!found) cout << "record not found" << endl;
	return found;
}
void addressBookType::find(const string& firstName, const string& lastName) const
{
	cout << "Find person who's name is " << firstName << " " << lastName<< endl;

	bool found = false;
	nodeType<extPersonType> *current;
	current = first;

	while (current != NULL && !found)     //search the list
	{
		if (current->info.checkLastName(lastName) && current->info.checkFirstName(firstName)) //the item is found
		{
			cout << "Match found " << endl;
			current->info.print();
			found = true;
		}
		else
			current = current->link;
	}
}
void addressBookType::print(const extPersonType& person) const
{
	person.print();
	cout << endl;
}
void addressBookType::print(relationShipType relationship) const
{
	string _rs;
	switch (relationship)
	{
	case 0: _rs = "FAMILY";
		break;
	case 1: _rs = "FRIEND";
		break;
	case 2: _rs = "BUSINESS";
		break;
	case 3: _rs = "OTHER";
		break;
	default:
		_rs = "you entered wrong number";
	}

	cout << "List of " << _rs << endl;
	bool found = false;
	nodeType<extPersonType> *current;
	current = first;
	while(current != NULL)
	{
		relationShipType rs = current->info.getRelationShip();
		if (rs == relationship)
		{
			current->info.print();
			current = current->link;
			found = true;
		}
		else
			current = current->link;
	}
}
void addressBookType::print(const dateType& oldDate, const dateType& newDate) const
{
	int o_day, o_month, o_year;
	oldDate.getDate(o_month, o_day, o_year);
	string o_mdy = std::to_string(o_year) + std::to_string(o_month) + std::to_string(o_day);

	int n_day, n_month, n_year;
	newDate.getDate(n_month, n_day, n_year);
	string n_mdy = std::to_string(n_year) + std::to_string(n_month) + std::to_string(n_day);
	
	cout << "List of Person who's birthday is between ";
	cout << o_month << "-" << o_day << "-" << o_year;
	cout << " and " << n_month << "-" << n_day << "-" << n_year << endl;
	cout << endl;

	bool found = false;
	nodeType<extPersonType> *current;
	current = first;

	while (current != NULL)     //search the list
	{
		dateType bd = current->info.getDOB();
		int m, d, y;
		bd.getDate(m, d, y);
		string mdy = std::to_string(y) + std::to_string(m) + std::to_string(d);
		if (mdy > o_mdy && mdy < n_mdy) //the item is found
		{
			current->info.print();
			current = current->link;
			found = true;
		}
		else
			current = current->link;
	}

	if (!found) cout << "Record not found" << endl;
}
void addressBookType::print(const string&  highLastName, const string& lowLastName) const
{
	cout << "List of person last name between " << lowLastName << " and ";
	cout << highLastName << endl;

	bool found = false;
	nodeType<extPersonType> *current;
	current = first;
	while( current != NULL)
	{
		string ln = current->info.getLastName();
		if (ln > lowLastName && ln < highLastName)
		{
			string fn = current->info.getFirstName();
			cout << ln << " " << fn << endl;
			found = true;
			current = current->link;
		}
		else
			current = current->link;
	}
}
void addressBookType::print() const
{
	nodeType<extPersonType> *current;
	current = first;

	while (current != NULL)
	{
		current->info.print();
		current = current->link;
	}
}
int addressBookType::saveAddressBook(ofstream& outfile, string file_name) const
{
	outfile.open(file_name);
	nodeType<extPersonType> *current;
	current = first;

	while (current != NULL)
	{
		string ln = current->info.getLastName();
		string fn = current->info.getFirstName();
		dateType dob = current->info.getDOB();
		int m, d, y;
		dob.getDate(m, d, y);
		relationShipType rs = current->info.getRelationShip();
		string _rs = (rs == 0) ? "FAMILY" : ((rs == 1) ? "FRIEND" : ((rs == 2) ? "BUSINESS" : "OTHER"));
		string phone = current->info.getTelephoneNumber();
		string street, city, state, zip;
		addressType ad = current->info.getAddress();
	    ad.getAddress(street, city, state, zip);

		outfile << "Name: " <<  ln << " " << fn << endl;
		outfile << "Phone#: " << phone << endl;
		outfile << "Address: " << street << endl;
		outfile << city << " " << state << " " << zip << endl;
		outfile << "Date of Birth: " << m << "-" << d << "-" << y << endl;
		outfile << "Relationship: " << _rs << endl;
		outfile << endl;

		current = current->link;
	}
	outfile.close();

	return 1;
}