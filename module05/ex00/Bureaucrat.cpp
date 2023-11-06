/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:31:52 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/31 16:19:00 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << GREEN << "Default constructor called" << std::endl << RESET;
};

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << GREEN << "Copy constructor called" << RESET << std::endl;
};

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << GREEN << "Parametric constructor called" << RESET << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
};

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Destructor called" << RESET << std::endl;
};

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << GREEN << "Assignation operator called" << GREEN << std::endl;
	if (this != &copy)
		this->_grade = copy._grade;
	return (*this);
};

std::string const	Bureaucrat::getName() const
{
	return (this->_name);
};

int					Bureaucrat::getGrade() const
{
	return (this->_grade);
};

void				Bureaucrat::incrementGrade()
{
	if (this->_grade < 150)
		this->_grade++;
	else
		throw Bureaucrat::GradeTooHighException();
};

void				Bureaucrat::decrementGrade()
{
	if (this->_grade > 1)
		this->_grade--;
	else
		throw Bureaucrat::GradeTooLowException();
};

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    static std::string message = std::string(ORANGE) + "Grade too high" + RESET;
    return (message.c_str());
};

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    static std::string message = std::string(ORANGE) + "Grade too low" + RESET;
    return (message.c_str());
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << GREEN << bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade() << RESET  << std::endl;
	return (out);
};

