#include <unordered_map>
#include "BankData.hpp"
/*
Name: Ryan Rochleau
Q1: Worst case for insert should be O(1) if we are inserting at front all the time as this should not depend on the amount of data in the list.
Q2: Worst case would be O(n) as we would end up iterating through the map in a list like fashion to find our data.
Q3: Worst case would be O(n). All data could be in one chain and we would have to iterate through the list to find the data.
Q4: Worst case to iterate through all values would be O(n) as we would need to visit all n values.
Q5: We should use an unordered_map when we want to quickly insert and access/delete data and when sorting data is not important.
Q6: Yes, I would say that it is a robust choice. We don't care for sorted information as there is no need to sort bank information. We can also access
banking information instantly through the use of the key which could be the accounts number. With the amount of banking information there is in the world, a lookup time
for something like a map, which is O(log n), could pose some problems when dealing with a large magnitude of accesses and data.
*/
int main(int argc, char* argv[])
{
	// we need a unordered map to store our key and mapped values
	// std::unordered_map<keyType, ValueType>; What should the key be? What about the value?
	std::unordered_map<int, BankData> hashMap;

	int tempAccountNum;
	double tempDouble;
	BankData tempBankData;
	std::string tempString;

	std::ifstream BankInfo;

	BankInfo.open("./BankAccounts.csv");
	std::getline(BankInfo, tempString);

	//Parse data and insert
		while (!BankInfo.eof())
		{
			std::getline(BankInfo, tempString, ',');
			tempAccountNum = std::stoi(tempString);
			tempBankData.setAcctNum(tempAccountNum);

			std::getline(BankInfo, tempString, ',');
			tempDouble = std::stod(tempString);
			tempBankData.setSavingsAmount(tempDouble);

			std::getline(BankInfo, tempString, '\n');
			tempDouble = std::stod(tempString);
			tempBankData.setCheckingAmount(tempDouble);

			hashMap.insert(std::pair<int, BankData>(tempAccountNum, tempBankData));

			std::cout << "Initial Bucket for Account " << tempAccountNum << " is " << hashMap.bucket(tempAccountNum) << std::endl;
		}
	//print # of buckets and max elements
		std::cout << "Number of buckets is " << hashMap.bucket_count() << std::endl;
		std::cout << "Max number of elements that can be stored it " << hashMap.max_size() << std::endl << std::endl;
	//Print all key values pairs
		for (auto i : hashMap)
		{
			std::cout << "Account: " << i.first << std::endl;
			std::cout << "Savings: " << i.second.getSavingsAmount() << std::endl;
			std::cout << "Checking: " << i.second.getCheckingAmount() << std::endl << std::endl;
		}
	//Erase the value 11111111
		hashMap.erase(11111111);
		std::cout << "****************************************" << std::endl;
		std::cout << "**************After Removal*************" << std::endl;
		std::cout << "****************************************" << std::endl << std::endl;
	//Print all key value pairs
		for (auto i : hashMap)
		{
			std::cout << "Account: " << i.first << std::endl;
			std::cout << "Savings: " << i.second.getSavingsAmount() << std::endl;
			std::cout << "Checking: " << i.second.getCheckingAmount() << std::endl << std::endl;
		}
	//print # of buckets
		std::cout << std::endl << "Number of buckets is " << hashMap.bucket_count() << std::endl;

	BankInfo.close();
	
	return 0;
}