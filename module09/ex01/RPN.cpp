/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:58:43 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/26 13:07:02 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdlib>

// init static variables

int					RPN::wordCount = 0;
float				RPN::currentValue = 0;
float				RPN::firstOperand = 0;
float				RPN::secondOperand = 0;
std::string			RPN::expression = "";
std::stack<float>	RPN::stack;
std::stack<char>	RPN::operationStack;

// constructor and destructor canonical form
RPN::RPN() {};
RPN::~RPN() {};
RPN & RPN::operator=(const RPN &) { return *this; };
RPN::RPN(const RPN &) {};

/* member function */

void	RPN::countWords(std::string expression)
{
	std::stringstream 	ss(expression);
	std::string 		word;

	ss << expression;
	while (ss >> word)
		wordCount++;
};

bool	RPN::handleCheckString(std::string *stringArray)
{
	std::stringstream 	ss(expression);
	std::string 		word;

	for (int i = 0; i < wordCount; i++)
	{
		ss >> stringArray[i];
		if (stringArray[i].length() != 1)
			return (false);
		else if (!std::isdigit(stringArray[i][0])
					&& stringArray[i][0] != '+' && stringArray[i][0] != '-'
					&& stringArray[i][0] != '*' && stringArray[i][0] != '/')
			return (false);
	}
	return (true);
};

bool RPN::handlePolishNotation(std::string const *arr)
{
    int i = 0;
    char oper;

    while (i < wordCount)
    {
        if (isdigit(arr[i][0]))
        {
            currentValue = std::atof(arr[i].c_str());
            stack.push(currentValue);
        }
        else if (!isdigit(arr[i][0]) && stack.size() < 2)
            return false;
        else if (!isdigit(arr[i][0]))
        {
            operationStack.push(arr[i][0]);
        }
        if (stack.size() >= 2 && operationStack.size() >= 1)
        {
            oper = operationStack.top();
            operationStack.pop();
            secondOperand = stack.top();
            stack.pop();
            firstOperand = stack.top();
            stack.pop();
            switch (oper)
            {
                case SUM:
                    stack.push(firstOperand + secondOperand);
                    break;
                case DIV:
					if (secondOperand == 0)
						return (false);
                    stack.push(firstOperand / secondOperand);
                    break;
                case SUB:
                    stack.push(firstOperand - secondOperand);
                    break;
                case MUL:
                    stack.push(firstOperand * secondOperand);
                    break;
            }
        }
        i++;
    }
	if (stack.size() != 1 || operationStack.size() != 0)
		return (false);
    return (true);
};