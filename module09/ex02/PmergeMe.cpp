/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:49:03 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/27 11:18:13 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* input controller */

bool	inputController(int argc, char **argv, std::list<int> &_list, std::deque<int> &_deque)
{
	std::string			word;
	std::stringstream	ss;
	long				l;
	char				*endptr = NULL;

	for (int i = 1; i < argc; i++)
		ss << argv[i] << " ";
	while (ss >> word)
	{
		endptr = NULL;
		l = strtol(word.c_str(), &endptr, 10);
		if (*endptr == '\0' && l >= 0 && l < INT_MAX)
		{
			_list.push_back(l);
			_deque.push_back(l);
		}
		else
		{
			std::cout << word << " ";
			return (false);
		}
	}
	return (true);
};