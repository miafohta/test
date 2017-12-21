#include "myStringClass.h"
#include <cctype>

using namespace std;

myStringClass::myStringClass()
{
	userInput = nullptr;
	userInputLength = 0;
}

myStringClass::myStringClass(const char *str)
{
	userInputLength = strlen(str);
	userInput = new char[userInputLength + 1];
	strcpy_s(userInput, userInputLength + 1, str);
}

myStringClass::myStringClass(const myStringClass &obj)
{
	if (this != &obj) {
		*this = obj;
	}
}

myStringClass::~myStringClass()
{
	delete[] userInput;
}

int myStringClass::stringLength() const
{
	return userInputLength;
}

myStringClass & myStringClass::operator=(const myStringClass &right)
{
	// TODO: insert return statement here
	//to handle empty object
	if (right.userInput == nullptr) 
	{
		delete[] userInput;
		userInput = nullptr;
		userInputLength = 0;
	}
	else if (this != &right) 
	{
		delete[] userInput;
		userInput = new char[right.stringLength() + 1];
		userInputLength = right.stringLength() + 1;
		strcpy_s(userInput, userInputLength, right.userInput);
	}

	return *this;
}

char & myStringClass::operator[](int index)
{
	// TODO: insert return statement here
	if (index >= 0 && index <= userInputLength)
		return userInput[index];
	else
	{
		cout << index << " is not a valid value" << endl;
		exit(EXIT_FAILURE);
	}
}

myStringClass& myStringClass::operator+(const myStringClass &right)
{
	// TODO: insert return statement here
	int totalLength = userInputLength + right.stringLength() + 1;
	char* ptr = new char[totalLength];
	strcpy_s(ptr, userInputLength + 1, userInput);
	strcat_s(ptr, totalLength, right.userInput);
	this->userInput = ptr;
	this->userInputLength = totalLength;

	return *this;
}

bool myStringClass::operator==(const myStringClass &right)
{
	return strcmp(userInput, right.userInput) == 0;
}

bool myStringClass::operator!=(const myStringClass &right)
{
	return !(*this == right);
}

bool myStringClass::operator<=(const myStringClass &right)
{
	return strcmp(userInput, right.userInput) <= 0;
}

bool myStringClass::operator<(const myStringClass &right)
{
	return strcmp(userInput, right.userInput) < 0;
}

bool myStringClass::operator>=(const myStringClass &right)
{
	return strcmp(userInput, right.userInput) >= 0;
}

bool myStringClass::operator>(const myStringClass &right)
{
	return strcmp(userInput, right.userInput) > 0;
}

myStringClass myStringClass::operator+=(myStringClass &right)
{
	*this = *this + right;
	return *this;
}
ostream& operator<< (ostream& os, const myStringClass *right)
{
	os << right->userInput;
	return os;
}
ostream& operator<< (ostream& os, const myStringClass &right)
{
	os << right.userInput;
	return os;
}
istream& operator>> (istream& is, myStringClass &right)
{
	char* ptr = new char[100];
	cin.getline(ptr,100); //use cin.getline to take whitespace
	right = myStringClass(ptr);
	delete[] ptr;
	return is;
	
}

void myStringClass::validateUserInput(myStringClass& myStringClassObject)
{
	int ln = myStringClassObject.stringLength();
	int counter = 0;
	while (counter < ln || ln == 0)
	{
		// Validates that the entry is a alphabetial letter
		if( (!isalpha(myStringClassObject[counter]) ||  isspace(myStringClassObject[counter])) && myStringClassObject[counter] != '\0')
		{
			cout << "You didn't enter a valid name. Please try again" << endl;
			cin >> myStringClassObject;//overloaded cin
			ln = myStringClassObject.stringLength();
			counter = 0;
		}
		else
		{
			counter++;
		}
	}
}
void myStringClass::validateUserInt(myStringClass& myStringClassObject)
{
	int ln = myStringClassObject.stringLength();
	int counter = 0;
	while (counter < ln || ln == 0)
	{
		// Validates that the entry is a alphabetial letter
		if( (!isdigit(myStringClassObject[counter]) || isspace(myStringClassObject[counter])) && myStringClassObject[counter] != '\0')
		{
			cout << "You didn't enter a valid age. Please try again" << endl;
			cin >> myStringClassObject;//overloaded cin
			ln = myStringClassObject.stringLength();
			counter = 0;
		}
		else
		{
			counter++;
		}
	}
}
