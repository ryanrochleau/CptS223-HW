#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <fstream>
#include "Destination.hpp"
#include <random>
#include <time.h>
#include <ctime>

class VectorMyJosephus : public std::vector<Destination>
{
private:
int M; //Number to skip
int N; //Number of destinations at start
std::ifstream destinationFile;
std::ofstream logFile;
public:
VectorMyJosephus(int newN, int newM)
{
	if (newN < 1 || newN>1024)
	{
		std::cout << "Value of N outside bounds " << std::endl;
		exit(EXIT_FAILURE);
	}
	if (newM<0 || newM > (newN - 1))
	{
		std::cout << "Value of M outside bounds" << std::endl;
		exit(EXIT_FAILURE);
	}
	destinationFile.open("./destinations.csv");
	if (!destinationFile.is_open())
	{
		std::cout << "Failure To Open File" << std::endl;
		exit(EXIT_FAILURE);
	}
	logFile.open("./Results.log", std::ofstream::app);
	if(!logFile.is_open())
	{
		std::cout << "Failure To Open File" << std::endl;
		exit(EXIT_FAILURE);
	}
    N = newN;
    M = newM;
}
~VectorMyJosephus()
{
	logFile.close();
	destinationFile.close();
}
void myclear()
{
    vector::clear();
}
int currentSize()
{
    return vector::size();
}
bool isEmpty()
{
    return vector::empty();
}
Destination eliminateDestination(int index)
{
    Destination temp(0,"");
    if(index<size() && index>=0)
    {
        temp = at(index);
        erase(begin()+index);
        return temp;
    }
    else
        std::cout << "Index " << index <<" Outside Bounds of Vector" << std::endl;
        
}
void printAllDestinations()
{
	if (isEmpty())
	{
		std::cout << "No Destinations to Print" << std::endl;
		return;
	}
	for (auto i = vector::begin(); i < vector::end(); ++i)
	{
		i->printPosition();
		std::cout << ". ";
		i->printDestinationName();
	}
}
void populateVector(int randInt)
{
    std::string destination;
    Destination tempDest(0, "");
    char temp[260000];

    for(int i = 0;i < randInt;++i)
        destinationFile.getline(temp,260000);
	destination = strtok(temp, "\"");
	tempDest.setDestination(destination);
    tempDest.setPosition(0);
	vector::emplace_back(tempDest);

    for(int i = 1;i<N;++i)
    {
		destination = strtok(NULL, "\"");
        destination = strtok(NULL,"\"");
        tempDest.setDestination(destination);
        tempDest.setPosition(i);
        vector::emplace_back(tempDest);
    }
}
std::ofstream& getLog()
{
	return logFile;
}
void outputRemainingDestination()
{
	if (isEmpty())
		return;
	logFile << "{";
	for (auto i = vector::begin(); i < vector::end(); ++i)
	{
		logFile << i->getPosition()+1 << ". " << i->getDestination() << ", ";
	}
	logFile << "}" << std::endl;
}
};