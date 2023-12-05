/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:58:43 by mdouglas          #+#    #+#             */
/*   Updated: 2023/12/05 11:11:34 by mdouglas         ###   ########.fr       */
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

/**
 * @brief Counts the number of words in the given expression.
 * 
 * @param expression The expression to count words from.
 */
void	RPN::countWords(std::string expression)
{
	std::stringstream 	ss(expression);
	std::string 		word;

	ss << expression;
	while (ss >> word)
		wordCount++;
};

/**
 * @brief Checks if the given string array contains valid characters.
 * 
 * This function checks each element of the string array and verifies if it is a single character
 * and if it is a digit or one of the four basic arithmetic operators: +, -, *, or /.
 * 
 * @param stringArray The string array to be checked.
 * @return true if all elements of the string array are valid, false otherwise.
 */
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

/**
 * @brief Handles the evaluation of a mathematical expression in Reverse Polish Notation (RPN).
 * 
 * This function takes an array of strings representing the RPN expression and evaluates it.
 * It uses a stack to store operands and an operation stack to store operators.
 * The function iterates through the array, performing the necessary operations
 * based on the current element.
 * If the expression is valid and can be evaluated successfully, the function returns true.
 * Otherwise, it returns false.
 * 
 * @param arr The array of strings representing the RPN expression.
 * @return True if the expression is valid and can be evaluated successfully, false otherwise.
 */
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