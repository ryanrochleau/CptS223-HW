#pragma once
#include <iostream>
#include <string>

class Destination
{
private:
std::string destination;
int position;
public:
Destination();
Destination(int newPos, std::string newDest);
~Destination();
void printPosition();
void printDestinationName();
std::string getDestination();
int getPosition();
void setPosition(int newPos);
void setDestination(std::string newDest);
};