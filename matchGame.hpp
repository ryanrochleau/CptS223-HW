#include <iostream>
#include <fstream>
#include "List.hpp"
#include <string>
#include "List.cpp"
#include <random>
#include <time.h>

struct playerProfile
{
	std::string score;
	std::string name;
};
class matchGame
{
private:
	std::fstream commands; //Commands File
	std::fstream profiles; //Profiles File
	List<std::string> list; //Linked List
	playerProfile profileArray[100]; //Array of profiles
	std::string currentPlayer; //Name of current active player
	int currentPlayerScore; //Score of current active player
public:
	matchGame(); //Constructor
	~matchGame(); //Destructor
	void loadProfiles(); //Load profiles into array from file
	void insertArray(std::string name, std::string score); //Insert a name and score into the array
	void storeArray(); //Store array contents into file
	bool createProfile(); //Creates a new profile and returns false if it's a duplicate
	bool checkDuplicateName(std::string name); //Check for duplicate profiles with name and return false if there is
	int printMenu(); //Prints the menu and returns the option
	void playGame(); //Plays the matching game
	void printRules(); //Prints the rules
	void wrapper(); //Wrapper for the entire PA
	void updateScore(); //Updates scores in the array with the current player score
	void loadProfile(); //Checks a given username in the array and updates currentPlayer and currentPlayerScore if there is a match
};