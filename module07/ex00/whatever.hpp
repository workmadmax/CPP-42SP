/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:12:25 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/15 14:17:11 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void swap(T &a, T &b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
};

template <typename T>
T min(T &a, T &b)
{
	if (a < b)
		return (a);
	return (b);
};

template <typename T>
T max(T &a, T &b)
{
	if (a > b)
		return (a);
	return (b);
};