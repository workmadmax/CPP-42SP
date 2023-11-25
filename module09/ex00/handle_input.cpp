/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:30:20 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/25 19:42:11 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitExchange.hpp"

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
			//std::cout << date << " | " << value << std::endl; // depuração
		}
		else
			_input.push_back(std::make_pair(line, "invalid"));
	}
	if (_input.size() == 0)
		return (false);
	file.close();
	return (true);
};
