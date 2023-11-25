/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:07:06 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/23 19:19:01 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <string>

// canonical form

Span::Span() : _size(0)
{
	std::cout << " Span: Default constructor called" << std::endl;
};

Span::Span(unsigned int N) : _size(N)
{
	std::cout << " Span: Parametric constructor called" << std::endl;
};

Span::Span(const Span &other) : _size(other._size), _container(other._container)
{
	std::cout << " Span: Copy constructor called" << std::endl;
};

Span::~Span()
{
	std::cout << " Span: Destructor called" << std::endl;
};

Span	&Span::operator=(const Span &other)
{
	std::cout << " Span: Assignation operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->_size = other._size;
	this->_container = other._container;
	return (*this);
};

// member functions

void	Span::addNumber(int value)
{
	if (this->_container.size() >= this->_size)
		throw std::length_error("Span is full");
	this->_container.push_back(value);
};

void	Span::addNumber(int value, int quantity)
{
	if (this->_container.size() + quantity > this->_size)
		throw std::length_error("Span is full");
	this->_container.insert(this->_container.end(), quantity, value);
};

int		Span::shortestSpan()
{
	if (this->_container.size() <= 1)
		throw std::length_error("Span is empty or has only one element");
	
	std::sort(this->_container.begin(), this->_container.end());
	int shortSpan = std::numeric_limits<int>::max();
	for (std::vector<int>::iterator it = this->_container.begin(); it != this->_container.end() - 1; it++)
	{
		int span = *(it + 1) - *it;
		shortSpan = (span < shortSpan) ? span : shortSpan;
	}
	return (shortSpan);
};



int		Span::longestSpan()
{
	if (this->_container.size() <= 1)
		throw std::length_error("Span is empty or has only one element");
	std::vector<int> copy = this->_container;
	std::sort(copy.begin(), copy.end());
	return (*(copy.end() - 1) - *copy.begin());
};
