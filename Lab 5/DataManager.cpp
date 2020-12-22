#include "DataManager.h"
#include <iostream>
#include <string>
#include <fstream>
template <class T>
DataManager<T>::DataManager() {
	max_size_ = 64;
	count_ = 0;
	mas = new T[64];
}
template <class T>
DataManager<T>::~DataManager() {
	delete[] mas;
}
template <class T>
void DataManager<T>::push(T elem) {
	if (count_ == 0) {
		mas[0] = elem;
		count_++;
	}
	else {
		for (int i = count_ - 1; i >= 0; i--) {
			if (count_ < max_size_) {
				mas[i + 1] = mas[i];
			}
			else
			{
				std::ofstream out;
				out.open("dump.dat", std::ios::app);
				for (int i = 0; i < count_; i++) {
					out << mas[i] << std::endl;
				}
				out.close();
				count_ = 0;
			}
		}
		mas[0] = elem;
		count_++;
	}
}
template <class T>
void DataManager<T>::push(T elems[], size_t n) {
	for (int i = 0; i < n; i++) {
		push(elems[i]);
	}
}
template<class T>
void DataManager<T>::print() {
	std::copy(mas, mas + count_, std::ostream_iterator<T>(std::cout, " "))
}
template<class T>
T DataManager<T>::peek() {

}
template<class T>
T DataManager<T>::pop() {

}