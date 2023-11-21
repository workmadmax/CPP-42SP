/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:05:23 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/21 12:19:48 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

class Span
{
private:
	unsigned int		_size;
	std::vector<int>	_container;
public:
	Span();
	Span(unsigned int N);
	~Span();

	Span(const Span	&other);
	Span	&operator=(const Span &other);

	void	addNumber(int value);
	void	addNumber(int value, int quantity);
	int		shortestSpan();
	int		longestSpan();
};