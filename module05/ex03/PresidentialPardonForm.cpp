/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:57:18 by madmax42          #+#    #+#             */
/*   Updated: 2023/11/05 09:59:14 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", "none", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
	AForm("PresidentialPardonForm", target, 25, 5)
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
		std::cout << "Form: " << this->getName() << " is not signed" << std::endl;
		throw AForm::NotSignedException();
	} else if (this->getGradeToExecute() < executor.getGrade()) {
		std::cout << "The form can't be executed because the bureaucrat's grade is too low" << std::endl;
		throw AForm::GradeTooLowException();
	} else {
		std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
	}
};