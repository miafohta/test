#ifndef NODELIST_H
#define NODELIST_H
#include "Circle.h"
#include <iostream>

using namespace std;

class NodeList
{
private:
	Circle *head;

public:
	//constructor
	NodeList();

	NodeList(const NodeList &otherList);
	//Destructor
	~NodeList();

	void appendNode(Circle*);
	void prependNode(Circle*); //copy constructor
	void insertNodeAscending(Circle*);
	void insertNodeDescending(Circle*);
	void displayNodes() const;
	bool searchNode(int); 
	void destroyList();
	void copyList(const NodeList&);

	void operator=(const NodeList&);
};
#endif

