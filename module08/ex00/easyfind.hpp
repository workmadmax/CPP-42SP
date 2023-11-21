/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:28:53 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/21 11:47:27 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <exception>

class MyException : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "Value not found!";
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it;
	
	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw MyException();
	return (it);
}

