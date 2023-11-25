/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:59:06 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/23 17:01:56 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cassert>
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

void	testMutantStackList ( void )
{
	MutantStack<int, std::list<int> > mstack; // mutantstack of int created
	
	mstack.push(5); // 5 added to the stack
	mstack.push(17); // 17 added to the stack
	std::cout << "last value add: " << mstack.top() << std::endl; // 17 printed last element added
	mstack.pop(); // 17 removed from the stack
	std::cout << "size: " << mstack.size() << std::endl; // 1 printed size of the stack
	mstack.push(3); // 3 added to the stack
	mstack.push(5); // 5 added to the stack
	mstack.push(737); // 737 added to the stack
	mstack.push(0); // 0 added to the stack
	MutantStack<int, std::list<int> >::iterator it = mstack.begin(); // iterator created at the beginning of the stack
	MutantStack<int, std::list<int> >::iterator ite = mstack.end(); // iterator created at the end of the stack
	++it; // iterator moved to the next element
	--it; // iterator moved to the previous element
	while (it != ite) // while the iterator is not at the end of the stack
	{
		std::cout << *it << std::endl; // print the element
		++it; // move the iterator to the next element
	}
	
};


void testEmptyStackIteration()
{
    std::cout << "Testando iteração em uma pilha vazia..." << std::endl;
    MutantStack<int> emptyStack;

    // Tentar acessar iteradores em uma pilha vazia deve lançar uma exceção
    try {
        MutantStack<int>::iterator it = emptyStack.begin();
        MutantStack<int>::iterator ite = emptyStack.end();

        std::cout << "Iterando em uma pilha vazia:" << std::endl;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }
    } catch (std::exception &e) {
        std::cout << "Erro ao iterar em uma pilha vazia: " << e.what() << std::endl;
    }
}

void testSizeOverload()
{
    std::cout << "Testando o overload do tamanho..." << std::endl;
    MutantStack<int> mstack;

    // Verificar se o tamanho inicial é 0
    assert(mstack.size() == 0);
    // Adicionar alguns elementos à pilha
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    // Verificar se o tamanho da pilha é igual ao número de elementos adicionados
    assert(mstack.size() == 3);
    // Remover alguns elementos da pilha
    mstack.pop();
    mstack.pop();
    // Verificar se o tamanho da pilha é igual ao número de elementos restantes
    assert(mstack.size() == 1);
    std::cout << "Teste do overload do tamanho passou." << std::endl;
}

void	testConstructor()
{
	MutantStack<int> mstack; // mutantstack of int created

	/*Testa se a pilha está vazia após a construção
		se o tamanho da pilha é 0 após a construção */
	assert(mstack.empty() == true); 
	assert(mstack.size() == 0);
	std::cout << "constructor test passed" << std::endl;
}


int main ( void )
{
	testPDF();
	//testConstructor();
	//testEmptyStackIteration();
	//testSizeOverload();

	return (0);
}