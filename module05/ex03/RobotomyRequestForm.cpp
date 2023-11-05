/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:53:42 by madmax42          #+#    #+#             */
/*   Updated: 2023/11/05 09:56:49 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", "none", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", target, 72, 45)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy.getName(), copy.getTarget(), copy.getGradeToSign(), copy.getGradeToExecute())
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
};

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
};

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	if (this != &copy)
	{
		AForm::operator=(copy);
	}
	return (*this);
};

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned()) {
		std::cout << "Form: " << this->getName() << " is not signed" << std::endl;
		throw AForm::NotSignedException();
	} else if (this->getGradeToExecute() < executor.getGrade()) {
		std::cout << "The form can't be executed because the bureaucrat's grade is too low" << std::endl;
		throw AForm::GradeTooLowException();
	} else {
		std::cout << "* drilling noises *" << std::endl;
		if (rand() % 2)
			std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
		else
			std::cout << this->getTarget() << " robotomization failed" << std::endl;
	}
};