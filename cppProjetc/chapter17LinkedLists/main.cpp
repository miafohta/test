#include <iostream>
#include <iomanip>
#include "NodeList.h"

using namespace std;

int main()
{
	//declare pointers to Circle objects
	Circle* circle1 = 0;
	Circle* circle2 = 0;
	Circle* circle3 = 0;
	Circle* circle4 = 0;

	//no circle may be created with a negative value for a radius
	try
	{
		circle1 = new Circle(-10);//a zero is allowed, the circle degenerates to a point
	}
	catch (Circle::ErrorAllocatingMemory e)
	{
		cout << "You entered the following value for the radius of  a circle " << e.getValue() << endl;
		cout << "you want created; this is an illegal value " << endl;
		cout << "and the circle was not created, but the rest of the " << endl;
		cout << "program continues... " << endl << endl;
	}

	//allocate memory to three Circle objects
	circle2 = new Circle(20);
	cout << "There is " << circle2->getCircleCount() << " circle in the list" << endl;
	circle3 = new Circle(30);
	cout << "There are " << circle2->getCircleCount() << " circles in the list" << endl;
	circle4 = new Circle(40);
	cout << "There are " << circle2->getCircleCount() << " circles in the list" << endl;

	//create empty list to store Circle objects

	NodeList circleList_1;

	//invoke the appendNode method/function
	circleList_1.appendNode(circle2);
	circleList_1.appendNode(circle4);
	circleList_1.appendNode(circle1);
	circleList_1.appendNode(circle3);

	//nodes (circles) should be displayed in the order entered
	cout << "Display circleList_1\n";
	circleList_1.displayNodes();
	system("pause");

	//the destroyList method/function should call the destructor of NodeList
	//which in turn should destroy all the circles in the list and set the Head = NULL.
	circleList_1.destroyList();
	system("pause");

	//After destrying circleList_1, you should be able to create new circles using the same variable names as before
	circle1 = new Circle(10);
	circle2 = new Circle(20);
	circle3 = new Circle(30);
	circle4 = new Circle(40);

	//Creat a new list 
	NodeList circleList_2;

	//invoke the prependNode method/function
	//prependNode mean last in, first out
	circleList_2.prependNode(circle2);//this will be the last node in the list when displayNodes() is invoked
	circleList_2.prependNode(circle4);
	circleList_2.prependNode(circle3);
	circleList_2.prependNode(circle1);//this will be the first node in the list when displayNodes() is invoked

									  //Display circleList_2
	cout << "Display circleList_2\n";
	circleList_2.displayNodes();
	system("pause");

	//Invoke prependNode() to copy the circleList_2 elements to circleList_3
	//This means that circleList_3 will have the same "elements" as circleList_2, BUT in reverse order!
	NodeList circleList_3(circleList_2);

	//the destroyList method/function should call the destructor of NodeList
	//which in turn should destroy all the circles in the list and set the Head = NULL.
	circleList_2.destroyList();
	cout << "circleList_2 destroyed\n";
	system("pause");

	//Display circleList_3
	cout << "Display circleList_3\n";
	circleList_3.displayNodes();
	system("pause");

	//more circle objects created
	Circle* circle11 = new Circle(11);
	Circle* circle22 = new Circle(22);
	Circle* circle33 = new Circle(33);
	Circle* circle44 = new Circle(44);


	//this may challenge you a bit
	//regardless of the value of the radius of each circle and the "order" in which circles are added to the list'
	//each circle addess , MUST be placed in the list at the EXACT and correct position--so that
	//ALL inserted circles end up in SORTED fashion from smallest to largest
	circleList_1.insertNodeAscending(circle33);
	circleList_1.insertNodeAscending(circle22);
	circleList_1.insertNodeAscending(circle44);
	circleList_1.insertNodeAscending(circle11);


	cout << "Display circleList_1\n";
	circleList_1.displayNodes();
	system("pause");
	
	NodeList circleList_4;
	//calls overloaded operator=, 
	//invoke prependNode() to copy the list
	circleList_4 = circleList_1;
	//the above statement is equivalent to: circleList_4.operator=(circleList_1);


	cout << "Display circleList_4\n";
	circleList_4.displayNodes();
	system("pause");

	//more circle objects created
	Circle* circle50 = new Circle(50);
	Circle* circle51 = new Circle(51);
	Circle* circle52 = new Circle(52);
	Circle* circle53 = new Circle(53);

	//make a list to store them
	NodeList circleList_5;
	//this may challenge you a bit
	//regardless of the value of the radius of each circle and the "order" in which circles are added to the list'
	//each circle addess , MUST be placed in the list at the EXACT and correct position--so that
	//ALL inserted circles end up in SORTED fashion from largest to smallest
	circleList_5.insertNodeDescending(circle50);
	circleList_5.insertNodeDescending(circle52);
	circleList_5.insertNodeDescending(circle51);
	circleList_5.insertNodeDescending(circle53);

	cout << "Display circleList_5\n";
	circleList_5.displayNodes();
	system("pause");

	//searchNode takes an int which represents the value of the radius of a circle object
	//return true if the circle is in the list, false otherwise
	if (circleList_5.searchNode(50))
	{
		cout << "There is a circle with radius value equal to 50" << endl;
	}
	else
	{
		cout << "There is no circle with radius value equal to 50" << endl;
	}

	if (circleList_5.searchNode(35))
	{
		cout << "There is a circle with radius value equal to 35" << endl;
	}
	else
	{
		cout << "There is no circle with radius value equal to 35" << endl;
	}

	system("pause");

	return 0;

}
