#include "Destination.hpp"
Destination::Destination()
{
    position = -1;
    destination = "";
}
Destination::Destination(int newPos, std::string newDest)
{
    position = newPos;
    destination = newDest;
}
Destination::~Destination()
{

}
void Destination::printPosition()
{
	std::cout << position+1;
}
void Destination::printDestinationName()
{
    std::cout << destination << std::endl;
}
std::string Destination::getDestination()
{
    return destination;
}
int Destination::getPosition()
{
    return position;
}
void Destination::setPosition(int newPos)
{
    position = newPos;
}
void Destination::setDestination(std::string newDest)
{
    destination = newDest;
}