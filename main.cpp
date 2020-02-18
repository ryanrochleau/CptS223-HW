/*
Name: Ryan Rochleau
Assignment: PA 2
Date of last revision: 2/17/2020
Purpose: Demonstrate the Josephus problem using standard list and vector classes through inheritance
NOTE: Run the make file which will append the results of the test function in main. Running more than once
will append more results and is not recommended. Comment out test cases to reduce processing time and log file
size.
*/
/*
1) The processor does matter, a faster processor will perform faster than a slower processor. You will not receive
the same time statistics on another machine unless it's running the same or a similair processor.
2) Vector seems to perform better with smaller N values and begins to match list as N grows.
3) Running time is more dependent on N than with M. Doubling M while holding N constant hardly changes
the running time of the Josephus problem.
*/
#include "VectorMyJosephus.hpp"
#include "ListMyJosephus.hpp"

void TestVectorMyJosephus(int N, int M);
void TestListMyJosephus(int N, int M);

int main(void)
{
    srand(time(NULL));

	TestListMyJosephus(4, 3);
	TestVectorMyJosephus(4, 3);

	TestListMyJosephus(8, 3);
	TestVectorMyJosephus(8, 3);

	TestListMyJosephus(16, 3);
	TestVectorMyJosephus(16, 3);

	TestListMyJosephus(32, 3);
	TestVectorMyJosephus(32, 3);

	TestListMyJosephus(64, 3);
	TestVectorMyJosephus(64, 3);

	TestListMyJosephus(128, 3);
	TestVectorMyJosephus(128, 3);

	TestListMyJosephus(256, 3);
	TestVectorMyJosephus(256, 3);

	TestListMyJosephus(512, 3);
	TestVectorMyJosephus(512, 3);

	TestListMyJosephus(1024, 3);
	TestVectorMyJosephus(1024, 3);



	TestListMyJosephus(512, 2);
	TestVectorMyJosephus(512, 2);

	TestListMyJosephus(512, 4);
	TestVectorMyJosephus(512, 4);

	TestListMyJosephus(512, 8);
	TestVectorMyJosephus(512, 8);

	TestListMyJosephus(512, 16);
	TestVectorMyJosephus(512, 16);

	TestListMyJosephus(512, 32);
	TestVectorMyJosephus(512, 32);

	TestListMyJosephus(512, 64);
	TestVectorMyJosephus(512, 64);

	TestListMyJosephus(512, 128);
	TestVectorMyJosephus(512, 128);

	TestListMyJosephus(512, 256);
	TestVectorMyJosephus(512, 256);

    return 0;
}