/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_date.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:32:09 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/25 14:59:26 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitExchange.hpp"

bool	check_format(const std::string &date)
{
	if (date.size() != 10)
		return (false);
	return (true);
};

bool	check_year(const std::string &date)
{
	char	*endptr = NULL;
	
	int	year = std::strtoll(date.substr(0, 4).c_str(), &endptr, 10);
	if (*endptr != '\0' || year < 2009 || year > 4242 || date[4] != '-')
		return (false);
	return (true);
};

bool	check_month(const std::string &date)
{
	char	*endptr = NULL;
	
	int	month = std::strtol(date.substr(5, 2).c_str(), &endptr, 10);
	if (*endptr != '\0' || month < 1 || month > 12 || date[7] != '-')
		return (false);
	return (true);
};

bool	check_day(const std::string &date)
{
	char	*endptr = NULL;
	
	int	day = std::strtol(date.substr(8, 2).c_str(), &endptr, 10);
	if (*endptr != '\0' || day < 1 || day > 31)
		return (false);
	return (true);
};

bool	is_valid_date(const std::string &date)
{
	if (!check_format(date))
		return (false);
	if (!check_year(date))
		return (false);
	if (!check_month(date))
		return (false);
	if (!check_day(date))
		return (false);
	return (true);
};