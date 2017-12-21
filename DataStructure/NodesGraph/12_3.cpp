/*
2. Write a program that outputs the nodes of a graph in a breadth-first traversal.
*/

#include "graphType.h"
#include <iostream>
#include <string>

int main()
{
	graphType graph(5);

	graph.createGraph();
	graph.printGraph();
	cout << endl;

	cout << "output of breadth-first traversal" << endl;
	graph.breadthFirstTraversal();
	cout << endl;

	system("pause");
	return 1;
}