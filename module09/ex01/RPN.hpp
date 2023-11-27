/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:48:54 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/26 13:02:35 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cstdlib>

typedef enum t_operation
{
	SUM 		= '+',
	SUB			= '-',
	MUL			= '*',
	DIV			= '/',
} t_operation;

class RPN
{
private:
	RPN();
	RPN(const RPN	&other);
	RPN	&operator=(const RPN &);
public:

	~RPN();
	
	static std::string			expression;
	static int					wordCount;
	static float 				currentValue;
	static float				firstOperand;
	static float				secondOperand;
	static std::stack<float>	stack;
	static std::stack<char>		operationStack;

	static void					countWords(std::string expression);
	static bool					handleCheckString(std::string *stringArray);
	static bool					handlePolishNotation(std::string const *stringArray);
};