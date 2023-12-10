/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:59:53 by mdouglas          #+#    #+#             */
/*   Updated: 2023/12/10 10:54:03 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitExchange.hpp"

// handle error

static void	handle_empty_file(std::ifstream &file, const std::string &filename)
{
	file.seekg(0, std::ios::end);
	if (file.tellg() == 0)
	{
		std::cerr << "Error: " << RED + filename + RESET + " file is empty." << std::endl;
		exit(1);
	}
	file.seekg(0, std::ios::beg);
};

static void	handle_permission_denied(std::ifstream &file)
{
	if (!file.is_open())
	{
		std::cerr << RED << "Error: permission denied." << RESET << std::endl;
		exit(1);
	}
};

static bool	is_file(const char *path, const std::string &filename)
{
	struct stat	st;
	stat(path, &st);
	if (!S_ISREG(st.st_mode))
	{
		std::cerr << "Error: " << RED + filename + RESET + " is not a file." << std::endl;
		return (false);
	}
	return (true);
};


static bool is_valid_args_format(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED << "Error: invalid arguments." << RESET << std::endl;
		std::cerr << "Usage: " << argv[0] << " <file_name>" << std::endl;
		exit(1);
	}
	return (true);
};

/**
 * @brief Handles errors in the program arguments.
 * 
 * @param argc The number of arguments.
 * @param argv The array of arguments.
 */
void	handle_error(int argc, char **argv)
{
	std::string filename;

	if (!is_valid_args_format(argc, argv))
		exit(EXIT_FAILURE);
	if (!is_file(argv[1], argv[1]))
		exit(EXIT_FAILURE);
	std::ifstream	file(argv[1]);
	handle_empty_file(file, argv[1]);
	handle_permission_denied(file);
};



int	processfile(char *argv)
{
	std::ifstream file;
	std::vector<std::pair<std::string, std::string> >	_input;
	std::vector<std::pair<std::string, double> >		_vData;
	if (handle_file(argv, file) == false) // input
		return (EXIT_FAILURE);
	if (handle_input(file, _input) == false)
		return (EXIT_FAILURE);
	if (!handle_file("./data/data.csv", file)) // data base
		return (EXIT_FAILURE);
	handle_invalid_input(_input);
	handle_data_base(file, _vData);
	print_result(_input, _vData);
	return (0);
}

int	main ( int argc, char **argv )
{
	handle_error(argc, argv);
	processfile(argv[1]);
	return (0);
}