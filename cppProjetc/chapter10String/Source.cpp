#include <iostream>
#include <cstring>

using namespace std;

//Function prototype
void outputLowercase(char*, int);
void outputUppercase(char*, int);
void selectionSort(char*, int);
void uppercaseVowelMode(char*, int);
void lowercaseVowelMode(char*, int);

int main()
{
	char userContinue = 'Y';

	while (userContinue == 'Y' || userContinue == 'y')
	{
		char aChar;
		int counter = 0;

		//1. Asks the user to enter any sequence of characters
		cout << "Enter a string :" << endl;
		cin.ignore();
		aChar = cin.get();

		char *ptr = nullptr;
		char *ptr2 = nullptr;

		while (aChar != 10)
		{
			if (counter % 2 == 0) //when counter is even, create ptr1
			{
				int s = counter + 1;
				ptr = new char[s];
				if (counter > 1) //from 3rd time, copy ptr2 to ptr
					strncpy(ptr, ptr2, s);

				ptr[counter] = aChar;
				delete[] ptr2;
				ptr2 = nullptr;
			}
			else //when counter is odd, create ptr2 and copy ptr1
			{
				int s = counter + 1;
				ptr2 = new char[s];
				strncpy(ptr2, ptr, s);
				ptr2[counter] = aChar;
				delete[] ptr;
				ptr = nullptr;
			} 
			counter++;
			aChar = cin.get();
		}

		char *userInput = nullptr;
		userInput = new char[counter + 1];
		if (counter % 2 == 0)
		{
			strncpy(userInput, ptr2, counter);
			delete[] ptr2;
			ptr2 = nullptr;
		}
		else
		{
			strncpy(userInput, ptr, counter);
			delete[] ptr;
			ptr = nullptr;
		}

		int length = strlen(userInput);

		//2. The program should display all the lower - case vowels that are present and the number of times each vowel occurs
		outputLowercase(userInput, length);
		//3. The program should display all the upper - case vowels that are present and the number of times each vowel occurs
		outputUppercase(userInput, length);
		
		//sort array to get mode
		selectionSort(userInput, length);
		//for (int m = 0; m < length - 1; m++)
			//	cout << userInput[m] << " " << endl;

		//4. The program should display the upper - case vowel which appears most frequently in the user input AND the number of times it appeared.
		uppercaseVowelMode(userInput, length);
		//5. The program should display the lower - case vowel which appears most frequently in the user input AND the number of times it appeared.
		lowercaseVowelMode(userInput, length);

		userInput = nullptr;
		delete[] userInput;

		//6. The user must be asked if he / she wants to continue entering values or quit.
		cout << "Would you like to continue? Enter Y or N" << endl;
		cin >> userContinue;
	}
	cout << "Thank you for using the program. Good bye!" << endl;

	//system("pause");
	return 1;
}

void outputLowercase(char *userInput, int length)
{
	int lvowels = 0;
	cout << "lowercase vowels are: ";
	for (int i = 0; i < length; i++)
	{
		if (userInput[i] == 'a' || (userInput[i]) == 'e' || (userInput[i]) == 'i' || (userInput[i]) == 'o' || (userInput[i]) == 'u')
		{
			lvowels++;
			cout << userInput[i];
		}
	}
	if (lvowels == 0)
		cout << " None. " << endl;
	else
		cout << " Number of Times :" << lvowels << endl;
}

void outputUppercase(char *userInput, int length)
{
	int uvowels = 0;
	cout << "uppercase vowels are: ";
	for (int i = 0; i < length; i++)
	{
		if (userInput[i] == 'A' || (userInput[i]) == 'E' || (userInput[i]) == 'I' || (userInput[i]) == 'O' || (userInput[i]) == 'U')
		{
			uvowels++;
			cout << userInput[i] << " " ;
		}
	}
	if (uvowels == 0)
		cout << " None. " << endl;
	else
		cout << " Number of Times :" << uvowels << endl;
}


void selectionSort(char *userInput, int size)
{
	int min = 0;
	char tmp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (userInput[j] < userInput[min])
				min = j;
		}
		if (min != i)
		{
			tmp = userInput[i];
			userInput[i] = userInput[min];
			userInput[min] = tmp;
		}
	}
}

void uppercaseVowelMode(char *userInput, int length)
{
	char mode = 10;
	int counter = 0, max = 0;
	for (int i = 0; i < length - 1; i++)
	{
		if (userInput[i] == 'A' || (userInput[i]) == 'E' || (userInput[i]) == 'I' || (userInput[i]) == 'O' || (userInput[i]) == 'U')
		{
			if (userInput[i] == userInput[i + 1])
			{
				counter++;
				if (counter > max)
				{
					max = counter;
					mode = userInput[i];
				}
			}
			else
				counter = 1;
		}
	}
	if (mode != 10)
		cout << "Uppercase vowels most appear is " << mode << " and number os times: " << max << endl;
	else
		cout << "There is no uppercase vowels more than once appeared." << endl;
}




void lowercaseVowelMode(char *userInput, int length)
{
	char mode = 10;
	int counter = 0, max = 0;
	for (int i = 0; i < length - 1; i++)
	{
		if (userInput[i] == 'a' || (userInput[i]) == 'e' || (userInput[i]) == 'i' || (userInput[i]) == 'o' || (userInput[i]) == 'u')
		{
			if (userInput[i] == userInput[i + 1])
			{
				counter++;
				if (counter > max)
				{
					max = counter;
					mode = userInput[i];
				}
			}
			else
				counter = 1;
		}
	}
	if (mode != 10)
		cout << "Lowercase vowels most appear is " << mode << " and number of times: " << max << endl;
	else
		cout << "There is no lowercase vowels more than once appeared." << endl;
}