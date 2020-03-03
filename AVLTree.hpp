#include "AVLNode.hpp"

int rank = 1;

template <typename T>
class AVLTree
{
private:
	AVLNode<T>* rootNode;
public:
	//Construct tree from file
		AVLTree(std::ifstream& input_file)
		{

			char temp[256];
			std::string country;
			std::string sCancerRate;
			double dCancerRate;
			int i = 0;

			while (!input_file.eof())
			{
				input_file.getline(temp, 256);
				country = strtok(temp, ",");
				sCancerRate = strtok(NULL, ",");
				dCancerRate = stod(sCancerRate);
				rootNode = insert(rootNode, country, dCancerRate);
				i++;
			}
		}
	//Destructor
		~AVLTree()
		{
			clear(this->rootNode);
		}
	//Insert
		AVLNode<T>* insert(AVLNode<T>* root,std::string& countryInput, double& rateInput)
		{
			CancerData newData(countryInput, rateInput);
			int currentBalance = 0;
		//Place here
			if (!root)
			{
				return newNode(newData);
			}
		//Go left
			else if(newData < root->getData())
			{
				root->setLeftPtr(insert(root->getLeftPtr(), countryInput, rateInput));
			}
		//Go right
			else if (newData > root->getData())
			{
				root->setRightPtr(insert(root->getRightPtr(), countryInput, rateInput));
			}

		//Set new nodes height
			if (root->getLeftPtr()->getHeight() > root->getRightPtr()->getHeight()) 
				root->setNodeHeight(1 + root->getLeftPtr()->getHeight());
			else
				root->setNodeHeight(1 + root->getRightPtr()->getHeight());

			currentBalance = checkBalance(root);

		//Right Right
			if (currentBalance > 1 && newData > root->getRightPtr()->getData())
			{
				return root = leftRotate(root);
			}
		//Left Left
			if (currentBalance < -1 && newData < root->getLeftPtr()->getData())
			{
				return root = rightRotate(root);
			}
		//Right Left
			if (currentBalance > 1 && newData < root->getRightPtr()->getData())
			{
				root->setRightPtr(rightRotate(root->getRightPtr()));
				return root = leftRotate(root);
			}
		//Left Right
			if (currentBalance < -1 && newData > root->getLeftPtr()->getData())
			{
				root->setLeftPtr(leftRotate(root->getLeftPtr()));
				return root = rightRotate(root);
			}
			return root;
		}
	//Create New Node
		AVLNode<T>* newNode(T data)
		{
			AVLNode<T>* newNode = new AVLNode<T>(data);

			return newNode;
		}
	//Get the current balance of a node
	//Negative indicates heavy left side and positive is heavy right
		int checkBalance(AVLNode<T>* root)
		{
			if (root == nullptr)
				return 0;
			return root->getRightPtr()->getHeight() - root->getLeftPtr()->getHeight();
		}
	//Left Rotation
		AVLNode<T>* leftRotate(AVLNode<T>* root)
		{
			AVLNode<T>* newRoot = root->getRightPtr();
			AVLNode<T>* lnewRoot = newRoot->getLeftPtr();

		//Rotate
			newRoot->setLeftPtr(root);
			root->setRightPtr(lnewRoot);

		//Update newRoot and root heights, lnewRoot is at same height
			if (root->getLeftPtr()->getHeight() > root->getRightPtr()->getHeight())
				root->setNodeHeight(1 + root->getLeftPtr()->getHeight());
			else
				root->setNodeHeight(1 + root->getRightPtr()->getHeight());

			if (newRoot->getLeftPtr()->getHeight() > newRoot->getRightPtr()->getHeight())
				newRoot->setNodeHeight(1 + newRoot->getLeftPtr()->getHeight());
			else
				newRoot->setNodeHeight(1 + newRoot->getRightPtr()->getHeight());

			return newRoot;
		}
	//Right Rotation
		AVLNode<T>* rightRotate(AVLNode<T>* root)
		{
			AVLNode<T>* newRoot = root->getLeftPtr();
			AVLNode<T>* rnewRoot = newRoot->getRightPtr();

		//Rotate
			newRoot->setRightPtr(root);
			root->setLeftPtr(rnewRoot);

		//Update newRoot and root heights, rnewRoot is at same height
			if (root->getLeftPtr()->getHeight() > root->getRightPtr()->getHeight())
				root->setNodeHeight(1 + root->getLeftPtr()->getHeight());
			else
				root->setNodeHeight(1 + root->getRightPtr()->getHeight());

			if (newRoot->getLeftPtr()->getHeight() > newRoot->getRightPtr()->getHeight())
				newRoot->setNodeHeight(1 + newRoot->getLeftPtr()->getHeight());
			else
				newRoot->setNodeHeight(1 + newRoot->getRightPtr()->getHeight());

			return newRoot;
		}
	//Check for empty tree
		bool isEmpty()
		{
			if (this->rootNode == nullptr)
				return true;
			else
				return false;
		}
	//Clear entire tree
		void clear(AVLNode<T>* root)
		{
			if(root->getLeftPtr())
				clear(root->getLeftPtr());

			if(root->getRightPtr())
				clear(root->getRightPtr());

			std::free(root);
		}
	//Find minimum value Helper
		T findMinHelper(AVLNode<T>* root)
		{
			T data;
			if (!root->getLeftPtr())
				return root->getData();
			else if (root->getLeftPtr())
			{
				data = findMinHelper(root->getLeftPtr());
				return data;
			}
		}
		T findMin()
		{
			return findMinHelper(this->rootNode);
		}
	//Find maximum value Helper
		T findMaxHelper(AVLNode<T>* root)
		{
			T data;
			if (!root->getRightPtr())
				return root->getData();
			else if (root->getRightPtr())
			{
				data = findMaxHelper(root->getRightPtr());
				return data;
			}
		}
	//Find Max
		T findMax()
		{
			return findMaxHelper(this->rootNode);
		}
	//Print tree in order helper
		void printInOrderHelper(AVLNode<T>* root)
		{
			if(root->getRightPtr())
				printInOrderHelper(root->getRightPtr());

			std::cout << rank << ". " << root->getData() << std::endl;
			rank++;

			if(root->getLeftPtr())
				printInOrderHelper(root->getLeftPtr());
		}
	//Print in order
		void printInOrder()
		{
			printInOrderHelper(this->rootNode);
			rank = 1;
		}
	//Delete data
		AVLNode<T>* removeHelper(AVLNode<T>* root, T data)
		{
			int currentBalance;
			AVLNode<T>* temp = new AVLNode<T>;
			if (!root)
				return nullptr;

			if (data < root->getData())
				root->setLeftPtr(removeHelper(root->getLeftPtr(), data));
			else if (data > root->getData())
				root->setRightPtr(removeHelper(root->getRightPtr(), data));

			else if (root->getData() == data)
			{
			//No children
				if (root->getLeftPtr() == nullptr && root->getRightPtr() == nullptr)
				{
					temp = root;
					root = nullptr;
					std::free(temp);
					return root;
				}
			//Two children
				else if (root->getLeftPtr() != nullptr && root->getRightPtr() != nullptr)
				{
					temp->setData(findMinHelper(root->getRightPtr()));

					root->setData(temp->getData());

					root->setRightPtr(removeHelper(root->getRightPtr(), root->getData()));
				}
				else
				{
				//One Left Child
					if (root->getLeftPtr() != nullptr)
					{
						temp = root->getLeftPtr();
						root = temp;
						delete temp;
					}
				//One Right Child
					else
					{
						temp = root->getRightPtr();
						root = temp;
						delete temp;
					}

				}
			}
		//Update height
			if (root->getLeftPtr()->getHeight() > root->getRightPtr()->getHeight())
				root->setNodeHeight(1 + root->getLeftPtr()->getHeight());
			else
				root->setNodeHeight(1 + root->getRightPtr()->getHeight());

			currentBalance = checkBalance(root);

			//Right Right
			if (currentBalance > 1 && data > root->getRightPtr()->getData())
			{
				return root = leftRotate(root);
			}
			//Left Left
			if (currentBalance < -1 && data< root->getLeftPtr()->getData())
			{
				return root = rightRotate(root);
			}
			//Right Left
			if (currentBalance > 1 && data < root->getRightPtr()->getData())
			{
				root->setRightPtr(rightRotate(root->getRightPtr()));
				return root = leftRotate(root);
			}
			//Left Right
			if (currentBalance < -1 && data > root->getLeftPtr()->getData())
			{
				root->setLeftPtr(leftRotate(root->getLeftPtr()));
				return root = rightRotate(root);
			}
			return root;
		}
	//Removes data
		void remove(T data)
		{
			rootNode = removeHelper(rootNode, data);
		}
};