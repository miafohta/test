/*
6. a. Write the definition of the function to implement the nonrecursive
postorder traversal algorithm.
b. Write a program to test the nonrecursive inorder, preorder, and postorder
traversal algorithms. (Note: First create a binary search tree.)
*/

#include "binarySearchTree.h"
#include <iostream>
#include <string>

int main()
{
	bSearchTreeType<int> bt;

	bt.insert(12);
	bt.insert(34);
	bt.insert(5);
	bt.insert(66);
	bt.insert(14);
	bt.insert(52);
	bt.insert(27);
	
	bt.nonRecursivePostTraversal();
	cout << endl;
	bt.postorderTraversal();
	system("pause");
	return 1;
}