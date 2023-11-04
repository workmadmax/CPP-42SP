/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:05:45 by madmax42          #+#    #+#             */
/*   Updated: 2023/11/01 15:30:42 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("bureaucrat"), _grade(150)
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

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
};

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_grade = copy._grade;
	return (*this);
};

std::string	Bureaucrat::getName() const
{
	return (_name);
};

int			Bureaucrat::getGrade() const
{
	return (_grade);
};

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

void		Bureaucrat::signForm(Form &form)
{
	try {
		form.beSigned(*this);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
};

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Exception: Grade too high");
};

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Exception: Grade too low");
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (out);
};

// Path: module05/ex01/Form.cpp