/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madmax42 <madmax42@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:55:33 by madmax42          #+#    #+#             */
/*   Updated: 2023/10/09 17:06:24 by madmax42         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return (1);
	}
	// extract arguments
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	
	// open file
	std::ifstream inputFile(filename.c_str());
	if (!inputFile)
	{
		std::cerr << "Error opening file" << filename << std::endl;
		return (1);
	}
	// read file content and store it in a string
	std::string content;
	std::string line;

	while (std::getline(inputFile, line))
		content += line + "\n";
	
		content += line + "\n";
	// replace all occurrences of s1 with s2 in the string
	size_t pos = 0;
	while ((pos = content.find(s1, pos)) != std::string::npos)
	{
		content.replace(pos, s1.length(), s2);
		pos += s2.length();
	}
	// create a new file with .replace extension
	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile)
	{
		std::cerr << "Error creating file" << filename << ".replace" << std::endl;
		return (1);
	}
	// write the new string in the new file
	outputFile << content;

	// handle error and exeptions
	if (inputFile.bad())
	{
		std::cerr << "Error reading file" << filename << std::endl;
		return (1);
	}
	if (outputFile.bad())
	{
		std::cerr << "Error writing file" << filename << ".replace" << std::endl;
		return (1);
	}
	// close files
	inputFile.close();
	outputFile.close();
	return (0);
}