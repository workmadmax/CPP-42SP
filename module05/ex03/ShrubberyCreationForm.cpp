/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:40:49 by madmax42          #+#    #+#             */
/*   Updated: 2023/11/05 09:52:08 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", "none", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
	AForm("ShrubberyCreationForm", target, 145, 137)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) :
	AForm(copy.getName(), copy.getTarget(), copy.getGradeToSign(), copy.getGradeToExecute())
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
};

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
};

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	if (this != &copy)
	{
		AForm::operator=(copy);
	}
	return (*this);
};

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned()) {
		std::cout << "Form: " << this->getName() << " is not signed" << std::endl;
		throw AForm::NotSignedException();
	} else if (this->getGradeToExecute() < executor.getGrade()) {
		std::cout << "The form can't be executed because the bureaucrat's grade is too low" << std::endl;
		throw AForm::GradeTooLowException();
	} else {
		std::ofstream out;
		out.open((this->getTarget() + "_shrubbery").c_str(), std::ofstream::in | std::ofstream::trunc);
		
		out << "      /\\      " << std::endl;
		out << "     /\\*\\     " << std::endl;
		out << "    /\\O\\*\\    " << std::endl;
		out << "   /*/\\/\\/\\   " << std::endl;
		out << "  /\\O\\/\\*\\/\\  " << std::endl;
		out << " /\\*\\/\\*\\/\\/\\ " << std::endl;
		out << "/\\O\\/\\/*/\\/O/\\" << std::endl;
		out << "      ||      " << std::endl;
		out << "      ||      " << std::endl;
		out << "      ||      " << std::endl;
		out << std::endl;
	}
};
