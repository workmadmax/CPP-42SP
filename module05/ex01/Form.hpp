/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:50:15 by madmax42          #+#    #+#             */
/*   Updated: 2023/11/01 15:29:21 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form 
{
private:
	const std::string			_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;
public:
	// canonical form
	Form();
	Form(const Form &copy);
	Form(const std::string &name, int gradeToSign, int gradeToExecute);
	~Form();

	Form	&operator=(const Form &copy);
	// getters
	std::string	getName() const;
	bool		getSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;
	// methods
	void		validateRange(int grade);
	void		beSigned(const Bureaucrat &bureaucrat);
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

std::ostream	&operator<<(std::ostream &out, const Form &form);