/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitExchange.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:26:29 by mdouglas          #+#    #+#             */
/*   Updated: 2023/12/10 10:32:28 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitExchange.hpp"

// handle input

/**
 * Opens a file with the given file name and checks for errors.
 * 
 * @param file_name The name of the file to be opened.
 * @param file The ifstream object to open the file with.
 * @return True if the file was successfully opened, false otherwise.
 */
bool	handle_file(std::string file_name, std::ifstream &file)
{
	file.open(file_name);
	if (!file.is_open())
	{
		std::cerr << "Error: file not found." << std::endl;
		return (false);
	}
	return (true);
};

/**
 * @brief Reads input from a file and populates a vector with pairs of strings.
 * 
 * This function reads each line from the given file and splits it into a date and a value.
 * If the line contains the delimiter " | ", it creates a pair of strings with the date and value
 * and adds it to the input vector. If the line does not contain the delimiter, it creates a pair
 * with the line itself and the string "invalid" and adds it to the input vector.
 * 
 * @param file The input file stream to read from.
 * @param _input The vector to store the pairs of strings.
 * @return True if the input vector is not empty after reading, false otherwise.
 */
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
	file.close();
	return (true);
};

// handle format

/**
 * @brief Checks if a given date is valid.
 * 
 * @param date The date to be checked in the format "YYYY-MM-DD".
 * @return true if the date is valid, false otherwise.
 */
bool	check_date(const std::string &date)
{
	char	*endptr = NULL;
	int		year;
	int		month;
	int		day;

	if (date.size() != 10)
		return (false);
	year = std::strtol(date.substr(0, 4).c_str(), &endptr, 10);
	if (*endptr != '\0' || year < 2009 || year > 9999 || date[4] != '-')
		return (false);
	month = std::strtol(date.substr(5, 2).c_str(), &endptr, 10);
	if (*endptr != '\0' || month < 1 || month > 12 || date[7] != '-')
		return (false);
	endptr = NULL;
	day = std::strtol(date.substr(8, 2).c_str(), &endptr, 10);
	if (*endptr != '\0' || day < 1 || day > 31 || (year == 2009 && month == 01 && day == 01))
		return (false);
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return (false);
	if (month == 2 && day > 28) {
		int max_day = 28;
		if (year % 4 == 0)
			max_day = 29;
		if ((year % 100 == 0 && year % 400 != 0) || (year % 400 == 0 && year % 4000 == 0))
			max_day = 28;
		if (day > max_day)
			return (false);
	}
	return (true);
}

/**
 * @brief Checks if a given date is valid.
 * 
 * @param date The date to be checked.
 * @return true if the date is valid, false otherwise.
 */
bool	is_valid_date(const std::string &date)
{
	if (check_date(date) == false)
		return (false);
	return (true);
};

// handle value

/**
 * @brief Checks if a given value is valid.
 * 
 * @param value The value to be checked.
 * @return A string indicating the validity of the value.
 *         - "invalid" if the value is empty or contains non-numeric characters.
 *         - "max" if the value is greater than 1000.
 *         - "min" if the value is less than 0.
 *         - "int" if the value is a valid integer.
 *         - "float" if the value is a valid floating-point number.
 */
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

/**
 * @brief Handles invalid input in the given vector.
 * 
 * This function iterates through the vector of pairs and checks if the first element
 * of each pair is a valid date.
 * If it is a valid date, it checks the second element for valid values and updates it accordingly.
 * If the first element is not a valid date, it updates it to "invalid".
 * 
 * @param _vec The vector of pairs to handle invalid input for.
 */
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

// handle binary search

/**
 * @brief Performs a binary search on a vector of pairs to find the index of a target date.
 * 
 * @param targetDate The target date to search for.
 * @param _vec The vector of pairs to search in.
 * @return The index of the target date if found, -1 otherwise.
 */
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

/**
 * @brief Prints the result of the calculations based on the input vectors.
 * 
 * This function iterates through the input vector of pairs and performs calculations based on the values.
 * If the input is invalid or out of range, an error message is printed.
 * Otherwise, the function performs a binary search to find the corresponding value 
 * in the second input vector,
 * multiplies it with the value from the first input vector, and prints the result.
 * 
 * @param _vec The input vector of pairs containing strings.
 * @param _vecData The input vector of pairs containing strings and doubles.
 */
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

// handle data base

/**
 * @brief Reads data from a file and populates a vector with pairs of strings and doubles.
 * 
 * @param file The input file stream to read data from.
 * @param _vData The vector to store the pairs of strings and doubles.
 */
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
			btc = std::strtod(value.c_str(), NULL); // converte for double value
			_vData.push_back(std::make_pair(date, btc)); // create pair string (date, value)
		}
	}
	file.close();
};

