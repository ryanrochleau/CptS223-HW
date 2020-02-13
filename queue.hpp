#include <iostream>
#include <cstdlib>

#define SIZE 10
using namespace std;

class queue
{
	int* arr;		// array to store queue elements
	int capacity;	// maximum capacity of the queue
	int front;		// front points to front element in the queue (if any)
	int rear;		// rear points to last element in the queue
	int count;		// current size of the queue

public:
	queue(int size = SIZE); 	// constructor
	~queue();   				// destructor

	void dequeue();
	void enqueue(int x);
	int peek();
	int size();
	bool isEmpty();
	bool isFull();
};

