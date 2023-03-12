#include <iostream>
#include <string>
#include <stack>

int main()
{
	std::string expression;
	getline(std::cin, expression);
	std::stack<int> opperandsStack;

	for (int i = 0; i < expression.size(); i++)
	{
		if (isdigit(expression[i])) opperandsStack.push(expression[i] - 48);
		else if(isspace(expression[i])) continue;
		else
		{
			int firstNum, secondNum = 0;
			firstNum = opperandsStack.top();
			opperandsStack.pop();
			secondNum = opperandsStack.top();
			opperandsStack.pop();
			switch (expression[i])
			{
				case '+': secondNum += firstNum; break;
				case '-': secondNum -= firstNum; break;
				case '*': secondNum *= firstNum; break;
				default: break;
			}
			opperandsStack.push(secondNum);
		}
	}
	std::cout << opperandsStack.top();
	return 0;
}
