/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IdentifyPointer.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:43:06 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/12 13:49:53 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

void identify(Base * p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "class pointer is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "class pointer is B" << std::endl;
	else
		std::cout << "class pointer is C" << std::endl;
};