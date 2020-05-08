#include "AVLTree.hpp"

int main(void)
{
	int num = 7;
	std::ifstream maleData, femaleData, bothData;
	maleData.open("./mencancerdata2018.csv");
	femaleData.open("./womencancerdata2018.csv");
	bothData.open("./bothcancerdata2018.csv");

	AVLTree<CancerData> maleTree(maleData), 
		femaleTree(femaleData), 
		bothTree(bothData);


	femaleTree.printInOrder();
	std::cout << std::endl;
	maleTree.printInOrder();
	std::cout << std::endl;
	bothTree.printInOrder();
	std::cout << std::endl;

	std::cout << "Worst Female Country: " <<femaleTree.findMax() << std::endl;
	std::cout << "Worst Male Country: " << maleTree.findMax() << std::endl;
	std::cout << "Worst Both Country: " << bothTree.findMax() << std::endl;
	std::cout << std::endl;
	std::cout << "Best Female Country: " << femaleTree.findMin() << std::endl;
	std::cout << "Best Male Country: " << maleTree.findMin() << std::endl;
	std::cout << "Best Both Country: " << bothTree.findMin() << std::endl;

	maleData.close();
	femaleData.close();
	bothData.close();
	return 0;
}