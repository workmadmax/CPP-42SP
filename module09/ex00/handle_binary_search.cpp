/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_binary_search.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:31:19 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/25 19:44:56 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitExchange.hpp"

int			handle_binary_search
	(const std::string & targetDate, const std::vector<std::pair<std::string, double> > & _vec)
{
	int		low = 0;
	int		high = _vec.size() - 1;
	int		mid = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (_vec[mid].first == targetDate)
			return (mid);
		else if (_vec[mid].first < targetDate)
			low = mid + 1;
		else
			high = mid - 1;
	}
	if (high < 0)
		return (-1);
	else
		return (high);
}

void	print_result
	(const std::vector<std::pair<std::string, std::string> >
		&_vec, const std::vector<std::pair<std::string, double> > & _vecData)
{
	double	mult;
	int		index;
	
	for (std::vector<std::pair<std::string, std::string> >
		::const_iterator it = _vec.begin(); it != _vec.end(); ++it)
	{
		if (it->first == "invalid" || it->second == "invalid")
			std::cout << "Error: invalid input." << std::endl;
		else if (it->second == "max")
			std::cout << "Error: value too large a number." << std::endl;
		else if (it->second == "min")
			std::cout << "Error: value is not positeve." << std::endl;
		else
		{
			index = handle_binary_search(it->first, _vecData);
			mult = std::strtof(it->second.c_str(), NULL) * _vecData[index].second;
			std::cout << it->first << " => " << it->second << " = " << mult << std::endl;
		}
	}
}
