/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:53:49 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/22 12:23:23 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <vector>
#include <algorithm>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
		typedef typename Container::iterator iterator;

		MutantStack() : std::stack<T, Container>() {};
		MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {};
		virtual ~MutantStack() {};

		MutantStack &operator=(const MutantStack &other)
		{
			if (this == &other)
				return (*this);
			std::stack<T, Container>::operator=(other);
			return (*this);
		};
		
		iterator	begin()
		{
			if (this->c.empty())
				throw std::logic_error("Empty stack");
			return (this->c.begin());
		};
		
		iterator	end()
		{
			if (this->c.empty())
				throw std::logic_error("Empty stack");
			return (this->c.end());
		};
};