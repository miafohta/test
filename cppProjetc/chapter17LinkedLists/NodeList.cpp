#include "NodeList.h"

NodeList::NodeList()
{
	head = nullptr;
}
//Destructor
NodeList::~NodeList()
{
	Circle* preNode = head;
	Circle* endOfList = nullptr;
	Circle* currNode = head;

	if (!head)
		cout << "list is empty\n";
	else
	{
		//traverse the list to the end
		while (currNode != endOfList)
		{
			preNode = currNode;
			currNode = currNode->nextNodeLink;
			head = currNode;
			delete preNode;
		}
	}
}
void NodeList::appendNode(Circle *someCircle)
{
	Circle *preNode = head;
	Circle *currNode = head;

	if (!head)
		head = someCircle;
	else
	{
		while (currNode != nullptr)
		{
			preNode = currNode;
			currNode = currNode->nextNodeLink;
		}
		preNode->nextNodeLink = someCircle;
	}

}
void NodeList::prependNode(Circle *someCircle)
{
	Circle *preNode = someCircle;

	if (!head)
		head = someCircle;
	else
	{
		preNode->nextNodeLink = head;
		head = preNode;
	}
}
void NodeList::insertNodeAscending(Circle * someCircle)
{
	Circle *currNode = head;
	Circle *nextNode = nullptr;

	if (!head)
	{
		head = someCircle;
		head->nextNodeLink = nullptr;
	}
	else
	{
		appendNode(someCircle);
		for (currNode = head; currNode->nextNodeLink != nullptr; currNode = currNode->nextNodeLink)
			for (nextNode = currNode->nextNodeLink; nextNode != nullptr; nextNode = nextNode->nextNodeLink)
			{
				if (currNode->getCircleRadius() > nextNode->getCircleRadius())
				{
					int temp = currNode->getCircleRadius();
					currNode->setCircleRadius(nextNode->getCircleRadius());
					nextNode->setCircleRadius(temp);
				}
			}
	}
}

void NodeList::insertNodeDescending(Circle * someCircle)
{
	Circle *currNode = head;
	Circle *nextNode = nullptr;

	if (!head)
	{
		head = someCircle;
		head->nextNodeLink = nullptr;
	}
	else
	{
		appendNode(someCircle);
		for (currNode = head; currNode->nextNodeLink != nullptr; currNode = currNode->nextNodeLink)
			for (nextNode = currNode->nextNodeLink; nextNode != nullptr; nextNode = nextNode->nextNodeLink)
			{
				if (currNode->getCircleRadius() < nextNode->getCircleRadius())
				{
					int temp = currNode->getCircleRadius();
					currNode->setCircleRadius(nextNode->getCircleRadius());
					nextNode->setCircleRadius(temp);
				}
			}
	}

}

void NodeList::displayNodes() const
{
	Circle *currNode = head;

	if (!head)
		cout << "list is empty" << endl;
	else {
		while (currNode != nullptr)
		{
			cout << currNode->getCircleRadius() << endl;
			currNode = currNode->nextNodeLink;
		}
	}
}
bool NodeList::searchNode(int searchValue)
{
	bool found = false;
	Circle *currNode = head;

	while (currNode)
	{
		if (currNode->getCircleRadius() == searchValue)
			found = true;
		currNode = currNode->nextNodeLink;
	}

	return found;
}

void NodeList::destroyList()
{
	NodeList::~NodeList();
}

//copy constructor
NodeList::NodeList(const NodeList &otherList)
{
	copyList(otherList);
}

void NodeList::copyList(const NodeList &otherList)
{
	this->head = nullptr;
	Circle *currNode = otherList.head;
	while (currNode != nullptr)
	{
		int copiedRadius = currNode->getCircleRadius();
		Circle *newNode = new Circle;
		newNode->setCircleRadius(copiedRadius);
		prependNode(newNode);
		currNode = currNode->nextNodeLink;
	}
}

void NodeList::operator=(const NodeList &otherList)
{
	copyList(otherList);
}
