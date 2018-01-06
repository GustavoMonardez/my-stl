#pragma once
template<bool isConst, typename C, typename N> struct select;
//Constant iterator type
template<typename isConst, typename nonConst>
struct select<true, isConst, nonConst> {
	typedef isConst type;
};
//Non-const iterator type
template<typename isConst, typename nonConst>
struct select<false, isConst, nonConst> {
	typedef nonConst type;
};
//Iterator
template<typename T, bool isConst = false> class Iterator {
public:
	typedef typename select<isConst, const T&, T&>::type reference;
	typedef typename select<isConst, const T*, T*>::type pointer;
	//Constructor/copy/assignment
	Iterator<T, isConst>(pointer current) : current(current) {}
	Iterator<T, isConst>(const Iterator<T, isConst>& other) : current(other.current) {}
	Iterator<T, isConst>& operator=(const Iterator<T, isConst>& other) { current = other.current; return *this; }
	//Operator overloading
	reference operator*() { return *current; }
	pointer operator->() const { return current };
	Iterator<T, isConst>& operator++() { ++current; return *this; }
	Iterator<T, isConst>& operator++(int) { Iterator<T, isConst> temp = *this; ++current; return temp; }
	Iterator<T, isConst>& operator--() { --current; return *this; }
	Iterator<T, isConst>& operator--(int) { Iterator<T, isConst> temp = *this; --current; return temp; }
	Iterator<T, isConst>& operator+(int value) {for(size_t i=0; i < value;++i)++current; return *this; }
	Iterator<T, isConst>& operator-(int value) { for (size_t i = 0; i < value; ++i)--current; return *this; }
	friend bool operator==(const Iterator<T, isConst> &lhs, const Iterator<T, isConst>& rhs) { return lhs.current == rhs.current; }
	friend bool operator!=(const Iterator<T, isConst> &lhs, const Iterator<T, isConst>& rhs) { return lhs.current != rhs.current; }
	friend bool operator>(const Iterator<T, isConst> &lhs, const Iterator<T, isConst>& rhs) { return lhs.current > rhs.current; }
	friend bool operator<(const Iterator<T, isConst> &lhs, const Iterator<T, isConst>& rhs) { return lhs.current < rhs.current; }
private:
	pointer current;
};
//Reverse Iterator
template<typename T, bool isConst = false> class ReverseIterator {
public:
	typedef typename select<isConst, const T&, T&>::type reference;
	typedef typename select<isConst, const T*, T*>::type pointer;
	//Constructor/copy/assignment
	ReverseIterator<T, isConst>(pointer current) : current(current) {}
	ReverseIterator<T, isConst>(const ReverseIterator<T, isConst>& other) : current(other.current) {}
	ReverseIterator<T, isConst>& operator=(const ReverseIterator<T, isConst>& other) { current = other.current; return *this; }
	//Operator overloading
	reference operator*() { return *current; }
	pointer operator->() const { return current };
	ReverseIterator<T, isConst>& operator++() { --current; return *this; }
	ReverseIterator<T, isConst>& operator++(int) { ReverseIterator<T, isConst> temp = *this; --current; return temp; }
	friend bool operator==(const ReverseIterator<T, isConst> &lhs, const ReverseIterator<T, isConst>& rhs) { return lhs.current == rhs.current; }
	friend bool operator!=(const ReverseIterator<T, isConst> &lhs, const ReverseIterator<T, isConst>& rhs) { return lhs.current != rhs.current; }
private:
	pointer current;
};
template <typename T> class Vector{
private:
	size_t sz;
	size_t cap;
	T *inner_array;
	void increaseCapacity(size_t new_capacity);
	void cleanup();
public:
	typedef Iterator<T> iterator;
	typedef Iterator<T, true> constIterator;
	typedef ReverseIterator<T> reverseIterator;
	typedef ReverseIterator<T, true> reverseConstIterator;
	/*****Member functions*****/
	Vector();//default constructor
	Vector(size_t new_size, const T& val=T());//paremeterized constructor
	~Vector();//destructor
	Vector<T>(const Vector<T>& other);//copy constructor
	Vector<T>& operator=(const Vector<T>& other);//assignment operator
	Vector<T>(Vector<T>&& other);//move constructor
	Vector<T>& operator=(Vector<T>&& other);//move assignment operator

	/*****Iterators*****/
	iterator begin();
	iterator end();
	constIterator cbegin();
	constIterator cend();
	reverseIterator rbegin();
	reverseIterator rend();
	reverseConstIterator crbegin();
	reverseConstIterator crend();

	/*****Capacity*****/
	size_t size() const;
	void resize(size_t new_size, T val = T());
	size_t capacity() const;
	bool empty() const;
	void reserve(size_t new_capcity);
	void shrinkToFit();

	/*****Element access*****/
	T& operator[](size_t index);
	const T& operator[](size_t index) const;
	T& at(size_t index);
	const T& at(size_t index) const;
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;

	/*****Modifiers*****/
	void assign(iterator first, iterator last);
	void assign(size_t n, const T& val);
	void pushBack(const T& data);
	void popBack();
	void insert(iterator before_pos, const T& val);//single element
	void insert(iterator before_pos, size_t n, const T& val);//n elements
	void insert(iterator before_pos, iterator start, iterator end);//range
	iterator erase(iterator pos);//single element
	iterator erase(iterator start, iterator end);//range
	void swap(Vector& other);
	void clear();
};
#include "Vector.cpp"
