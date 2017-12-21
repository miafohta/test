/*
Moonseong Park  09/23/2017
Chapter 11 Programing Quiz 3

Reads students’ names followed by their test scores. The program should output each student’s name followed by
the test scores and the relevant grade. It should also find and print the highest test score and the name of the students having the highest test score.
Student data should be stored in a struct variable of type studentType, which has four components: 
StudentFName, studentLName of type string, testScore of type int (testScore is between 0 and 100), and grade of type char. 
Suppose that the class has 20 students. Use an array of 20 elements of type studentType.
Your program must contain at least the following functions:

A function to read the students’ data into the array
A function to assign the relevant grade to each student
A function to find the highest test score
A function to print the names of the students having the highest test score.

Your program must output each student’s name in this form: last name followed by a comma, followed by a space, 
followed by the first name, the name must be left justified. Moreover, other than declaring variables and opening the input and output files,
the function main() should only be a collection of function calls.
Comment your code and use meaningful or mnemonic variable names.
You are REQUIRED to use the data in the Data.txt filePreview the documentView in a new window.
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//structure declearation
struct StudentType
{
	string StudentFName;
	string StudentLName;
	int testScore;
	char grade;
};

//function prototype
void readFile(StudentType [], ifstream&);
void assignGrade(StudentType [], int);
int findTheHighest(StudentType[], int);
void printTheName(StudentType[], int, int);
void printOutfile();

int main()
{
	int count = 0;
	int size = 20;
	ifstream infile;
	
	infile.open("Data.txt");
	if (!infile)
	{
		cerr << "Unable to open file Data.txt";
		system("pause");
		return 0;
	}

	//define StudentType pointer and dynamically create arrays.
	//StudentType *sList = nullptr;
	//sList = new StudentType[size];
	StudentType sList[20];

	//read file and load students data into arrays of StudentType struct.
	readFile(sList, infile);
	infile.close();

	//assign grade to each students.
	assignGrade(sList, size);

	//get the hishest test score.
	int highest = findTheHighest(sList, size);

	//print all the students name, test score & grades.
	printTheName(sList, size, highest);

	printOutfile();

	system("pause");
	return 0;
}

void readFile(StudentType s[], ifstream& infile)
{
	int index = 0;
	while (infile)
	{
		infile >> s[index].StudentFName;
		infile >> s[index].StudentLName;
		infile >> s[index].testScore;
		index++;
	}
}
void assignGrade(StudentType s[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (s[i].testScore >= 90)
			s[i].grade = 'A';
		else if (s[i].testScore >= 80)
			s[i].grade = 'B';
		else if (s[i].testScore >= 70)
			s[i].grade = 'C';
		else
			s[i].testScore = 'F';
	}
}
int findTheHighest(StudentType s[], int size)
{
	int hts = 0;
	//fint the highest score
	for (int i = 0; i < size-1; i++)
	{
		if (s[i].testScore >= s[i + 1].testScore)
			hts = s[i].testScore;
	}
	return hts;
}
void printTheName(StudentType s[], int size, int hts)
{
	ofstream outfile;
	outfile.open("Out.txt");

	//last name followed by a comma, followed by a space,
	//followed by the first name, the name must be left justified
	for (int i = 0; i < size; i++)
	{
		outfile << s[i].StudentLName << ", " << s[i].StudentFName << " " << s[i].testScore << " " << s[i].grade << endl;
	}

	outfile << "The highest test score is " << hts << endl;
	outfile << "Students who have the highest score are " << endl;
	//find and print students' name who has the highest score.
	for (int i = 0; i < size; i++)
		if (s[i].testScore == hts)
			outfile << s[i].StudentLName << ", " << s[i].StudentFName << endl;

	outfile.close();
}
void printOutfile()
{
	string line;
	ifstream resultfile;
	resultfile.open("Out.txt");

	while (getline(resultfile, line))
	{
		cout << line << endl;
	}
		
}