/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:32:39 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/10 11:49:34 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>


class FileReplacer
{
	public:
		FileReplacer(
			const std::string& filename, const std::string& s1, const std::string& s2
		);
		
		bool	replace();
		bool	hasError() const;
		
		std::string getErrorMessage() const;
	
	private:
		std::string _filename;
		std::string _s1;
		std::string _s2;
		bool		_error;
		std::string _errorMessage;
};