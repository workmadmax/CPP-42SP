/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:43:56 by madmax42          #+#    #+#             */
/*   Updated: 2023/11/01 17:49:47 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

#include "Form.hpp"

#define high 1
#define low 150

class Form;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

public:
	// canonical form
	Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();

	Bureaucrat	&operator=(const Bureaucrat &copy);

	// getters
	std::string	getName() const;
	int			getGrade() const;

	// methods
	void		incrementGrade();
	void		decrementGrade();
	void		signForm(Form &form);

	// exceptions
	class GradeTooHighException : public std::exception
	{
		public: const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public: const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
