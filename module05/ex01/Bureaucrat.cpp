/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:05:45 by madmax42          #+#    #+#             */
/*   Updated: 2023/11/08 15:22:37 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// canonical form
Bureaucrat::Bureaucrat() : _name("bureaucrat"), _grade(150)
{
	std::cout << GREEN << "Bureaucrat default constructor called" << RESET << std::endl;
};

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << GREEN << "Bureaucrat constructor called" << RESET << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
};

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << GREEN << "Bureaucrat copy constructor called" << GREEN << std::endl;
};

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat destructor called" << RESET << std::endl;
};

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << GREEN << "Bureaucrat assignation operator called" << RESET << std::endl;
	if (this == &copy)
		return (*this);
	this->_grade = copy._grade;
	return (*this);
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

void		Bureaucrat::signForm(Form &form)
{
	try {
		form.beSigned(*this);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
};

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    static std::string message = std::string(ORANGE) + "Exception: Grade too high!" + RESET;
    return (message.c_str());
};

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    static std::string message = std::string(ORANGE) + "Exception: Grade too low!" + RESET;
    return (message.c_str());
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << GREEN << bureaucrat.getName()
		<< ", bureaucrat grade "
		<< bureaucrat.getGrade()
		<< RESET << std::endl;
	return (out);
};

// Path: module05/ex01/Form.cpp