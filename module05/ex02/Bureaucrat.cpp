/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:38:01 by madmax42          #+#    #+#             */
/*   Updated: 2023/11/05 10:02:50 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;	
};

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < high)
		throw Bureaucrat::GradeTooHighException();
	if (grade > low)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
};

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
};

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (copy._grade < high)
		throw Bureaucrat::GradeTooHighException();
	if (copy._grade > low)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = copy._grade;
	return (*this);
};

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
};

// getters

std::string	Bureaucrat::getName() const
{
	return (this->_name);
};

int			Bureaucrat::getGrade() const
{
	return (this->_grade);
};

// methods functions

void		Bureaucrat::incrementGrade()
{
	this->_grade--;
	if (this->_grade < high)
		throw Bureaucrat::GradeTooHighException();
};

void		Bureaucrat::decrementGrade()
{
	this->_grade++;
	if (this->_grade > low)
		throw Bureaucrat::GradeTooLowException();
};

void		Bureaucrat::signForm(AForm &form)
{
	form.beSigned(*this);
};

void		Bureaucrat::executeForm(const AForm &form)
{
	try {
		form.validateExecution(*this);
	} catch (std::exception &e) {
		std::cout << this->_name << " cannot execute " << form.getName()
			<< " because " << e.what() << std::endl;
		return ;
	}
};

// exceptions

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
};

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
};

// overload

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
};