/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_value.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:47:10 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/25 19:40:35 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitExchange.hpp"

std::string    is_valid_value(const std::string& value)
{
    unsigned int i = 0;

    for(; i < value.length() && value[i] != ' '; i++);

    if (value.empty() || i != value.length()) {
        return "invalid";
    }
    else
    {
        char* endptr = NULL;
        long l = std::strtol(value.c_str(), &endptr, 0);
        if (*endptr == '\0')
        {
            if (l > 1000)
                return "max";
            else if (l < 0)
                return "min";
            return "int";
        }
        else
        {
            endptr = NULL;
            float f = std::strtof(value.c_str(), &endptr);
            if (*endptr == '\0' || (endptr[0] == 'f' && endptr[1] == 0))
            {
                if (f > 1000)
                    return "max";
                else if( f < 0)
                    return "min";
                return "float";
            }
            else
                return "invalid";
        }
    }
}

void	handle_invalid_input(std::vector<std::pair<std::string, std::string> > &_vec)
{
	int		i = 0;
	
	std::string	invalid_date;
	
	for (std::vector<std::pair<std::string, std::string> >
		::const_iterator it = _vec.begin(); it != _vec.end(); ++it)
	{
		if (is_valid_date(it->first) == true)
		{
			invalid_date = is_valid_value(it->second);
			if (invalid_date == "invalid")
				_vec[i].second = "invalid";
			else if (invalid_date == "min")
				_vec[i].second = "min";
			else if (invalid_date == "max")
				_vec[i].second = "max";
		}
		else
			_vec[i].first = "invalid";
		i++;
	}
};