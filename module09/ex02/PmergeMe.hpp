/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:25:10 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/27 11:24:24 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <list>
#include <deque>
#include <sstream>
#include <climits>
#include <ctime>
#include <cstdlib>
#include <algorithm>

/* input controller */

bool	inputController(int argc, char **argv, std::list<int> &_list, std::deque<int> &_deque);


/* Ford-Johnson algorithm - merge insert */
template <typename T>
void	simpleInsertSort(T &container)
{
	int	temp;
	typename T::iterator	it;
	typename T::iterator	prev;
	typename T::iterator	j;
	for (it = container.begin(); it != container.end(); ++it)
	{
		temp = *it;
		j = it;
		while (j != container.begin())
		{
			prev = j;
			--prev;
			if (*prev > temp)
				*j = *prev;
			else
				break;
			--j;
		}
	}
};

template <typename T>
void	mergeInsertSort(T &container)
{
	size_t					size = container.size();
	size_t					threshold = 100;
	
	if (size > threshold)
	{
		typename T::iterator	begin = container.begin();
		typename T::iterator	mid = container.begin();
		std::advance(mid, container.size() / 2);
		typename T::iterator	end = container.end();
		T						left(begin, mid);
		T						right(mid, end);
		if (left.size() > 1)
			mergeInsertSort(left);
		if (right.size() > 1)
			mergeInsertSort(right);
		std::merge(left.begin(), left.end(), right.begin(), right.end(), container.begin());
	}
	else
		simpleInsertSort(container);
};