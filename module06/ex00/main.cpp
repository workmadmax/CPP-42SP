/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:08:34 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/12 11:09:23 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int main (int argc, char **argv) {
	
	if (argc != 2)
	{
		std::cout << "Error: Invalid number of arguments" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}

// main pdf
/* 
int main (void)
{
	ScalarConverter::convert("0");
	ScalarConverter::convert("nan");
	ScalarConverter::convert("nanf");
}
 */

