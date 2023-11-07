/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:06:08 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/07 11:49:41 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
	typedef struct s_forms {
		std::string name;
		AForm		*forms;
	} t_forms;
public:
	Intern();
	Intern(const Intern &copy);
	~Intern();

	Intern& operator=(const Intern &copy);
	
	AForm*	makeForm(std::string name, std::string target);
	
	class FormNotFoundException : public std::exception
	{
		public: virtual const char* what() const throw();
	};
};