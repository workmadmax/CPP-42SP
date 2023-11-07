/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:38:01 by madmax42          #+#    #+#             */
/*   Updated: 2023/11/07 09:17:00 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;	
};

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
};

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
};

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (copy._grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (copy._grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = copy._grade;
	return (*this);
};

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
};

// getters

std::string const	Bureaucrat::getName() const
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
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
};

void		Bureaucrat::decrementGrade()
{
	this->_grade++;
	if (this->_grade > 150)
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
	static std::string message = std::string(ORANGE) + "Grade too high" + std::string(RESET);
	return (message.c_str());
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