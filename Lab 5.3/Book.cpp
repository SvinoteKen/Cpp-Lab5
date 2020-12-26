#include "Book.h"
Book::Book(std::string name, std::string author, int year) {
	name_ = name;
	author_ = author;
	year_ = year;
}
std::string Book::getName() const {
	return name_;
}
std::string Book::getAuthor() const {
	return author_;
}
int Book::getYear() const {
	return year_;
}
std::vector<int> Book::toYears(std::vector<Book*>books) {
	std::vector<int> years;
	for (int i = 0; i < books.size(); i++) {
		years.push_back(books[i]->year_);
	}
	return years;
}
//---------------BookSorter-------------
BookSorter::BookSorter(int n) : n_(n) {}
bool BookSorter::operator()(Book* b1, Book* b2) {
	if (n_ == 1)
		return b1->getAuthor() < b2->getAuthor();
	else
		return b1->getName() < b2->getName();
}

//----------------BookFinder-------------------
BookFinder::BookFinder(int first, int last) : first_(first), last_(last) {}
bool BookFinder::operator() (Book* book) {
	return book->getYear() >= first_ && book->getYear() <= last_;
}