/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:42:10 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/10 11:48:46 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

FileReplacer::FileReplacer(
	const std::string& filename, const std::string& s1, const std::string& s2
){
	_filename = filename;
	_s1 = s1;
	_s2 = s2;
	_error = false;
	_errorMessage = "";
}

bool FileReplacer::replace()
{
	std::ifstream inputFile(_filename.c_str());
	if (!inputFile) {
		_error = true;
		_errorMessage = "Error: could not open file " + _filename;
		return (false);
	}
	
	std::ofstream outputFile((_filename + ".replace").c_str());
	if (!outputFile) {
		_error = true;
		_errorMessage = "Error: could not open file " + _filename + ".replace";
		inputFile.close();
		return (false);
	}

	std::string line;
	while (std::getline(inputFile, line)) {
		size_t found = line.find(_s1);
		while (found != std::string::npos) {
			line.replace(found, _s1.length(), _s2);
			found = line.find(_s1, found + _s2.length());
		}
		outputFile << line << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return (true);
}

bool FileReplacer::hasError() const
{
	return (_error);
}

std::string FileReplacer::getErrorMessage() const
{
	return (_errorMessage);
}