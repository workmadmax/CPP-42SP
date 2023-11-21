/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:59:06 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/21 16:18:47 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"

void	testPDF ( void )
{
	MutantStack<int> mstack; // mutantstack of int created
	mstack.push(5); // 5 added to the stack
	mstack.push(17); // 17 added to the stack
	std::cout << "last value add: " << mstack.top() << std::endl; // 17 printed last element added
	mstack.pop(); // 17 removed from the stack
	std::cout << "size: " << mstack.size() << std::endl; // 1 printed size of the stack
	mstack.push(3); // 3 added to the stack
	mstack.push(5); // 5 added to the stack
	mstack.push(737); // 737 added to the stack
	mstack.push(0); // 0 added to the stack
	MutantStack<int>::iterator it = mstack.begin(); // iterator created at the beginning of the stack
	MutantStack<int>::iterator ite = mstack.end(); // iterator created at the end of the stack
	++it; // iterator moved to the next element
	--it; // iterator moved to the previous element
	while (it != ite) // while the iterator is not at the end of the stack
	{
		std::cout << *it << std::endl; // print the element
		++it; // move the iterator to the next element
	}
	std::stack<int> s(mstack); // stack created from the mutantstack
};

void	testList ( void )
{
	std::cout << "Test List" << std::endl;
	std::list<int> list;
	
	list.push_back(5);
	list.push_back(17);
	list.push_back(20);
	list.push_back(30);

	std::cout << "last value add: " << list.back() << std::endl;
	list.pop_back();
	std::cout << "size: " << list.size() << std::endl;
	std::cout << "first value: " << list.front() << std::endl;
	std::cout << "last value: " << list.back() << std::endl;
	
	list.push_back(3);
	list.push_back(8);
	list.push_back(737);
	list.push_back(0);

	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();

	std::cout << "stack print : " << *it << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	return ;
}

int main ( void )
{
	//testPDF();
	testList();
	
	return (0);
}