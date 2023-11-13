/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IdentifyReference.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:44:12 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/12 13:52:21 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

void identify(Base & p)
{
	try {
		dynamic_cast<A&>(p);
		std::cout << "class reference is A " << std::endl;
	}catch (const std::exception &e) {
		try {
			dynamic_cast<B&>(p);
			std::cout << "class reference is B " << std::endl;
		} catch (const std::exception &e) {
			try {
				dynamic_cast<C&>(p);
				std::cout << "class reference is C " << std::endl;
			} catch (const std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		}
	}
};