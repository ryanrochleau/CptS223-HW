#include "VectorMyJosephus.hpp"
#include "ListMyJosephus.hpp"

void TestListMyJosephus(int N, int M)
{
	clock_t startTotal = clock();
	ListMyJosephus newListJosephus(N, M);
	int randInt = rand() % 25 + 1;
	Destination temp(0, "");
	clock_t tempTime = 0;
	int elimCount = 0;
	std::ofstream logFile;
	logFile.open("./Results.log",std::ofstream::app);

	newListJosephus.populateList(randInt);

	std::cout << "Elimination Sequence: ";

	for (int count = 0, index = 1; newListJosephus.currentSize() > 1; index++, count++)
	{
		if (index > newListJosephus.currentSize())
			index = 1;
		if (count == M)
		{
			clock_t startEliminate = clock();
			temp = newListJosephus.eliminateDestination(index);
			clock_t endEliminate = clock();
			elimCount++;
			tempTime+=(endEliminate-startEliminate);

			count = 0;
			std::cout << temp.getPosition() + 1 << " ";
			newListJosephus.outputRemainingDestination();
		}
		if (index > newListJosephus.currentSize())
			index = 1;
	}
	std::cout << std::endl << "Chosen Destination: ";
	newListJosephus.printAllDestinations();
	std::cout << std::endl;
	clock_t endTotal = clock();
	logFile << "CPU Elapsed Time: " << (double)(endTotal-startTotal)/(CLOCKS_PER_SEC)*1000 << " Milliseconds" << std::endl;
	logFile << "Average Elimination Time : " << (((double)tempTime/CLOCKS_PER_SEC)*1000)/elimCount << " Milliseconds" << std::endl;
	logFile << "N: " << N << std::endl;
	logFile << "M: " << M << std::endl << std::endl;

}