/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:03:18 by madmax42          #+#    #+#             */
/*   Updated: 2023/11/06 19:45:42 by mdouglas         ###   ########.fr       */
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
public:
	AForm();
	AForm(const AForm &copy);
	AForm(const std::string &name, const std::string &target, int gradeToSign, int gradeToExecute);
	virtual ~AForm();

	AForm				&operator=(const AForm &copy);
	// getters
	std::string			getName() const;
	std::string			getTarget() const;
	bool				getSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	// methods functions
	void				validateRange(int grade);
	void				beSigned(const Bureaucrat &bureaucrat);
	void				validateExecution(const Bureaucrat &executor) const;
	virtual void		execute(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		public: const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public: const char *what() const throw();
	};
	
	class NotSignedException : public std::exception
	{
		public: const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, const AForm &form);