/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:08:34 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/11 15:00:50 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int main () {
	
	ScalarConverter::convert("0");
	std::cout << "---------------------" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << "---------------------" << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << "---------------------" << std::endl;
	return 0;
}
/* 
int main( int argc, char **argv )
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	testNaN();
	ScalarConverter::convert(argv[1]);
	return (0);
	
	static	bool	isValideNumericRange(std::string str)
{
	if (
		str == "-inff" 	||
		str == "+inff" 	||
		str == "nanf" 	||
		str == "-inf" 	||
		str == "+inf" 	||
		str == "-nan" 	||

		)
		return (true);
	return (false);
};

} */
