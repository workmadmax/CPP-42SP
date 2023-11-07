/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:04:36 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/07 13:14:21 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Bureaucrat.hpp"
#include "./includes/AForm.hpp"
#include "./includes/PresidentialPardonForm.hpp"
#include "./includes/ShrubberyCreationForm.hpp"
#include "./includes/RobotomyRequestForm.hpp"
#include "./includes/Intern.hpp"

void	testInternRobotoForm(void)
{
	std::cout << GREY << "---------- roboto --------------" << std::endl;
	try {
		Intern	someRandomIntern;
		AForm*	rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		delete rrf;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << RESET;
};

void	testInternPresidentialForm(void)
{
	std::cout << YELLOW << "---------- presidential --------------" << std::endl;
	try {
		Intern	someRandomIntern;
		AForm*	ppf;
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout << *ppf << std::endl;
		delete ppf;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << RESET;
};

void	testInternShrubberyForm(void)
{
	std::cout << GREEN << "---------- shrubbery --------------" << std::endl;
	try {
		Intern	someRandomIntern;
		AForm*	scf;
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		std::cout << *scf << std::endl;
		delete scf;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << RESET;
};

void	testInternAnyForm(void)
{
	std::cout << BLUE << "---------- any --------------" << std::endl;
	try {
		Intern	someRandomIntern;
		AForm*	any;
		any = someRandomIntern.makeForm("any form", "Bender");
		if (any != NULL) {
			std::cout << *any << std::endl;
			delete any;
		} else {
			std::cout << "Form not found" << std::endl;
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << RESET;
};

int main (void)
{
	//testInternRobotoForm();
	testInternAnyForm();
	return (0);
};