/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:29:36 by madmax42          #+#    #+#             */
/*   Updated: 2023/11/05 10:50:04 by madmax42         ###   ########.fr       */
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
	// canonical form
	AForm();
	AForm(const std::string &name, const std::string &target, const int gradeToSign, const int gradeToExecute);
	AForm(const AForm &copy);
	virtual ~AForm();

	AForm	&operator=(const AForm &copy);

	// getters
	const std::string	&getName() const;
	const std::string	&getTarget() const;
	bool				getSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	// methods functions
	void				validateRange(int grade);
	void				validateExecution(const Bureaucrat &executor) const;
	void				beSigned(const Bureaucrat &bureaucrat);
	virtual void		execute(const Bureaucrat &executor) const = 0;
	// exceptions
	class GradeTooHighException : public std::exception
	{
		public: const char	*what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public: const char	*what() const throw();
	};
	class NotSignedException : public std::exception
	{
		public: const char	*what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, const AForm &aForm);