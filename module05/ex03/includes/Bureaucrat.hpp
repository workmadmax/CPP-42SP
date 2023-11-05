/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:36:20 by madmax42          #+#    #+#             */
/*   Updated: 2023/11/05 09:37:43 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	// canonical form
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	virtual ~Bureaucrat();

	Bureaucrat	&operator=(const Bureaucrat &copy);

	// getters
	const std::string	&getName() const;
	int					getGrade() const;
	// methods functions
	void				incrementGrade();
	void				decrementGrade();
	void				signForm(AForm &form);
	void				executeForm(const AForm &form);
	// exceptions
	class GradeTooHighException : public std::exception
	{
		public: const char	*what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public: const char	*what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat);