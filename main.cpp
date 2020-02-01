#include <iostream>
#include <fstream>
#include "matchGame.hpp"
/*
Name: Ryan Rochleau
Last Updated: 1/31/20
Assignment: PA 1 Linux Function Matching Game
Purpose: Match Linux commands to their respective description. Explore linked lists
and arrays more to compare and contrast their advantages and disadvantages.
*/

/*
ADVANTAGES/DISADVANTAGES LINKED LIST

Advantage: Inserting to the front is O(1) and is easy to implement. Used when inserting new functions.

Disadvantage: Searching for a function is O(n) and is easy-ish to implement. Used when searching for duplicate functions
*/

/*
ADVANTAGES/DISADVANTAGES ARRAY

Advantages: Very simple to implement. Array just need a data type and size.

Disadvantages: Inserting into the front of the list for profiles was tedious and inefficient. Each bit of data had
to be shifted to the right to make way for a new bit of data.
*/

int main(void)
{ 
	srand(time(NULL));
	matchGame game;
	game.wrapper();

}