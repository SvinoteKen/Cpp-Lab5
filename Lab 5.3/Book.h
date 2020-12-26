#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Book
{
public:
	Book(std::string name, std::string author, int year);
	std::string getName() const;
	std::string getAuthor() const;
	int getYear() const;
	static std::vector<int> toYears(std::vector<Book*> books);
private:
	std::string name_;
	std::string author_;
	int year_;
};

class BookSorter {
public:
	BookSorter(int n);
	bool operator()(Book* b1, Book* b2);
private:
	int n_;
};

class BookFinder
{
public:
	BookFinder(int first, int last);
	bool operator()(Book* book);
private:
	int first_;
	int last_;
};
