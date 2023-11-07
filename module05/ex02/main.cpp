/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:29:51 by madmax42          #+#    #+#             */
/*   Updated: 2023/11/07 14:18:11 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "testsForms.hpp"

int main (void)
{
	Bureaucrat *bureaucrat = new Bureaucrat("leila", 1);
	std::cout << bureaucrat->getName() << std::endl;
	allTestsAForms();
	delete bureaucrat;
	return (0);
}