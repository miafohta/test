// CO SCI 140 
//Quiz 1
// Write a program which:
//1. Prompts the user for a positive integer >= 0
//2. Validates the user input to ensure it is a positive integer >= 0
//3. Allocate (dynamically) an array big enough for the data.
//4. Load the array with random numbers ranging in value from1 to 100
//5. Display the elements of the array (unsorted)
//6. Display the elements of the array (sorted)
//7. Display the average
//8. Display the median
//9. Display the mode, if none, display appropriate message

#include <iostream>
#include <cstdlib>

using namespace std;

//function prototype
void showSortedArray(int [], int);
void displayAvg(int[], int);
void displayMdn(int[], int);
void displayMod(int[], int);
int main()
{
	int *numArray = nullptr;
	int num;

	cout << "Enter positive number" << endl;
	cin >> num;

	while (num <= 0)
	{
		cout << "please enter positive number" << endl;
		cin >> num;
	}

	const int index = num;
	numArray = new int[num];
	for (int count = 0; count<num; count++)
		numArray[count] = (rand() % 100) + 1;

	for (int count = 0; count < num; count++)
		cout << numArray[count] << " ";
	    cout << endl;

	showSortedArray(numArray, num);
	displayAvg(numArray, num);
	displayMdn(numArray, num);
	displayMod(numArray, num);

	system("pause");
	return 0;
}

void showSortedArray(int arr[], int size)
{
	int i, j;
	for (i = 1; i<size; i++)
		for (j = 0; j<size-i; j++)
			if ((arr[j]) > (arr[j + 1]))
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}

	for (int count = 0; count < size; count++)
		cout << arr[count] << " ";
	cout << endl;
}

void displayAvg(int arr[], int size)
{
	int total = 0, avrg;
	int num = size;
	while (num > 0)
	{
		total += arr[num - 1];
		num--;
	}
	avrg = total / size;
	cout << "Array avarage is" << " ";
	cout << avrg << endl;

}
void displayMdn(int arr[], int size)
{
	double median;
	if (size % 2 == 0)
	{
		median = (arr[size / 2 - 1] + arr[size / 2]) / 2;
	}
	else
	{
		median = arr[size / 2];
	}
	cout << "Array median is" << " ";
	cout << median << endl;
}
void displayMod(int arr[], int size)
{

}
