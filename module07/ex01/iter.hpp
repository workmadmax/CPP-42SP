/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:48:25 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/15 14:49:51 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*f)(T const &))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
};