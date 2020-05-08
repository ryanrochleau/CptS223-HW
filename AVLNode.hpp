//Headers
#include <iostream>
#include <fstream>
#include <string>
#include "CancerData.hpp"

template <typename T>
class AVLNode
{
private:
	T data;
	AVLNode* leftPtr;
	AVLNode* rightPtr;
	int nodeHeight;
public:
	//Constructors
		AVLNode()
		{
			//this->data = nullptr;
			this->leftPtr = nullptr;
			this->rightPtr = nullptr;
			this->nodeHeight = 0;
		}
		AVLNode(T newData)
		{
			this->data = newData;
			this->leftPtr = nullptr;
			this->rightPtr = nullptr;
			this->nodeHeight = 0;
		}
	//Destructor
		~AVLNode()
		{
			delete this;
		}
	//Getters
		T getData()
		{
			return this->data;
		}
		AVLNode<T>*& getLeftPtr()
		{
			return this->leftPtr;
		}
		AVLNode<T>*& getRightPtr()
		{
			return this->rightPtr;
		}
		int getHeight(AVLNode* ptr)
		{
			if (ptr == nullptr)
				return -1;
			return ptr->nodeHeight;
		}
	//Setters
		void setData(T data)
		{
			this->data = data;
		}
		void setLeftPtr(AVLNode<T>* newLeftPtr)
		{
			this->leftPtr = newLeftPtr;
		}
		void setRightPtr(AVLNode<T>* newRightPtr)
		{
			this->rightPtr = newRightPtr;
		}
		void setNodeHeight(int height)
		{
			this->nodeHeight = height;
		}
};