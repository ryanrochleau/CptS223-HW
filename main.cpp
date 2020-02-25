#include "BST.h"

/*
Move Constructor: A constructor that takes in a Class&& and allows the data of the r-value to be moved into
the l-value
Move Assignment Operator: Allows an l-value to take control of the pointer to another dynamically allocates structure
held by the r-value.
*/
/*
Empty: O(1) just returns a true or false value depending on whether or not room exists
Add: O(log(n)) each time you go down a branch, you divide the data in half which is logarithmic
makeEmpty: O(n) as you only visit each node once
printLevelOrder: O(n^2) at each iteration of the while loop we are adding 2^level nodes to the stack which causes 2^level more
iterations of the while loop.
cloneTree: O(n) as you are copying each node once
*/

int main(void)
{

	//Destructor Test
	std::cout << "Destructor Test" << std::endl;
	BST<int> testDestructor;
	testDestructor.add(3);
	std::cout << std::endl;

	//Deep Copy Constructor Test
	BST<int> bTree4;
	bTree4.add(10);
	bTree4.add(12);
	bTree4.add(8);

	std::cout << "Deep Copy Constructor Test" << std::endl;

	BST<int> deepCopyConstructorTest(bTree4);

	deepCopyConstructorTest.printLevelOrder();
	std::cout << std::endl << std::endl;

	//Move Constructor Test
	BST<int> bTree3;
	bTree3.add(10);
	bTree3.add(12);

	bTree3.add(8);
	std::cout << "Move Constructor Test" << std::endl;

	BST<int> moveConstructorTest(std::move(bTree3));

	moveConstructorTest.printLevelOrder();
	std::cout << std::endl << std::endl;

	//Deep Copy Assignment Test
	BST<int> bTree2;
	bTree2.add(10);
	bTree2.add(12);
	bTree2.add(8);

	std::cout << "Deep Copy Assignment Test" << std::endl;

	BST<int> deepCopyAssignment;
	deepCopyAssignment = bTree2;

	deepCopyAssignment.printLevelOrder();
	std::cout << std::endl << std::endl;

	//Move Copy Assignment Test
	BST<int> bTree;
	bTree.add(10);
	bTree.add(12);
	bTree.add(8);

	std::cout << "Move Copy Assignment Test" << std::endl;

	BST<int> moveCopyAssignment;
	moveCopyAssignment = std::move(bTree);

	moveCopyAssignment.printLevelOrder();
	std::cout << std::endl << std::endl;

	//Print Level Order Helper
	BST<int> BinarySearchTree;
	BinarySearchTree.add(10);
	BinarySearchTree.add(8);
	BinarySearchTree.add(12);

	std::cout << "Print Level Order Helper Test" << std::endl;

	BinarySearchTree.printLevelOrder();
	std::cout << std::endl << std::endl;
	


	


	return 0;
}