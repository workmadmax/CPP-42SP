/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:59:53 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/25 16:49:29 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitExchange.hpp"
#include <vector>

// usar apenas c++ std=98




int	main ( int argc, char **argv ) {
	if (argc != 2)
	{
		std::cerr << "Error: wrong number of arguments." << std::endl;
		return (1);
	}
	else
	{
		std::ifstream										file;
		std::vector<std::pair<std::string, std::string> >	_input;
		std::vector<std::pair<std::string, double> >		_vData;
		
		if (handle_file(argv[1], file) == false)
			return (EXIT_FAILURE);
		if (handle_input(file, _input) == false)
			return (EXIT_FAILURE);
		handle_invalid_input(_input);
		if (!handle_file("./data/data.csv", file))
			return (EXIT_FAILURE);
		handle_data_base(file, _vData);
		print_result(_input, _vData);
		
	}
	return (0);
}