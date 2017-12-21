/*
Create a class, TheJarsProblem. The class’ data is a private vector of Jars. The class has a default constructor
and a constructor whose one parameter is a vector of Jars. The class has three methods – Divide, Read, Pour, and Show.
*/
#ifndef H_TheJarsProblem
#define H_TheJarsProblem

#include "classJar.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class TheJarsProblem
{
public:
	void Divide();
	//The Divide method divides all the contents of the largest capacity jar 
	//evenly among the other jars. A Divide method can look like:
	//count = 0
	//repeat
	//add 1 to count
	//read source jar, destination jar
	//pour source jar into destination jar
	//show jars, count
	//until volumes of originally empty jars are equal
	void Read(int& source, int& destinaton);
	//The Read method returns valid source and destination jar identifiers from the user.
	void Pour(int source, int destination);
	//The Pour method pours as much as it can of the source jar
	//contents into the destination jar contents.
	//The Pour method ignores attempts to pour the contents
	//of jar into itself – no self - pours.
	void Show(int counter) const;
	//The Show method displays the jars’ volumes and the number of times 
	//the user pours the contents of one jar into another.
	TheJarsProblem();
	//default constructor
	//The default constructor creates a vector of 4 jars. 
	//The jars capacities are 24, 13, 11, and 5.
	TheJarsProblem(const vector<jarType> otherJars);
	//The one parameter constructor copies its parameter to the private vector of jars.
	//The constructor guarantees that the parameter satisfies the following conditions :
	//1.	the vector holds at least 3 jars
	//2.	all the jars’ capacities are greater than 0
	//3.	the gcd of any two pair of jar capacities is 1
	//4.	all jars are empty but one - the jar with the largest capacity
	//5.	the largest capacity jar’s volume equals its capacity
	//6.	the number of jars less 1 divides the largest capacity without remainder.
private:
	vector<jarType> jars;
	int recGcd(int a, int b);
	bool isEmpty(int container) const;
	bool isFull(int container) const;
	int findMaxPosition(vector<jarType> otherjars, int arraySize) const;
};
TheJarsProblem::TheJarsProblem() //default constructor
{
	jarType jar0, jar1, jar2, jar3;
	jar0.capacity = 24;
	jar0.volume = 24;
	jar1.capacity = 13;
	jar2.capacity = 11;
	jar3.capacity = 5;
	jar1.volume = jar2.volume = jar3.volume = 0;
	
	jars.push_back(jar0);
	jars.push_back(jar1);
	jars.push_back(jar2);
	jars.push_back(jar3);
}   
TheJarsProblem::TheJarsProblem(const vector<jarType> otherJars)
{
	//1.the vector holds at least 3 jars
	if (otherJars.size() < 3)
	{
		cout << "size has to be more than 3" << endl;
		return;
	}
	//2.all the jars’ capacities are greater than 0
	for (unsigned k = 0; k < otherJars.size(); k++)
	{
		if (otherJars[k].capacity < 1)
		{
			cout << "capacity has to be more than 0" << endl;
			return;
		}
	}
	//3.the gcd of any two pair of jar capacities is 1
    for (unsigned j = 0; j < otherJars.size(); j++)
	{
		for (unsigned k = 1; k < otherJars.size() - 1; k++)
		{
			if (j == k) continue;
			int a = otherJars[j].capacity;
			int b = otherJars[k].capacity;
			int GCD = recGcd(a, b);
			if (GCD != 1)
			{
				cout << GCD << endl;
				cout << "capacities are wrong" << endl;
				return;
			}
		}
	}
	//4.all jars are empty but one - the jar with the largest capacity
	int c = findMaxPosition(otherJars, otherJars.size());
	for (unsigned m = 0; m < otherJars.size(); m++)
		if (m != c && otherJars[m].volume > 0)
		{
			cout << "volume are wrong" << endl;
			return;
		}
	//5.the largest capacity jar’s volume equals its capacity
	if (otherJars[c].volume != otherJars[c].capacity)
	{
		cout << "The largest capacity and volume are not equals" << endl;
	}
	//6.the number of jars less 1 divides the largest capacity without remainder.
	int size = otherJars.size() - 1;
	if (otherJars[c].capacity % size != 0)
	{
		cout << "the number of jars less 1 divides the largest capacity with remainder." << endl;
	}

	jars.resize(otherJars.size());
	//copy
	for (int l = 0; l < otherJars.size(); l++)
	{
		jars[l].capacity = otherJars[l].capacity;
		jars[l].volume = otherJars[l].volume;
	}
}
void TheJarsProblem::Divide()
{
	int count = 0;
	do //repeat
	{
		count++; //add 1 to count
		int s, d;
		Read(s, d);//read source jar, destination jar
		Pour(s, d);//pour source jar into destination jar
		Show(count);//show jars, count
	} while (jars[0].volume != 8 || jars[1].volume != 8 ||
		jars[2].volume != 8); //until volumes of originally empty jars are equal
}
void TheJarsProblem::Read(int& source, int&destination)
{
	cout << "source? ";
	cin >> source;
	cout << "jars :" << source << " is the source" << endl;
	cout << "destination? ";
	cin >> destination;
	cout << "jars :" << destination << " is the destination" << endl;
}
void TheJarsProblem::Pour(int source, int destination)
{
	if (source != destination)
	{
		while (!isEmpty(source) && !isFull(destination))
		{
			jars[source].volume--;
			jars[destination].volume++;
		}
	}
	else
		cout << "No self-pours" << endl;
}
void TheJarsProblem::Show(int counter) const
{
	cout << "tries:" << counter << endl;
	for (unsigned i = 0; i < jars.size(); i++)
	{
		cout << "Jar" << i << " :" << jars[i].volume << endl;
	}	
}
int TheJarsProblem::recGcd(int a, int b)
{
	a = abs(a);
	b = abs(b);

	if (b == 0 && a != 0) return a;
	else if (b == 0 || a == 0) return 1;
	return recGcd(b, a % b);
}
bool TheJarsProblem::isEmpty(int container) const 
{
	return jars[container].volume == 0;
}
bool TheJarsProblem::isFull(int container) const
{
	return jars[container].volume == jars[container].capacity;
}
int TheJarsProblem::findMaxPosition(vector<jarType> otherjars, int arraySize) const
{
	int maxPosition = 0; 
	for (int i = 1; i < arraySize; i++)
		if (otherjars[i].volume > otherjars[maxPosition].volume) 
			maxPosition = i;   
	return maxPosition;
}

#endif



