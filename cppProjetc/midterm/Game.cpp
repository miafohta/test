#include <string> 
#include <iostream> 
#include <fstream>
#include <iomanip>
#include <cctype>
#include "Game.h"
using namespace std;

//default constructor
//Postcondition: 
/*
userName = "";//variable to store the user name
totalWages = 0;//variable to store the total earning
totalCorrect = 0;//variable to store the total of correct responses
totalWrong = 0;//variable to store the total of incorrect responses
*/
Game::Game()
{
	userName = "";
	totalWages = 0;
	totalCorrect = 0;
	totalWrong = 0;
}

//Function to display credits and developer information.
void  Game::splashScreen()
{
	cout << "//************************//" << endl;
	cout << "//***** The Math Game ****//" << endl;
	cout << "//*** By Mia Ohta **//" << endl;
	cout << "//************************//" << endl;
	cout << endl;
	system("pause");
}
 
//Function to display the menu options and validate them.
//Postcondition: continu is equal to: 1 or 2 or 3 or or 5 or n or N; 
void  Game::menu()
{
	cout << "//***************************//" << endl;
	cout << "//***** Choose a problem ****//" << endl;
	cout << "//***** 1. Addition      ****//" << endl;
	cout << "//***** 2. Subtraction   ****//" << endl;
	cout << "//***** 3. Multiplication****//" << endl;
	cout << "//***** 4. Division      ****//" << endl;
	cout << "//***** 5. Stats         ****//" << endl;
	cout << "//***** N/n to QUIT      ****//" << endl;
	cout << "//***************************//" << endl;

}

//Function to update game statistics
//Postcondition: updates totalWages and totalCorrect and totalWrong; 
void  Game::updateStats(bool correct)
{
	if (correct == true)
	{
		totalCorrect += 1;
		totalWages += REWARD;
	}
	else
	{
		totalWrong += 1;
		totalWages -= PENALTY;
	}
}

//Function to display player statistics
void  Game::displayStats()
{
	cout << "//*****************************//" << endl;
	cout << "//****** " << userName << "'s stats"  << endl;
	cout << fixed << setprecision(2);
	cout << "//**** Total Earnings $" << totalWages << endl;
	cout << "//**** Total Correct " << totalCorrect  << endl;
	cout << "//**** Total Incorrect " << totalWrong <<  endl;
	cout << "//*****************************//" << endl;

}

//Function to get userName
//This function also invokes the validate method which ensures that the userName is valid; that is, it is not numbers, blanks, non-alpha chars or a combination thereof
//Postcondition: creates a new text file if user is a first-time player or reads statistics from text file if user is a returniong player
//if the player is a "returning player", the statistics are read into: userName, totalWages, totalCorrect, and totalWrong
void  Game::requestName()
{
	string str1;

	cout << "Enter your name and press <Enter>" << endl;
	cout << "No numbers or spaces are allowed" << endl;
	getline(cin, str1);
	validate(str1);
	userName = str1;

	ifstream inData;
	string filename = userName + ".txt";

	inData.open(filename);

	if (inData)
	{
		// Read the numbers from the file.
		inData >> totalCorrect;
		inData >> totalWrong;
		inData >> totalWages;

		inData.close();

		displayStats();
	}
	else
		cout << "Welcome " << userName << "!" << endl;

}

//Function to save statistics into text file
//Postcondition:statistics saved are: userName, totalWages, totalCorrect, and totalWrong
void  Game::saveStats()
{
	ofstream outData;
	string filename = userName + ".txt";

	outData.open(filename);

	cout << "Now saving your stats.\n";

	// Write data to file.
	outData << totalCorrect << endl;
	outData << totalWrong << endl;
	outData << totalWages << endl;

	// Close the file
	outData.close();
	cout << "Done.\n";
}

//Function to validate userName
//userName is not allowed to be more than one word or numbers, blanks, non-alpha chars or a combination thereof
//Postcondition: userName is a single word made of alpha chars only
void Game::validate(string &str1)
{
	int ln = str1.length();
	bool ok = false;
	int counter = 0;
	while (counter < ln || ln == 0)
	{
		//2. Validates that the entry is a alphabetial letter
		if (!isalpha(str1[counter]) || isspace(str1[counter]))
		{
			cout << "You didn't enter a valid name. Please try again" << endl;
			getline(cin, str1);
			ln = str1.length();
			counter = 0;
		}
		else
		{
			counter++;
		}

	}
}

