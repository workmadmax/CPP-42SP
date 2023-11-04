/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:14:58 by madmax42          #+#    #+#             */
/*   Updated: 2023/11/01 17:37:23 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("AForm"), _target("none"), _signed(false), _gradeToSign(high), _gradeToExecute(high)
{
	std::cout << "AForm default constructor called" << std::endl;
};

AForm::AForm(const std::string &name, const std::string &target, int gradeToSign, int gradeToExecute) : _name(name), _target(target), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "AForm constructor called" << std::endl;
	validateRange(gradeToSign);
	validateRange(gradeToExecute);
};

AForm::AForm(const AForm &copy) : _name(copy._name), _target(copy._target), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	std::cout << "AForm copy constructor called" << std::endl;
};

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
};

AForm				&AForm::operator=(const AForm &copy)
{
	std::cout << "AForm assignation operator called" << std::endl;
	if (this != &copy)
		_signed = copy._signed;
	return (*this);
};

// getters

std::string			AForm::getName() const
{
	return (this->_name);
};

std::string			AForm::getTarget() const
{
	return (this->_target);
};

bool				AForm::getSigned() const
{
	return (this->_signed);
};

int					AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
};

int					AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
};

// methods functions

void				AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign) {
		this->_signed = true;
		std::cout << bureaucrat.getName() << "has signed " << this->_name << std::endl;
	} else {
		std::cout << bureaucrat.getName() << "cannot sign " << this->_name
			<< " because his grade is too low" << std::endl;
		throw AForm::GradeTooLowException();
	}
};

void				AForm::validateExecution(const Bureaucrat &bureaucrat) const
{
	if (this->_signed == false) {
		std::cout << bureaucrat.getName() << " cannot execute " << this->_name
			<< " because the form is not signed" << std::endl;
		throw AForm::NotSignedException();
	}
	if (bureaucrat.getGrade() > this->_gradeToExecute) {
		std::cout << bureaucrat.getName() << "cannot execute " << this->_name
			<< " because his grade is too low" << std::endl;
		throw AForm::GradeTooLowException();
	}
	std::cout << bureaucrat.getName() << " executes " << this->_name << std::endl;
	this->execute(bureaucrat);
	
};

void				AForm::validateRange(int grade)
{
	if (grade < high) throw Bureaucrat::GradeTooHighException();
	if (grade > low) throw Bureaucrat::GradeTooLowException();
};

const char 			*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
};

const char 			*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
};

const char 			*AForm::NotSignedException::what() const throw()
{
	return ("Form not signed");
};

std::ostream		&operator<<(std::ostream &out, const AForm &form)
{
	out << "AForm " << form.getName()
	<< " is " << (form.getSigned() ? "signed" : "not signed")
	<< " and requires a grade " << form.getGradeToSign()
	<< " to be signed and a grade " << form.getGradeToExecute()
	<< " to be executed" << std::endl;
	return (out);
};

