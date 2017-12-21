/*
 1. (Online Address Book Revisited) Programming Exercise 9 in Chapter 3 could
 handle a maximum of only 500 entries. Using linked lists, redo the program to
 handle as many entries as required. Add the following operations to your program:
 a. Add or delete a new entry to the address book.
 b. When the program terminates, write the data in the address book to a disk.
*/



#include <iostream>
#include <fstream>
#include <string>
#include "addressBookType.h"
#include "extPersonType.h"
using namespace std;

void createAddressBook(ifstream& infile,
	addressBookType& addressBook );
int main()
{
	addressBookType addressBook;
	ifstream infile;

	//open the input file
	infile.open("contact.txt");
	if (!infile)
	{
		cout << "The input file does not exist. "
			<< "The program terminates!!!" << endl;

		return 1;
	}

	//i. Load the data into the address book from a disk.
	createAddressBook(infile, addressBook);
	infile.close();

	//ii. Search for a person by last name.
	string ln;
	cout << "Enter last name of the person you want to find" << endl;
	getline(cin, ln);
	bool found = addressBook.find(ln);

	//iv. Print the names of the people whose birthdays are in a given month or between two given dates.
	dateType oldDate(3, 3, 1999);
	dateType newDate(5, 31, 2000);
	addressBook.print(oldDate, newDate);

	//iii.Print the address, phone number, and date of birth(if it exists) of a given person.
	addressBook.find("Micki", "Maresca");

	//v.Print the names of all the people having the same status, such as family, friend, or business.
	relationShipType rsp = FAMILY;
	addressBook.print(rsp);

	// vi. Print the names of all the people between two last names.
	addressBook.print("Ddddd", "A");

	//a.Add or delete a new entry to the address book.
	extPersonType extp;
	extp.setName("Treva", "Rael");
	cout << "Remove Treva Rael from the address book" << endl;
	addressBook.deleteNode(extp);

	cout << "Find Treva Rael to see if it's removed" << endl;
	addressBook.find("Rael");

	//b.When the program terminates, write the data in the address book to a disk.
	ofstream outfile;
	string file_name = "myAddressBook.txt";

	int success;
	success = addressBook.saveAddressBook(outfile, file_name);
	
	if (success == 1)
	{
		cout << "Address Book has been saved" << endl;
	}
	system("pause");
	return 0;
}

void createAddressBook(ifstream& infile,
	addressBookType& addressBook)
{
	string firstName;
	string lastName;
	string _telephoneNumber;
	string _rs;
	string month, day, year;
	string streetAddress, city, state, zipcode;

	extPersonType extPerson;

	getline(infile, firstName);

	while (infile)
	{
		getline(infile, lastName);
		getline(infile, _telephoneNumber);
		getline(infile, month);
		getline(infile, day);
		getline(infile, year);
		getline(infile, streetAddress);
		getline(infile, city);
		getline(infile, state);
		getline(infile, zipcode);
		getline(infile, _rs);

		//date object
		int m = atoi(month.c_str());
		int d = atoi(day.c_str());
		int y = atoi(year.c_str());

		dateType dob(m, d, y);

		//enum 
		relationShipType rs;
		int v = atoi(_rs.c_str());

		switch(v) 
		{
			case 0: rs = FAMILY;
				break;
			case 1: rs = FRIEND;
				break;
			case 2: rs = BUSINESS;
				break;
			case 3: rs = OTHER;
				break;
		}
		//address object
		addressType address(streetAddress, city, state, zipcode);
		
		extPerson.setExtPerson(firstName, lastName, _telephoneNumber, dob, rs, address);
		addressBook.insertFirst(extPerson);

		getline(infile, firstName);
	}//end while
}
