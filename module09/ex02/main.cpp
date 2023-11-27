/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:52:26 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/27 11:16:34 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Usage ./PmergeMe 'positive integer sequence'";
		return(EXIT_FAILURE);
	}

	std::list<int>		_list;
	std::deque<int>		_deque;

	if (inputController(argc, argv, _list, _deque) == false)
	{
		std::cerr << "parameter must be a positive integer value";
		return (EXIT_FAILURE);
	}
	
	//PRINT BEFORE///
	std::cout << "Before:	";
 	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	//SORT with std:list and TAKE TIME
	std::clock_t start_time = std::clock();
    mergeInsertSort(_list);
    std::clock_t end_time = std::clock();
	
	//PRINT AFTER
	std::cout << "After:	";
 	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	//PRINT TIME for LIST
	double res_time = static_cast<double>(end_time - start_time) / (double)CLOCKS_PER_SEC *  1000000;
    std::cout << "Time to process a range of " << _list.size() << " elements with std::list<int> sort: " << res_time << " us" << std::endl;
	
	//SORT with std::deque and TAKE TIME,
	start_time = std::clock();
    mergeInsertSort(_deque);
    end_time = std::clock();

	//PRINT TIME for DEQUE
	res_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque<int> sort: " << res_time << " us" << std::endl;

    return 0;
}