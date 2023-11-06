/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsForms.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:12:09 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/06 20:15:18 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "testsForms.hpp"

// test AForm

// test ShrubberyCreationForm

static void		testHighAFormShrubberyCreationForm(void)
{
    Bureaucrat test("shrubbery creation", 1);
    ShrubberyCreationForm form("shrubbery creation");
    test.signForm(form);
    test.executeForm(form);
};

static void		testLowAFormShrubberyCreationForm(void)
{
    Bureaucrat test("shrubbery creation", 150);
    ShrubberyCreationForm form("shrubbery creation");
    test.signForm(form);
    test.executeForm(form);
};

void    		testShrubberyCreationForm(void)
{
    try {
        std::cout << "testing shrubbery creation high grade" << std::endl;
        testHighAFormShrubberyCreationForm();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << "testing shrubbery creation low grade" << std::endl;
        testLowAFormShrubberyCreationForm();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
};

// test presidential pardon
static void		testHighAFormPresidentialPardonform(void)
{
	Bureaucrat test("presidential pardon", 1);
	PresidentialPardonForm form("presidential pardon");
	test.signForm(form);
	test.executeForm(form);
};
static void		testLowAFormPresidentialPardonform(void)
{
	Bureaucrat test("presidential pardon", 150);
	PresidentialPardonForm form("presidential pardon");
	test.signForm(form);
	test.executeForm(form);
};

void 			testPresidentialPardon(void)
{
	try {
		std::cout << "testing presidential pardon high grade" << std::endl;
		testHighAFormPresidentialPardonform();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "testing presidential pardon low grade" << std::endl;
		testLowAFormPresidentialPardonform();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
};

// test robotomy request

static void		testHighAFormRobotomyRequestForm(void)
{
	Bureaucrat test("robotomy request", 1);
	RobotomyRequestForm form("robotomy request");
	test.signForm(form);
	test.executeForm(form);
};

static void		testLowAFormRobotomyRequestForm(void)
{
	Bureaucrat test("robotomy request", 150);
	RobotomyRequestForm form("robotomy request");
	test.signForm(form);
	test.executeForm(form);
};

void			testRobotomyRequestForm(void)
{
	try {
		std::cout << "testing robotomy request high grade" << std::endl;
		testHighAFormRobotomyRequestForm();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		std::cout << "testing robotomy request low grade" << std::endl;
		testLowAFormRobotomyRequestForm();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
};

// test execute form errors

void		testHighAFormExecuteFormError(void)
{
	std::cout << GREY << "==Test High A Form Execute Form Error : =="
	<< RESET << std::endl;
	std::cout << YELLOW;
	Bureaucrat highA("High A", 1);
	Bureaucrat lowA("Low A", 150);
	ShrubberyCreationForm form("Shrubbery Creation Form");
	try {
		highA.signForm(form);
		highA.executeForm(form);
		lowA.signForm(form);
		lowA.executeForm(form);
	} catch (AForm::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	} catch (AForm::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << RESET << std::endl;
};

// main test

void			allTestsAForms(void)
{
	std::cout << ORANGE << std::endl;
	testShrubberyCreationForm();
	std::cout << RESET;
	std::cout << GREEN << std::endl;
	testPresidentialPardon();
	std::cout << BLUE << std::endl;
	testRobotomyRequestForm();
	std::cout << RESET << std::endl;
	testHighAFormExecuteFormError();
};