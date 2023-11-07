/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:31:14 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/07 11:46:31 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	const std::string	_target;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	AForm();
public:
	// canonical form
	AForm(const std::string& name, const std::string& target, int gradeToSign, int gradeToExecute);
	AForm(const AForm &copy);
	virtual ~AForm();

	AForm& operator=(const AForm &copy);
	// getters
	const std::string&	getName() const;
	const std::string&	getTarget() const;
	bool				getSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	// member functions
	void				beSigned(const Bureaucrat &bureaucrat);
	void				validateExecution(Bureaucrat const &executor) const;
	void				validateRange(int grade);
	virtual	void		execute(Bureaucrat const &executor) const = 0;
	// exceptions
	class GradeTooHighException : public std::exception
	{
		public: virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public: virtual const char* what() const throw();
	};
	class NotSignedException : public std::exception
	{
		public: virtual const char* what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, const AForm &form);