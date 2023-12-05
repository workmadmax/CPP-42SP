/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:48:31 by mdouglas          #+#    #+#             */
/*   Updated: 2023/12/05 12:07:30 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* 	explicação do algoritimo 	
	 - A calculadora RPN ela funciona empilhando os numeros e desempilhando.
	 - Quando um operador é encontrado, ele desempilha os dois ultimos numeros.
	 - Faz a operação e empilha o resultado.
	 - Quando a expressão acaba, o resultado é o ultimo numero da pilha.
	 
	 * O algoritimo funciona da seguinte forma:
	 - 1 - Verifica se a string é valida.
	 - 2 - Separa a string em um array de strings.
	 - 3 - Verifica se a string é um numero ou um operador.
	 - 4 - Se for um numero, empilha.
	 - 5 - Se for um operador, desempilha os dois ultimos numeros e faz a operação.
	 
*/
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
