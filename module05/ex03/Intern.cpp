/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:10:26 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/07 11:51:32 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
};

Intern::Intern(const Intern &copy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
};

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
};

Intern	&Intern::operator=(const Intern &copy)
{
	std::cout << "Intern assignation operator called" << std::endl;
	if (this != &copy)
	{
		(void)copy;
	}
	return (*this);
};

AForm*	Intern::makeForm(std::string name, std::string target)
{
	static const int sizeForms = 3;
	t_forms forms[sizeForms] = {
		{"robotomy request", new RobotomyRequestForm(target)},
		{"presidential pardon", new PresidentialPardonForm(target)},
		{"shrubbery creation", new ShrubberyCreationForm(target)}
	};
	AForm* ret = NULL;
	for (int i = 0; i < sizeForms; i++) {
		if (forms[i].name == name)
			ret = forms[i].forms;
		else
			delete forms[i].forms;
	}
	if (ret != NULL )
		std::cout << "Intern creates form " << name << std::endl;
	else
		std::cout << "Intern cannot create form " << name << std::endl;
	return (ret);
};

const char* Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found");
};