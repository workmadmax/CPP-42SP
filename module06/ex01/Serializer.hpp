/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:56:08 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/12 12:16:59 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdint.h>

struct Data
{
	std::string	name;
	int			number;
};

class Serializer
{
private:
	Serializer();
	Serializer(Serializer const &);
	Serializer& operator=(Serializer const &);
public:
	~Serializer();
	static uintptr_t	serialize(Data *ptr);
	static Data*		deserialize(uintptr_t raw);
};