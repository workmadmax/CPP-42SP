/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:11:21 by madmax42          #+#    #+#             */
/*   Updated: 2023/11/04 10:13:40 by madmax42         ###   ########.fr       */
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
		std::cout << "The form cannot be executed because its not signed" << std::endl;
		return ;
	}
	else if (this->getGradeToExecute() < executor.getGrade()) {
		std::cout << "The form cannot be executed because the grade of the executor is too low" << std::endl;
		throw AForm::GradeTooLowException();
	}
	else
	{
		std::cout << "* drilling noises *" << std::endl;
		if (rand() % 2)
			std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
		else
			std::cout << this->getTarget() << " has not been robotomized successfully" << std::endl;
	}
};