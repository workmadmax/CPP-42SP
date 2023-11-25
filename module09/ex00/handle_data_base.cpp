/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_data_base.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:43:31 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/25 16:47:31 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitExchange.hpp"

void	handle_data_base(std::ifstream &file, std::vector<std::pair<std::string, double> > &_vData)
{
	std::string	line;
	std::string	date;
	std::string	value;
	int			pos;
	double		btc;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		pos = line.find(",");
		if (pos != -1)
		{
			date = line.substr(0, pos);
			value = line.substr(pos + 1);
			btc = std::strtod(value.c_str(), NULL);
			_vData.push_back(std::make_pair(date, btc));
		}
	}
	file.close();
};