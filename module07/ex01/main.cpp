/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:49:53 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/15 15:02:32 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>
#include "iter.hpp"

void print(int const &i)
{
	std::cout << i << std::endl;
};

static void	flood_vector(std::vector<int> &vector)
{
	vector.push_back(11);
	vector.push_back(12);
	vector.push_back(13);
	vector.push_back(14);
	vector.push_back(15);
};

int main(void)
{
	int array[] = {1, 2, 3, 4, 5};
	std::vector<int> vector;

	flood_vector(vector);

	iter(array, 5, print);
	std::cout << std::endl;
	iter(vector.data(), 5, print);
	return (0);
};