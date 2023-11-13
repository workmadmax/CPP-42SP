/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:08:34 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/13 13:52:51 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int	main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert [literal]" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}

/* int main (void)
{
	//ScalarConverter::convert("0");
	std::cout << std::endl;
	//ScalarConverter::convert("nan");
	std::cout << std::endl;
	//ScalarConverter::convert("42.0f");
}
 */
