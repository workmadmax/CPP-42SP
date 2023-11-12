/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:59:52 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/12 12:18:01 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {};

Serializer::Serializer(const Serializer& serializer)
{
	*this = serializer;
};

Serializer& Serializer::operator=(const Serializer&)
{
	return *this;
};

Serializer::~Serializer() {};

uintptr_t	Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
};

Data*		Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
};