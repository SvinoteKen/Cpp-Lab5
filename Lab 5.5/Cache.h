#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "CacheOverflowException.h"
#include "Symbols.h"
template <class T>
class Cache
{
public:
	Cache() {
		vector.reserve(100);
	}
	void put(T elem) {
		vector.push_back(elem);
	}
	void operator+=(T elem) {
		vector.push_back(elem);
	}
	bool contains(T elem) {
		return std::find(vector.begin(), vector.end(), elem) != vector.end();
	}
private:
	std::vector<T> vector;
};
template<>
class Cache<std::string> {
public:
	Cache() {
		vector.reserve(100);
	}
	void add(std::string elem) {
		if (vector.size() < 100) {
			vector.push_back(elem);
		}
		else
		{
			throw new CacheOverflowException;
		}
	}
	void operator+=(std::string elem) {
		vector.push_back(elem);
	}
	bool contains(std::string elem) {
		Symbols comparer(elem);
		return std::find_if(vector.begin(), vector.end(), comparer) != vector.end();
	}
private:
	std::vector<std::string> vector;
};