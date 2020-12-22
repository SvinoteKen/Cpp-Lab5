#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
template <class T>
#pragma once
class DataManager
{
public:
	DataManager();
	~DataManager();
	void push(T elem);
	void push(T elems[], size_t n);
	void print();
	T peek();
	T pop();
	void chekEmpty();
private:
	T* mas;
	int max_size_;
	int count_;
	std::vector<T> buffer_vector;
};

template<>
class DataManager<char> {
public:
	DataManager();
	void push(char elem);
	char popUpper();
	char popLower();
	void chekEmpty();
	void print();
private:
	char* mas;
	int max_size_;
	int count_;
	std::vector<char> buffer_vector;
};

