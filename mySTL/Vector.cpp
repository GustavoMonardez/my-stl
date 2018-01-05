#pragma once

#include "Vector.h"
#include <iostream>

/*****Private functions*****/
template <typename T> 
void Vector<T>::increaseCapacity(size_t new_capacity) {
	//Reallocate
	T *temp = new T[new_capacity];
	//Copy old values if any
	for (size_t i = 0; i < sz; ++i)
		temp[i] = inner_array[i];
	cap = new_capacity;
	delete[] inner_array;
	inner_array = temp;
}
template <typename T>
void Vector<T>::cleanup() {
	delete[] inner_array;
	sz = 0;
	cap = 0;
}

/*****Constructors/Destructor/Assignment*****/
template <typename T>
Vector<T>::Vector():sz(0),cap(0),inner_array(new T[cap]){
	std::cout << "default constructor\n";
}
template <typename T>
Vector<T>::Vector(size_t new_size, const T& val) : sz(new_size),cap(new_size), inner_array(new T[cap]) {
	std::cout << "paremeterized constructor\n";
	for (size_t i = 0; i < cap; ++i)
		inner_array[i] = val;
}
template <typename T>
Vector<T>::~Vector(){
	std::cout << "destructor\n";
	cleanup();
}
template <typename T>
Vector<T>::Vector(const Vector<T>& other):sz(other.sz),cap(other.cap),inner_array(new T[cap]) {
	std::cout << "copy constructor\n";
	for (size_t i = 0; i < sz; ++i)
		inner_array[i] = other.inner_array[i];
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	std::cout << "assignment operator\n";
	if (this != &other) {
		cleanup();
		sz = other.sz;
		cap = other.cap;
		inner_array = new T[cap];
		for (size_t i = 0; i < sz; ++i)
			inner_array[i] = other.inner_array[i];
	}
	return *this;
}
template <typename T>
Vector<T>::Vector(Vector<T>&& other):sz(0),cap(0),inner_array(other.inner_array) {
	std::cout << "move constructor\n";
	other.cleanup();
}
template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) {
	std::cout << "move assignment operator\n";
	if (this != &other) {
		//cleanup();
		sz = other.sz;
		cap = other.cap;
		inner_array = new T[cap];
		//inner_array = other.inner_array;
		//other.inner_array = nullptr;
		//other.cleanup();
	}
	return *this;
}

/*****Iterators*****/
template <typename T>
typename  Vector<T>::iterator Vector<T>::begin() {
	return iterator(inner_array);
}
template <typename T>
typename  Vector<T>::iterator Vector<T>::end() {
	return iterator(inner_array+sz);
}
template <typename T>
typename  Vector<T>::constIterator Vector<T>::cbegin() {
	return constIterator(inner_array);
}
template <typename T>
typename  Vector<T>::constIterator Vector<T>::cend() {
	return constIterator(inner_array + sz);
}
template <typename T>
typename  Vector<T>::reverseIterator Vector<T>::rbegin() {
	return reverseIterator(inner_array + sz-1);
}
template <typename T>
typename  Vector<T>::reverseIterator Vector<T>::rend() {
	return reverseIterator(inner_array - 1);
}
template <typename T>
typename  Vector<T>::reverseConstIterator Vector<T>::crbegin() {
	return reverseConstIterator(inner_array + sz - 1);
}
template <typename T>
typename  Vector<T>::reverseConstIterator Vector<T>::crend() {
	return reverseConstIterator(inner_array - 1);
}

/*****Capacity*****/
template <typename T>
size_t Vector<T>::size() const {
	return sz;
}
template <typename T>
void Vector<T>::resize(size_t new_size, T val) {
	//if capacity less than new_size, reallocate
	if (cap < new_size) {
		//Increase capacity and copy old values
		increaseCapacity(new_size);
		//Fill the rest with val passed in
		for (size_t i = sz; i < new_size; ++i)
			inner_array[i] = val;		
		sz = new_size;
	}
	//Enough capacity with empty array
	else if (sz == 0) {
		for (size_t i = 0; i < new_size; ++i)
			inner_array[i] = val;
		sz = new_size;
	}
	//Enough capacity with prev values
	else {
		//expand
		if (new_size > sz) {
			for (size_t i = sz; i < new_size; ++i)
				inner_array[i] = val;
		}
	}
}
template <typename T>
size_t Vector<T>::capacity() const {
	return cap;
}
template <typename T>
bool Vector<T>::empty() const {
	return sz == 0;
}
template <typename T>
void Vector<T>::reserve(size_t new_capcity) {
	//empty array with or without reserved capacity
	if (cap == 0 || sz == 0) {
		inner_array = new T[new_capcity];
	}
	//non-empty
	else {
		//expand
		if (new_capcity > cap) {
			T *temp = new T[new_capcity];
			for (size_t i = 0; i < sz; ++i)
				temp[i] = inner_array[i];
			delete[] inner_array;
			inner_array = temp;
		}
	}
	cap = new_capcity;
}
template <typename T>
void Vector<T>::shrinkToFit() {
	if (cap > sz) {
		T *temp = new T[sz];
		for (size_t i = 0; i < sz; ++i)
			temp[i] = inner_array[i];
		delete[] inner_array;
		inner_array = temp;
		cap = sz;
	}
}

/*****Element access*****/
template <typename T>
T& Vector<T>::operator[](size_t index) {
	if (index >= sz || index < 0)
		throw std::out_of_range("Index out of range");
	return inner_array[index];
}
template <typename T>
const T& Vector<T>::operator[](size_t index) const {
	if (index >= sz || index < 0)
		throw std::out_of_range("Index out of range");
	return inner_array[index];
}
template <typename T>
T& Vector<T>::at(size_t index) {
	if (index >= sz || index < 0)
		throw std::out_of_range("Index out of range");
	return inner_array[index];
}
template <typename T>
const T& Vector<T>::at(size_t index) const {
	if (index >= sz || index < 0)
		throw std::out_of_range("Index out of range");
	return inner_array[index];
}
template <typename T>
T& Vector<T>::front() {
	if(sz==0)
		throw std::out_of_range("Index out of range");
	return inner_array[0];
}
template <typename T>
const T& Vector<T>::front() const {
	if (sz == 0)
		throw std::out_of_range("Index out of range");
	return inner_array[0];
}
template <typename T>
T& Vector<T>::back() {
	if (sz == 0)
		throw std::out_of_range("Index out of range");
	return inner_array[sz-1];
}
template <typename T>
const T& Vector<T>::back() const {
	if (sz == 0)
		throw std::out_of_range("Index out of range");
	return inner_array[sz-1];
}

/*****Modifiers*****/
template <typename T>
void Vector<T>::assign(typename iterator first,typename iterator last) {
	//TODO after iterator class
}
template <typename T>
void Vector<T>::assign(size_t n, const T& val) {
	sz = n;
	delete[] inner_array;
	inner_array = new T[sz];
	for (size_t i = 0; i < sz; ++i)
		inner_array[i] = val;

	if (cap < sz)
		cap = sz;
}
template <typename T>
void Vector<T>::pushBack(const T& data) {
	if(cap==0)
		increaseCapacity(++cap);
	if (sz >= cap) 
		increaseCapacity(cap * 2);

	inner_array[sz] = data;
	++sz;
}
template <typename T>
void Vector<T>::popBack() {
	if (sz < 1)
		throw std::out_of_range("Out of range exception:popBack()");
	--sz;
}
template <typename T>
void Vector<T>::insert(typename iterator before_pos, const T& val) {
	//TODO after Iterator class
}
template <typename T>
void Vector<T>::insert(typename iterator before_pos, size_t n, const T& val) {
	//TODO after Iterator class
}
template <typename T>
void Vector<T>::insert(typename iterator before_pos, typename iterator start, typename iterator end) {
	//TODO after Iterator class
}
template <typename T>
typename Vector<T>::iterator Vector<T>::erase(typename iterator pos) {
	//TODO after Iterator class
}
template <typename T>
typename Vector<T>::iterator Vector<T>::erase(typename iterator start, typename iterator end) {
	//TODO after Iterator class
}
template <typename T>
void Vector<T>::swap(Vector& other) {
	//TODO find more efficient approach
	Vector<T> temp = other;
	other = *this;
	*this = temp;
}
template <typename T>
void Vector<T>::clear() {
	for (size_t i = 0; i < sz; ++i)
		inner_array[i] = T();
	sz = 0;
}