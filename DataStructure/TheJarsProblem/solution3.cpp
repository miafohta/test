#include "TheJarsProblem.h"
#include <iostream>
#include <string>
#include <vector>

int main()
{
	TheJarsProblem Jars;
	Jars.Divide();
	Jars.Show(1);

	jarType jar0, jar1, jar2, jar3;
	jar0.capacity = 21;
	jar0.volume = 21;
	jar1.capacity = 4;
	jar2.capacity = 11;
	jar3.capacity = 5;
	jar1.volume = jar2.volume = jar3.volume = 0;

	vector<jarType> newJars;
	newJars.push_back(jar0);
	newJars.push_back(jar1);
	newJars.push_back(jar2);
	newJars.push_back(jar3);
	TheJarsProblem OtherJars(newJars);
	OtherJars.Show(1);

	system("pause");
	return 0;
}

/*

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int TUB = 0;
const int JAR1 = 1;
const int JAR2 = 2;

vector<string> names(3);
vector<int> capacity(3);
vector<int> volume(3);

void display(int count);
void read(int& source, int& destination);
void pour(int source, int destination);
bool isEmpty(int container);
bool isFull(int container);

int main()
{
	capacity[TUB] = 8;
	capacity[JAR1] = 5;
	capacity[JAR2] = 3;

	volume[0] = 8;
	volume[1] = 0;
	volume[2] = 0;

	names[TUB] = "Tub";
	names[JAR1] = "Jar 1";
	names[JAR2] = "Jar 2";

	int count = 0;
	display(count);
	do
	{
		on);
		count++;
		display(count);
	} while (volume[JAR1] != 4);
	system("pause");
	return 0;
}
void pour(int source, int destination)
{
	while (!isEmpty(source) && !isFull(destination))
	{
		volume[source]--;
		volume[destination]++;
	}
}
bool isEmpty(int container)
{
	return volume[container] == 0;
}
bool isFull(int container)
{
	return volume[container] == capacity[container];
}
void read(int& source, int& destination)
{
	cout << "source? ";
	cin >> source;
	cout << names[source] << " is the source" << endl;
	cout << "destination? ";
	cin >> destination;
	cout << names[destination] << " is the destination" << endl;
}
void display(int count)
{
	cout << count << ": ";
	for (int index = TUB; index <= JAR2; index++)
		cout << volume[index] << ' ';
	cout << endl;
}
*/