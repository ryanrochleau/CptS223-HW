#include <iostream>
#include <cstdlib>

using namespace std;

// define default capacity of the queue
#define SIZE 10

/*
Test ID: Test Size
Unit: queue::size()
Description: To test if queue::size() returns 2
Test Steps: 1) Construct queue of size SIZE
2) Enqueue 2 values
3) Invoke queue::size()
4) Conditionally evaluate the value returned by queue::size()
Test data: size = 2
Preconditions: queue is size 2
Postcondition: queue is still size 2
Expected Result: queue::size() returns 2
First Result: Returns 1
Actual Result: Returns 2
Status: Passes
*/
void testSize();


/*
Test ID: Test Empty
Unit: queue::isEmpty()
Description: To test if isEmpty() returns 1 if empty and 0 if not
Test Steps: 1) Construct empty queue
2) Invoke queue::isEmpty()
3) Conditionally evaluate the value returned by queue::isEmpty()
Test data: size = 0
Preconditions: queue is size 0
Postcondition: queue is still size 0
Expected Result: isEmpty() returns 1
First Result: Returned 0
Actual Result: Returns 1
Status: Passes
*/
void testisEmpty();


/*
Test ID: Test if Full
Unit: queue::isFull()
Description: To test if isFull() returns 1
Test Steps: 1) Construct empty queue
2) Fill queue
3) Conditionally evaluate the value returned by queue::isFull()
Test data: size == capactiy
Preconditions: size and capacity are 10
Postcondition: size and capacity are 10
Expected Result: isFull() returns 1
First Result: Returned 0
Actual Result: Returns 1
Status: Passes
*/
void testisFull();


/*
Test ID: Test Dequeue Empty
Unit: queue::dequeue()
Description: To test if dequeue() exits due to empty queue
Test Steps: 1) Construct empty queue
2) call dequeue()
3) Check that dequeue() exits as a result of empty queue
Test data: size = 0
Preconditions: size is 0
Postcondition: size is 0
Expected Result: dequeue() Exits
First Result: Removes first element
Actual Result: Exits
Status: Passes
*/
void testDequeueEmpty();


/*
Test ID: Test deque
Unit: queue::dequeue()
Description: To test if dequeue() dequeues first element
Test Steps: 1) Construct empty queue
2) Insert element
3) call dequeue()
4) Check that dequeue() dequeues array index 0
Test data: size = 1
Preconditions: size is 1
Postcondition: size is 0
Expected Result: dequeue() says removing index 0 value
First Result: Removes first element
Actual Result: Removes first element
Status: Passes
*/
void testDequeue();


/*
Test ID: Test enqueue full
Unit: queue::enqueue()
Description: To test if enqueue() Exits due to full array
Test Steps: 1) Construct empty queue
2) Fill queue
3) call enqueue()
4) Check that enqueue() exits
Test data: size = 10
Preconditions: size is 10
Postcondition: size is 10
Expected Result: enqueue() exits
First Result: Inserts
Actual Result: Exits
Status: Passes
*/
void testEqueueFull();


/*
Test ID: Test enqueue
Unit: queue::enqueue()
Description: To test if enqueue() enqueues element
Test Steps: 1) Construct empty queue
2) call enqueue(10)
3) Check that enqueue() enqueues 10
Test data: size = 1
Preconditions: size is 0
Postcondition: size is 1
Expected Result: enqueue() says inserting 10
First Result: Inserts 10
Actual Result: Inserts 10
Status: Passes
*/
void testEnqueue();


/*
Test ID: Test peek empty
Unit: queue::peek()
Description: To test if peek() exits
Test Steps: 1) Construct empty queue
2) call peek()
3) Check that peek() exits
Test data: size = 0
Preconditions: size is 0
Postcondition: size is 0
Expected Result: peek() exits
First Result: peek() returns value
Actual Result: peek() exits
Status: Passes
*/
void testPeekEmpty();


/*
Test ID: Test peek
Unit: queue::peek()
Description: To test if peek() returns first value
Test Steps: 1) Construct empty queue
2) insert 2 different elements
3) Check that peek() returns first element
Test data: size = 2
Preconditions: size is 2
Postcondition: size is 2
Expected Result: peek() returns the first element
First Result: peek() returns second element
Actual Result: peek() returns first element
Status: Passes
*/
void testPeek();