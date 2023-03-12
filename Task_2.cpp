#include <iostream>
#include <vector>
#include <string>

int main()
{
	int allPagesSize, currentPageIndex{}, tabsNum = 0;
	std::cin >> allPagesSize;
	std::vector<std::string> allPages;
	std::string currentAction;
	getline(std::cin, currentAction);
	if (currentAction.rfind("Run", 0) == 0)
	{
		allPages.push_back(currentAction.substr(4, currentAction.size()));
		currentPageIndex = allPages.size() - 1;
	}
	for (int i = 0; i < allPagesSize; i++)
	{
		std::string currentAction;
		getline(std::cin, currentAction);
		if (currentAction.rfind("Run", 0) == 0)
		{
			allPages.push_back(currentAction.substr(4, currentAction.size()));
			currentPageIndex = allPages.size() - 1;
		}
		else
		{
			tabsNum = std::count(currentAction.begin(), currentAction.end(), '+');
			currentPageIndex = (currentPageIndex + tabsNum) % allPages.size();
		}
		std::cout << allPages[currentPageIndex] << std::endl;
	}
	return 0;
}
