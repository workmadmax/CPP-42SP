/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouglas <mdouglas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:38:43 by mdouglas          #+#    #+#             */
/*   Updated: 2023/11/16 10:18:16 by mdouglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>


template <typename T>
class Array
{
private:
		unsigned int	_size;
		T				*_array;
public:
		Array();
		Array(unsigned int n);
		Array(const Array	&other);
		~Array();

		Array<T>		&operator=(const Array	&other);
		T				&operator[](size_t idx);
		const T			&operator[](size_t idx) const;
		unsigned int	size() const;
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &array);

// implementação dos templete

template <typename T>
Array<T>::Array() : _size(0), _array(NULL)
{
	try {
		_array = new T[size]();
	} catch (const std::bad_alloc &e) {
		throw ;
	}
};

template <typename T>
Array<T>::Array(unsigned int n) : _size(0), _array(NULL)
{
	try {
		_array = new T[n]();
	} catch (const std::bad_alloc &e) {
		throw ;
	}
	_size = n;
};

template <typename T>
Array<T>::Array(const Array	&other) : _size(0), _array(NULL)
{
	try {
		_array = new T[other.size()]();
	} catch (const std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
	}
	_size = other.size();
	for (size_t i = 0; i < _size; i++)
		_array[i] = other._array[i];
};

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
	_array = NULL;
	_size = 0;
};

// operator overload

template <typename T>
Array<T> &Array<T>::operator=(const Array &other) {
	if (this == &other)
		return (*this);
	T *tmp = NULL;
	try {
		tmp = new T[other._size]();
	} catch (const std::bad_alloc &e) {
		std::cerr << e.what() << std::endl;
	}
	delete[] _array;
	_array = tmp;
	_size = other._size;
	for (size_t i = 0; i < _size; i++)
		_array[i] = other._array[i];
	return (*this);
};

template <typename T>
const T &Array<T>::operator[](size_t idx) const {
	if (size() <= idx || !_array)
		throw std::out_of_range("Error: Index out of range ");
	return (_array[idx]);
};

template <typename T>
T &Array<T>::operator[](size_t idx) {
	if (size() <= idx || !_array)
		throw std::out_of_range("Error: Index out of range ");
	return (_array[idx]);
};

template <typename T>
unsigned int Array<T>::size() const {
	return (_size);
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &array) {
	out << "[";
	for (size_t i = 0; i < array.size(); i++) {
		out << array[i];
		if (i < array.size() - 1)
			out << ", ";
	}
	out << "]";
	return (out);
};