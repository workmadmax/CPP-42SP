/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsForms.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:27:30 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/06 20:02:00 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


void 			testPresidentialPardon(void);
void    		testShrubberyCreationForm(void);
void			testRobotomyRequestForm(void);
void			allTestsAForms(void);

// test execute form errors

void			testHighAFormExecuteFormError(void);