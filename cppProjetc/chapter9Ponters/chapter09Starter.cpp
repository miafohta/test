
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

#include <iostream>#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;
//   Function prototypes
double median(int *,   int);
int mode(int *,   int);
int *makeArray(int);
void loadNumberData(int *,   int);
void selectionSort(int [], int);
double average(int *,   int);
void displayArray(int *numberData, int qtyOfRandomNumbers);
void validateInt(string userIn, int& userInput);
int main()
{
	int *ap = nullptr;
	int num, md;
	double avg, mdn;

	cout << "Enter positive number" << endl;
	cin >> num;
	
	while (num <= 0)
	{
		cout << "please enter positive number" << endl;
		cin >> num;
	}

	ap = makeArray(num);
	loadNumberData(ap, num);
	displayArray(ap, num);
	selectionSort(*ap, num);
	displayArray(ap, num);
	avg = average(ap, num);

	cout << "Average is " << avg << endl;

	mdn = median(ap, num);

	cout << "Median is " << mdn << endl;

	md = mode(ap, num);

	cout << "Mode is " << md << endl;


	system("pause");
	return 0;

}


//function definitions
//*************************************************
//function displayArray
//this function displays the elements of the array
//use pointer arithmetic to step through the array
void displayArray(int * numberData, int qtyOfRandomNumbers)
{
	for (int count = 0; count < qtyOfRandomNumbers; count++)
		cout << numberData[count] << " ";
}

//*************************************************
//function validateInt ensures that the user input
//is an   integer >=   0

void validateInt(string userIn, int& userInput)
{

}

//*************************************************
//   Function makeArray                             *
//   This function dynamically allocates an   array of*
//   ints and returns a  pointer to   it. The parameter*
//   size is the number of   elements to   allocate.    *
//*************************************************
int *makeArray(int size)
{
	int *numArray = nullptr;
	numArray = new int[size];

	return numArray;
}

//*************************************************
//   Function loadNumberData*
//   This function loads the array with random numbers*
//ranging in   value from 1  to 100
//use pointer arithmetic to   step through the array   *
//*************************************************
void loadNumberData(int *ap, int size)
{
	for (int count = 0; count<size; count++)
		ap[count] = (rand() % 100) + 1;
}

//*************************************************
//   Function selectionSort                         *
//   This function performs the selection sort      *
//   algorithm on   array, sorting it   into ascending  *
//   order. The parameter size holds the number of  *
//   elements in   the array.                         *
//*************************************************
void selectionSort(int ap[] , int size)
{
	int min, tmp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (ap[j] < ap[min])
				min = j;
		}

		if (min != i)
		{
			tmp = ap[i];
			ap[i] = ap[min];
			ap[min] = tmp;
		}
	}

}

//**************************************************
//   Function median                                 *
//   This function displays the median of   the values *
//   in the array pointed to   by   the parameter arr.   *
//   The num parameter holds the number of elements  *
//   in the array.                                   *
//**************************************************
double median(int *ap, int size)
{
	double median;
	if (size % 2 == 0)
	{
		median = (ap[size / 2 - 1] + ap[size / 2]) / 2;
	}
	else
	{
		median = ap[size / 2];
	}
	return median;
}

//*********************************************************
//   Function mode                                          *
//   This function returns the mode of   the array pointed to *
//   by arr. The mode is   the value that appears most often. *
//   The parameter num holds the number of elements in the  *
//   array. If   no   element appears more than once, the       *
//   function returns -1.                                   *
//*********************************************************
int mode(int *ap, int size)
{
	int mode = 0;
	
	return mode;
}

//**************************************************
//   Function average                                *
//   This function calculates and returns the average*
//   of the values in the array arr. num is   the      *
//   number of   elements in   the array.                *
//**************************************************
double average(int *ap, int size)
{
	int total = 0, avrg;
	int num = size;
	while (num > 0)
	{
		total += ap[num - 1];
		num--;
	}
	avrg = total / size;
	return avrg;
}
