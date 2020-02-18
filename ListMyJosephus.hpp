#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "Destination.hpp"
#include <random>
#include <time.h>
#include <list>
#include <ctime>

class ListMyJosephus : public std::list<Destination>
{
private:
	int M; //Number to skip
	int N; //Number of destinations at start
	std::ifstream destinationFile;
	std::ofstream logFile;
public:
	ListMyJosephus(int newN, int newM)
	{
		if (newN < 1 || newN>1024)
		{
			std::cout << "Value of N outside bounds " << std::endl;
			exit(EXIT_FAILURE);
		}
		if (newM<0 || newM >(newN - 1))
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
	~ListMyJosephus()
	{
		logFile.close();
		destinationFile.close();
	}
	void myclear()
	{
		list::clear();
	}
	int currentSize()
	{
		return list::size();
	}
	bool isEmpty()
	{
		return list::empty();
	}
	Destination eliminateDestination(int position)
	{
		if (position<1 || position>currentSize())
		{
			std::cout << "Trying to Eliminate Outside Bounds of Array" << std::endl;
			exit(EXIT_FAILURE);
		}
		Destination temp(0, "");
		auto i = list::begin();

		for (int j = 1; j < position; j++, i++);

		temp = *i;

		list::erase(i);

		return temp;
	}
	void printAllDestinations()
	{
		if (isEmpty())
		{
			std::cout << "No Destinations to Print" << std::endl;
			return;
		}
		else
		{
			for (auto i = list::begin(); i != list::end(); ++i)
			{
				i->printPosition();
				std::cout << ". ";
				i->printDestinationName();
			}
		}
	}
	void populateList(int randInt)
	{
		std::string destination;
		Destination tempDest(0, "");
		char temp[260000];

		for (int i = 0; i < randInt; ++i)
			destinationFile.getline(temp, 260000);
		destination = strtok(temp, "\"");
		tempDest.setDestination(destination);
		tempDest.setPosition(0);
		list::emplace_back(tempDest);

		for (int i = 1; i<N; ++i)
		{
			destination = strtok(NULL, "\"");
			destination = strtok(NULL, "\"");
			tempDest.setDestination(destination);
			tempDest.setPosition(i);
			list::emplace_back(tempDest);
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
		for (auto i = list::begin(); i != list::end(); ++i)
		{
			logFile << i->getPosition()+1 << ". " << i->getDestination() << ", ";
		}
		logFile << "}" << std::endl;	
	}
};