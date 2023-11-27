/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:48:31 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/26 13:02:16 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: invalid number of arguments." << std::endl;
		return (1);
	}
	RPN::expression = argv[1];
	RPN::countWords(RPN::expression);
	std::string stringArray[RPN::wordCount];
	if (RPN::handleCheckString(stringArray) == false)
	{
		std::cout << "Error: invalid expression." << std::endl;
		return (EXIT_FAILURE);
	}
	if (RPN::handlePolishNotation(stringArray) == true)
	{
		if (RPN::stack.size() == 1 && RPN::operationStack.size() == 0)
			RPN::currentValue = RPN::stack.top();
		else
			std::cout << "Error: invalid expression." << std::endl;
	}
	else
	{
		std::cout << "Error: invalid expression." << std::endl;
		return (EXIT_FAILURE);
	}
	std::cout << RPN::currentValue << std::endl;
	return (EXIT_SUCCESS);
}