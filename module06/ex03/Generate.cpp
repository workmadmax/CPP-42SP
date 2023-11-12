/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:39:26 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/12 13:42:23 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base	*generate( void )
{
	int		random;

	srand(time(NULL));
	random = rand() % 3;
	if (random == 0) {
		std::cout << "create class A" << std::endl;
		return (new A);
	} else if (random == 1) {
		std::cout << "create class B" << std::endl;
		return (new B);
	} else {
		std::cout << "create class C" << std::endl;
		return (new C);
	}
	return (NULL);
};