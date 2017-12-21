#include <iostream>
#include <string>
#include "Game.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include <iostream>

using namespace std;

//function prototype
void validateUserMenu(string&);
bool generateProblem(string&);

int main()
{
	Game g;

	g.splashScreen();
	g.requestName();
	g.menu();

	string cho;
	getline(cin, cho);
	validateUserMenu(cho);

	while (cho != "n" && cho != "N")
	{
		if (cho != "5")
		{
			bool correct = false;
			correct = generateProblem(cho);
			g.updateStats(correct);
		}
		else
			g.displayStats();

		g.menu();
		getline(cin, cho);
		validateUserMenu(cho);
	}
	g.saveStats();
	system("pause");
	return 1;
}
void validateUserMenu(string &cho)
{	
	while (cho != "1" && cho != "2" && cho != "3" && cho != "4" && cho != "5" && cho != "n" && cho != "N")
	{
		cout << "Please enter valid menu." << endl;
		getline(cin, cho);
	}
	
}

bool generateProblem(string &c)
{
	string userinput;
	string a;
	bool correct = false;
	char *cstr = new char[c.length() + 1];
	strcpy_s(cstr, c.length()+1, c.c_str());
	
	switch(*cstr){
	//switch(c){
		case '1': 
		{
			Addition np;
			cout << np << endl;
			getline(cin, userinput);
			np.validate(userinput);
			a = (np.checkAnswer()) ? "right" : "wrong";
			correct = np.checkAnswer();
		}
		break;
		case '2':
		{
			Subtraction np;
			cout << np << endl;
			getline(cin, userinput);
			np.validate(userinput);
			a = (np.checkAnswer()) ? "right" : "wrong";
			correct = np.checkAnswer();
		}
		break;
		case '3': 
		{
			Multiplication np;
			cout << np << endl;
			getline(cin, userinput);
			np.validate(userinput);
			a = (np.checkAnswer()) ? "right" : "wrong";
			correct = np.checkAnswer();
		}
		break;
		case '4': 
		{
			Division np;
			cout << np << endl;
			getline(cin, userinput);
			np.validate(userinput);
			a = (np.checkAnswer()) ? "right" : "wrong";
			correct = np.checkAnswer();
		}
		break;
	}
	cout << a << endl;
	delete[] cstr;
	return correct;
}
