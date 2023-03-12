#include <iostream>
#include <string>
#include <stack>

bool checkBrackets(char left, char right)
{
	return (left == '(' && right == ')') || (left == '[' && right == ']') || (left == '{' && right == '}');
}

int main()
{
	std::stack<char> bracketsStack;
	std::string str;
	getline(std::cin, str);
	for (std::string::size_type i = 0; i < str.size(); i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			bracketsStack.push(str[i]);
		}
		else if ((str[i] == ')' || str[i] == ']' || str[i] == '}') && bracketsStack.empty())
		{
			bracketsStack.push(str[i]); break;
		}
		else if (checkBrackets(bracketsStack.top(), str[i]))
		{
			bracketsStack.pop();
		}
		else
		{
			bracketsStack.push(str[i]); break;
		}
	}
	if (bracketsStack.empty()) std::cout << "yes";
	else std::cout << "no";
	
	return 0;
};
