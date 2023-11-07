/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:21:53 by madmax42          #+#    #+#             */
/*   Updated: 2023/11/07 07:53:18 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", "none", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", target, 145, 137)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
};	

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	: AForm(copy.getName(), copy.getTarget(), copy.getGradeToSign(), copy.getGradeToExecute())
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = copy;
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
		std::cout << "The form cannot be executed because its not signed" << std::endl;
		return ;
	}
	else if (this->getGradeToExecute() < executor.getGrade()) {
		std::cout << "The form cannot be executed because the grade of the executor is too low" << std::endl;
		throw AForm::GradeTooLowException();
	}
	else
	{
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