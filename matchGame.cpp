#include "matchGame.hpp"
//Constructor
matchGame::matchGame()
{
	profiles.open("profiles.csv"); //Open profiles file
	commands.open("commands.csv"); //Open commands file
	loadProfiles(); //Load the profiles into array
	list.populateList(commands); //Populate list
}

//Destructor
matchGame::~matchGame()
{
	list.storeList(commands); //Store list into file
	storeArray(); //Store array into file
	profiles.close(); //Close files
	commands.close();
}

void matchGame::loadProfiles() //Load profiles from file
{
	char temp[50];
	std::string name, score;

	while (!profiles.eof()) //While not at end of file
	{
		profiles.getline(temp, 200);
		if (temp[0]!=0) //Check for empty string
		{
			name = strtok(temp, ",");
			score = strtok(NULL, ",");
			insertArray(name, score);
		}
	}
}

//Inserts a given name and score into the array at the front
void matchGame::insertArray(std::string name, std::string score)
{
	int i = 0;
	if (profileArray[i].name.empty()) //Check if first spot in empty
	{
		profileArray[i].name = name;
		profileArray[i].score = score;
	}
	else
	{
		for (i = 98; i >= 0; --i) //Loop through array and shift profiles down
		{
			profileArray[i + 1] = profileArray[i];
		}
		profileArray[0].name = name; //insert at newly freed index 0
		profileArray[0].score = score;
	}
}

//Store array into file
void matchGame::storeArray()
{
	std::string temp;
	int i = 0;
	profiles.close();
	profiles.open("profiles.csv", std::fstream::out | std::fstream::trunc); //Open in truncated mode to delete file contents

	for (i = 0; i < 100; ++i) //Loop through array
	{
		if (!profileArray[i].name.empty()) //If the current index isn't empty then concatenate and add to file
		{
			temp = profileArray[i].name + "," + profileArray[i].score + '\n';
			profiles << temp;
		}
	}
}

//Create a profile and return false if duplicate
bool matchGame::createProfile()
{
	std::string name, score = "0";
	std::cout << "Enter a New Player Name: ";
	std::cin >> name;
	if (checkDuplicateName(name)) //If valid name
	{
		insertArray(name, score);
		system("cls");
		currentPlayer = name;
		currentPlayerScore = 0;
		return true;
	}
	else //If invalid name
	{
		std::cout << "Duplicate Profile Detected" << std::endl;
		system("pause");
		system("cls");
		return false;
	}
}

//Check for duplicate name in array
bool matchGame::checkDuplicateName(std::string name)
{
	for (int i = 0; i < 100; ++i) //Loop through and compare names
	{
		if (profileArray[i].name == name)
		{
			return false; //Duplicate found
		}
	}
	return true; //Duplicate not found
}

//Prints menu and returns option
int matchGame::printMenu()
{
	int choice = 0;
	while (choice < 1 || choice>6) //Check for valid input
	{
		std::cout << "1. Game Rules" << std::endl
			 	  << "2. Play Game" << std::endl
			  	  << "3. Load Previous Game" << std::endl
			 	  << "4. Add Command" << std::endl
				  << "5. Remove Command" << std::endl
				  << "6. Exit" << std::endl;
		std::cin >> choice;
		system("cls");
		return choice;
	}
}

//Plays the game
void matchGame::playGame()
{
	std::string function, tempDescription, descriptions[3];
	int randomN = -1, answer = -1, NofGames = 0;

	if (currentPlayer.empty()) //Check if there is an not and active player
	{
		while (!createProfile()); //Get a new valid player
	}

	do //Get # of matches to play
	{
		std::cout << "How Matches Would You Like To Play?" << std::endl << "You may play 0 - " << list.getCount() << std::endl << ">>";
		std::cin >> NofGames;
		system("cls");
	} while (NofGames<0 || NofGames>list.getCount());

	for (int i = 0; i < NofGames; ++i) //Loop for each match
	{
		system("cls");
		randomN = rand() % list.getCount() + 1; //Generate random number 1-# of Nodes
		do //Get 3 functions and descriptions
		{
			list.getnList(randomN, function, descriptions[1], false);
			randomN = rand() % list.getCount() + 1;
			list.getnList(randomN, function, descriptions[2], false);
			randomN = rand() % list.getCount() + 1;
		} while (!list.getnList(randomN, function, descriptions[0], true)||descriptions[0]==descriptions[1]||descriptions[0]==descriptions[2]||descriptions[2]==descriptions[1]); //Check for duplicates
		std::cout << function << std::endl;
		randomN = rand() % 3; //Random number for where correct answer will be displayed
		if (randomN == 0) //Answer is 1
		{
			std::cout << "1. " << descriptions[0] << std::endl
					  << "2. " << descriptions[1] << std::endl
					  << "3. " << descriptions[2] << std::endl
					  << "Answer: ";
			std::cin >> answer;
			system("cls");
			if (answer == 1) //Correct Choice
			{
				std::cout << "Correct! " << function << " - " << descriptions[0];
				currentPlayerScore++;
				system("pause");
			}
			else // Wrong Choice
			{
				std::cout << "Incorrect! " << function << " - " << descriptions[0];
				currentPlayerScore--;
				system("pause");
			}
		}
		else if (randomN == 1) //Answer is 2
		{
			std::cout << "1. " << descriptions[1] << std::endl
					  << "2. " << descriptions[0] << std::endl
					  << "3. " << descriptions[2] << std::endl
					  << "Answer: ";
			std::cin >> answer;
			system("cls");
			if (answer == 2) //Correct choice
			{
				std::cout << "Correct! " << function << " - " << descriptions[0];
				currentPlayerScore++;
				system("pause");
			}
			else //Wrong choice
			{
				std::cout << "Incorrect! " << function << " - " << descriptions[0];
				currentPlayerScore--;
				system("pause");
			}
		}
		else //Answer is 3
		{
			std::cout << "1. " << descriptions[2] << std::endl
					  << "2. " << descriptions[1] << std::endl
					  << "3. " << descriptions[0] << std::endl
					  << "Answer: ";
			std::cin >> answer;
			system("cls");
			if (answer == 3) // Correct Choice
			{
				std::cout << "Correct! " << function << " - " << descriptions[0];
				currentPlayerScore++;
				system("pause");
			}
			else // Wrong Choice
			{
				std::cout << "Incorrect! " << function << " - " << descriptions[0];
				currentPlayerScore--;
				system("pause");
			}
		}
	}
	list.resetFlag(); //Reset chosen flags for next game
	updateScore(); //Update current players score
	system("cls");
}

//Prints rules
void matchGame::printRules()
{
	std::cout << "A Linux command will be displayed to the screen and your objective is to select" << std::endl
			  << "the right description that matches said command. Each correct answer will reward" << std::endl
			  << "you with 1 point and each wrong answer will deduct 1 point." << std::endl << std::endl
			  << "You may choose to play between 1 and however many linux commands there are worth of" << std::endl
			  << "hands.";
	system("pause");
	system("cls");
}

//Runs the whole PA
void matchGame::wrapper()
{
	int choice = -1;
	while (choice != 6)
	{
		choice = printMenu(); //Get menu choice
		switch (choice) //Switch case for each menu option
		{
		case 1:
			printRules();
			break;
		case 2:
			playGame();
			break;
		case 3:
			loadProfile();
			break;
		case 4:
			list.newFunction();
			break;
		case 5:
			list.removeFunction();
			break;
		}
	}

}

//Updates the score in the array of the current player
void matchGame::updateScore() 
{
	int i = 0;
	for (i = 0; currentPlayer != profileArray[i].name && i < 100; ++i); //Loop until player is found or max index reach
	if (currentPlayer == profileArray[i].name) //Check if player was found
	{
		profileArray[i].score = std::to_string(currentPlayerScore); //Update the score
	}
}

//Search array for a player and load them into the current player
void matchGame::loadProfile()
{
	std::string name;
	std::cout << "Enter a name (Case Sensitive): ";
	std::cin >> name;
	system("cls");
	for (int i = 0; i < 100; ++i) //Loop through array
	{
		if (profileArray[i].name == name) //Check if names match
		{
			currentPlayer = profileArray[i].name; //Set as current player
			currentPlayerScore = std::stoi(profileArray[i].score); //Copy score
			std::cout << "Score: " << profileArray[i].score << std::endl; //Display score
			system("pause");
			system("cls");
			break;
		}
	}
}