#include <iostream>
#include <fstream>
#include <string>

template <class T>
class List
{
private:
	T function, description; //Hold function and description
	List<T> * headPtr;
	List<T> * nextPtr;
	int count = 0; //Node count of entire list
	bool chosenflag = false; //Flag for whether or not the node has been used in the game
public:
	//Constructor
	List()
	{
		headPtr = nullptr;
	}

	//Destructor
	~List()
	{
		deleteList();
	}

	//Inserts in the front of the list
	void insertFront(T func, T desc)
	{
		List<T> * newNode = new List<T>;
		newNode->nextPtr = nullptr;
		newNode->description = desc;
		newNode->function = func;
		if (!headPtr) //No head pointer
			headPtr = newNode;
		else //Head pointer exists
		{
			newNode->nextPtr = headPtr;
			headPtr = newNode;
		}
		count++;
	}

	//Read a file and inserts each function and command into the front of the list
	void populateList(std::fstream &commands)
	{
		char temp[200];
		std::string function, description;

		while (!commands.eof()) //Until end of file
		{
			commands.getline(temp, 200); //Get line
			if (temp[0] != 0) //Check for empty line
			{
				function = strtok(temp, ","); //Tokenate the strings
				description = strtok(NULL, ",");
				insertFront(function, description);
			}
		}
	}

	//Deletes the entire list
	void deleteList()
	{
		List<T> * tempNode = headPtr, *temp2Node = new List<T>;

		while (tempNode) //Iterate through list and delete nodes
		{
			temp2Node = tempNode->nextPtr;
			delete tempNode;
			tempNode = temp2Node;
		}
	}

	//Store the entire list back into the file
	void storeList(std::fstream &commands)
	{
		List<T> * tempNode = headPtr;
		std::string tempString;
		commands.close();
		commands.open("commands.csv", std::fstream::out | std::fstream::trunc); //Open in truncated to delete current contents of file
		while (tempNode) //Iterate through list
		{
			tempString = tempNode->function + "," + tempNode->description+'\n'; //Combine strings
			commands << tempString;
			tempNode = tempNode->nextPtr;
		}
	}

	//Create a new function
	void newFunction()
	{
		std::string function, description;

		std::cout << "Enter New Function: "; //Get new function
		std::cin >> function;

		std::cout << std::endl << "Enter New Description: "; //Get new description
		std::getline(std::cin, description);
		std::getline(std::cin, description);

		insertFront(function, description); //Insert into list

		system("cls");
	}

	//Remove a function given a function
	bool removeFunction()
	{
		List<T> * tempNode = headPtr, *temp2Node = new List<T>;
		std::string function;
		int flag = 0;

		if (!headPtr) //Check if list even exists
		{
			std::cout << "No List Exists" << std::endl;
			return false;
		}

		std::cout << "Enter A Function To Remove: "; //Get function to remove
		std::cin >> function;

			while (tempNode) //Iterate through list to check for match
			{
				if (tempNode->function == function) //If match found then break
				{
					flag = 1;
					break;
				}
				else
				{
					temp2Node = tempNode;
					tempNode = tempNode->nextPtr;
				}
			}
			if (flag) //If a match was found
			{
				if (tempNode == headPtr) //Deleting head node
				{
					headPtr = tempNode->nextPtr;
					delete tempNode;
				}
				else //Deleting any other node
				{
					temp2Node->nextPtr = tempNode->nextPtr;
					delete tempNode;
				}
			}
			else //No function found
			{
				std::cout << "Function Not Found" << std::endl;
				system("pause");
				system("cls");
				return false;
			}

		count--; 
		system("cls");
		return true;
	}

	//Getter for node count
	int getCount()
	{
		return count;
	}


	//Goes to position n and returns function and description via reference. Take a bool to decide whether or not to flag as chosen
	bool getnList(int n, T &function, T &description, bool toflag)
	{
		List<T> * tempNode = headPtr;
		int i = 0;
		for (i = 1; i < n; i++)
		{
			tempNode = tempNode->nextPtr;
		}
		if (tempNode->chosenflag == true)
		{
			return false;
		}
		else 
		{
			function = tempNode->function;
			description = tempNode->description;
			if (toflag == true)
			{
				chosenflag = true;
			}
			return true;
		}
	}

	//Resets all of the chosen flags so that the game has access to all functions again
	void resetFlag()
	{
		List<T> * tempNode = headPtr;
		while (tempNode)
		{
			chosenflag = false;
			tempNode = tempNode->nextPtr;
		}
	}
};