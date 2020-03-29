#include <map>
#include "TwitterData.hpp"
#include <fstream>

/*
Answers:
1) We use the username of the twitter user as it makes the most sense to store based on identifiable information
rather than something like number of tweets.
2) Inserting would be worst cast O(log N)
3) Retrieving would be worst case O(log N)
4) Deleting would be worst case O(log N)
5) Iterating through the whole map would be worst case O(N)
6) Worst case would be O(N) as I searched through the map with an iterator
7) No a map is not a good data structure to retrieve the information as there's no way to quickly find users
preference. Rather, we should use a hash table so we can quickly lookup a user by their unique username and find
their preference for tweets.
*/

int main(int argc, char* argv[])
{
	// we need a map to store our key-value pairs
	// std::map<keyType, ValueType>; What should the key be? What about the value?
	std::map<std::string, TwitterData> twitterMap;
	std::map<std::string, TwitterData>::iterator mapIterator = twitterMap.begin();
	std::string temp, name;
	TwitterData tempData;


	std::ifstream twitterData;
	twitterData.open("./TwitterAccounts.csv");

	if (!twitterData.is_open())
		std::cout << "File Not Open";

	std::getline(twitterData, temp);
	while (!twitterData.eof())
	{
	//Get username
		std::getline(twitterData, temp, ',');
		tempData.setUserName(temp);

	//Get Real name
		name.clear();
		std::getline(twitterData, temp, ',');
		name.append(temp);
		name.append(",");
		std::getline(twitterData, temp, ',');
		name.append(temp);
		tempData.setActualName(name);

	//Get email
		std::getline(twitterData, temp, ',');
		tempData.setEmail(temp);

	//Get num tweets
		std::getline(twitterData, temp, ',');
		tempData.setNumTweets(std::stoi(temp));

	//Get category
		std::getline(twitterData, temp, ',');
		tempData.setCategory(temp);

	//Eat newline character
		std::getline(twitterData, temp, '\n');

	//Insert into Map
		twitterMap.insert(std::pair<std::string, TwitterData>(tempData.getUserName(), tempData));
	}

	//Print
		for (mapIterator = twitterMap.begin(); mapIterator != twitterMap.end(); mapIterator++)
		{
			std::cout << mapIterator->first << " " << mapIterator->second.getActualName() << " "
				<< mapIterator->second.getEmail() << " " << mapIterator->second.getNumTweets()
				<< " " << mapIterator->second.getCategory() << std::endl;
		}
		std::cout << std::endl;
	//Delete savage1
		twitterMap.erase("savage1");

	//Print
		for (mapIterator = twitterMap.begin(); mapIterator != twitterMap.end(); mapIterator++)
		{
			std::cout << mapIterator->first << " " << mapIterator->second.getActualName() << " "
				<< mapIterator->second.getEmail() << " " << mapIterator->second.getNumTweets()
				<< " " << mapIterator->second.getCategory() << std::endl;
		}
	std::cout << std::endl;
	//Delete Smith,Rick
		for (mapIterator = twitterMap.begin(); mapIterator != twitterMap.end(); mapIterator++)
		{
			if (mapIterator->second.getActualName() == "Smith,Rick")
			{
				twitterMap.erase("smithMan");
				break;
			}
		}

	//Print
		for (mapIterator = twitterMap.begin(); mapIterator != twitterMap.end(); mapIterator++)
		{
			std::cout << mapIterator->first << " " << mapIterator->second.getActualName() << " "
				<< mapIterator->second.getEmail() << " " << mapIterator->second.getNumTweets()
				<< " " << mapIterator->second.getCategory() << std::endl;
		}
	std::cout << std::endl;

	//Close file
		twitterData.close();

	return 0;
}