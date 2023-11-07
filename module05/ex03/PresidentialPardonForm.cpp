/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:02:26 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/07 11:02:51 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", "none", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", target, 25, 5)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
	: AForm(copy.getName(), copy.getTarget(), copy.getGradeToSign(), copy.getGradeToExecute())
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
};

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
};

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
	if (this != &copy)
	{
		AForm::operator=(copy);
	}
	return (*this);
};

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
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
		std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
};