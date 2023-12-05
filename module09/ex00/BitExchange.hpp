/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitExchange.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:34:58 by mdouglas          #+#    #+#             */
/*   Updated: 2023/12/05 10:42:14 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <sys/stat.h>


/* check input date */

bool			check_date(const std::string &date);
bool			is_valid_date(const std::string &date);


/* check input value */

std::string		is_valid_value(const std::string &value);
void			handle_invalid_input(std::vector<std::pair<std::string, std::string> > &_vec);

/* handle input */

bool			handle_file(std::string file_name, std::ifstream &file);
bool			handle_input(std::ifstream &file, std::vector<std::pair<std::string, std::string> > &_input);

/* handle binary search */

int				handle_binary_search(const std::string & targetDate,
				const std::vector<std::pair<std::string, double> > & _vec);

void			print_result(const std::vector<std::pair<std::string, std::string> >
				&_vec, const std::vector<std::pair<std::string, double> > & _vecData);

/* handle data base */

void			handle_data_base(std::ifstream &file, std::vector<std::pair<std::string, double> > &_vData);

/* handle error */

void			handle_error(int argc, char **argv);