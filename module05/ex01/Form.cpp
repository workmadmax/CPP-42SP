/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:53:06 by madmax42          #+#    #+#             */
/*   Updated: 2023/11/01 15:24:29 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("form"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
    std::cout << "Form default constructor called" << std::endl;
};

Form::Form(const std::string &name, int gradeToSign, int gratoToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gratoToExecute)
{
    std::cout << "Form constructor called" << std::endl;
    validateRange(gradeToSign);
    validateRange(gratoToExecute);
};

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
};

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
};

Form	&Form::operator=(const Form &copy)
{
	std::cout << "Form assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	_signed = copy._signed;
	return (*this);
};

std::string	Form::getName() const
{
	return (this->_name);
};

bool	Form::getSigned() const
{
	return (this->_signed);
};

int		Form::getGradeToSign() const
{
	return (this->_gradeToSign);
};

int		Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
};

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign) {
		this->_signed = true;
		std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
	}
	else {
		std::cout << bureaucrat.getName() << " cannot sign " << this->_name << " because ";
		throw Form::GradeTooLowException();
	}
};

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Exception: Grade too high");
};

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Exception: Grade too low");
};

void	Form::validateRange(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
};

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.getName() << " is ";
	if (form.getSigned())
		out << "signed";
	else {
		out << "not signed";
		out << " and requires grade " << form.getGradeToSign()
		<< " to be signed and grade " << form.getGradeToExecute()
		<< " to be executed" << std::endl;
	}
		
	return (out);
};