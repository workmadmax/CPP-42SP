/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:59:53 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/25 12:35:59 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitExchange.hpp"
#include <vector>

// usar apenas c++ std=98

bool	handle_file(std::string file_name, std::ifstream &file)
{
	file.open(file_name);
	if (!file.is_open())
	{
		std::cerr << "Error: file not found." << std::endl;
		return (false);
	}
	file.seekg(0, std::ios::end);
	if (file.tellg() == 0)
	{
		std::cerr << "Error: file is empty." << std::endl;
		return (false);
	}
	file.seekg(0, std::ios::beg);
	return (true);
};

bool	handle_input(std::ifstream &file, std::vector<std::pair<std::string, std::string> > &_input)
{
	std::string line;
	std::string date;
	std::string value;
	int			pos;

	while (std::getline(file, line))
	{
		pos = line.find(" | ");
		if (pos != -1)
		{
			date = line.substr(0, pos);
			value = line.substr(pos + 3);
			_input.push_back(std::make_pair(date, value));
			std::cout << date << " | " << value << std::endl; // depuração
		}
		else
		{
			std::cerr << "Error: file is not in the correct format." << std::endl;
			return (false);
		}
	}
	if (_input.size() == 0)
		return (false);
	file.close();
	return (true);
};

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
		
		if (handle_file(argv[1], file) == false)
			return (EXIT_FAILURE);
		if (handle_input(file, _input) == false)
			return (EXIT_FAILURE);
	}
	return (0);
}