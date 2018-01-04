#pragma once

template<typename T, bool isConst = false> class Iterator;

template <typename T> class Vector{
private:
	size_t sz;
	size_t cap;
	T valueType();
	void cleanup();
public:
	typedef Iterator<T> iterator;
	typedef Iterator<T, true> constIterator;
	/*****Member functions*****/
	Vector();//constructor
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
	iterator rbegin();
	iterator rend();
	constIterator crbegin();
	constIterator crend();

	/*****Capacity*****/
	size_t size() const;
	void resize(size_t new_size, T val = valueType());
	size_t capacity() const;
	bool empty() const;
	void reserve(size_t new_capcity);
	void shrinkToFit();

	/*****Element access*****/
	T& operator[](size_t index);
	const T& operator[](size_t index) const;
	T& at(size_t index);
	const T& at(size_t index) const;
	T& front(size_t index);
	const T& front(size_t index) const;
	T& back(size_t index);
	const T& back(size_t index) const;

	/*****Modifiers*****/
	void assign(Iterator first, Iterator last);
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

