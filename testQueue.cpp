#include "testQueue.hpp"
#include "queue.hpp"

using namespace std;

void testSize()
{
	queue testQueue(SIZE);
    testQueue.enqueue(1);
    testQueue.enqueue(1);
	if(testQueue.size()==2)
		cout<< "Test Passes" << endl;
	else
		cout << "Test Failed" << endl;
	
}
void testisEmpty()
{
	queue testQueue(SIZE);
	if(testQueue.isEmpty())
		cout << "Test Passes" << endl;
	else if(!testQueue.isEmpty())
		cout << "Test Fails" << endl;
	
}
void testisFull()
{
	queue testQueue(SIZE);
	for(int i = 0;i<10;i++)
	{
		testQueue.enqueue(10);
	}
	if(testQueue.isFull())
		cout << "Test Passes" << endl;
	else
		cout << "Test Fails" << endl;
	
}
void testDequeueEmpty()
{
    queue testQueue(SIZE);

    testQueue.dequeue();
}
void testDequeue()
{
    queue testQueue(SIZE);

    testQueue.enqueue(10);

    testQueue.dequeue();
}
void testEqueueFull()
{
    queue testQueue(SIZE);


}
void testEnqueue()
{
    queue testQueue(SIZE);

    testQueue.enqueue(10);
}
void testPeekEmpty()
{
    queue testQueue(SIZE);
    int temp;

   temp = testQueue.peek();
}
void testPeek()
{
    queue testQueue(SIZE);
    int temp;

    testQueue.enqueue(10);
    testQueue.enqueue(3);

    temp = testQueue.peek();

    if(temp==10)
        cout << "Test Passes";
    else
        cout << "Test Fails";
    
}