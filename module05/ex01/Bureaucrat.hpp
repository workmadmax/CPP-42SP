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
#include <stdexcept>
#include <climits>

#include "Form.hpp"

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define ORANGE "\033[0;38;5;208m"
# define GREY "\033[0;38;5;246m"
# define RESET "\033[0m"

class Form;

class Bureaucrat
{
private:
	const std::string			_name;
	int                 		_grade;
public:
	// canonical form
	Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();

	Bureaucrat			&operator=(const Bureaucrat &copy);
	// getters
	std::string const	getName() const;
	int					getGrade() const;
	// methods
	void				incrementGrade();
	void				decrementGrade();
	void				signForm(Form &form);
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

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);
