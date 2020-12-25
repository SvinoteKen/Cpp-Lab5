/*#include "DataManager.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
template <class T>
DataManager<T>::DataManager() {
	N = 0;
	arr = new T[64];
}
template <class T>
DataManager<T>::~DataManager() {
	delete[] arr;
}
template <class T>
void DataManager<T>::push(T elem) {
	if (N == 0) {
		arr[0] = elem;
		N++;
	}
	else {
		for (int i = N-1; i > -1; i--) {
			if (N < 64) {
				arr[i + 1] = arr[i];
			}
			else
			{
				std::ofstream out;
				out.open("dump.txt", std::ios::app);
				for (int i = 0; i < N; i++) {
					out << arr[i] << std::endl;
				}
				out.close();
				N = 0;
			}
		}
		arr[0] = elem;
		N++;
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
	std::copy(arr, arr + N, std::ostream_iterator<T>(std::cout, " "));
}
template<class T>
T DataManager<T>::peek() {
	if (N % 2 == 0) return 0;
	return arr[N / 2];
}
template<class T>
T DataManager<T>::pop() {
		if (N != 0) {
			if (N % 2 == 0) {
				T temp = arr[N / 2 - 1];
				for (int i = N / 2; i < N; i++) {
					arr[i - 1] = arr[i];
				}
				N--;
				if (N == 0) {
					readFromFile();
				}
				return temp;
			}
			else
			{
				T temp = arr[N / 2];
				for (int i = N / 2 + 1; i < N; i++) {
					arr[i - 1] = arr[i];
				}
				N--;
				if (N == 0) {
					readFromFile();
				}
				return temp;
			}
		}
		else { std::cout << "Vector is empty" << std::endl; }
}
template<class T>
void DataManager<T>::readFromFile() {
		std::ifstream in;
		std::ofstream out;
		std::vector<T> tempVector;
		in.open("dump.dat", std::ios::app);
		while (in.peek() != EOF) {
			T temp;
			in >> temp;
			tempVector.push_back(temp);
		}
		if (tempVector.size() > 64) {
			for (int i = 0; i < 64; i++) {
				arr[i] = tempVector[i];
			}
			out.open("dump.dat", std::ios::app);
			for (int i = 64; i < tempVector.size(); i++) {
				out << tempVector[i] << std::endl;
			}
			out.close();
			tempVector.clear();
		}
		else {
			for (int i = 0; i < tempVector.size(); i++) {
				arr[i] = tempVector[i];
			}
			tempVector.clear();
		}
		in.close();
		in.open("dump.dat", std::ios::out | std::ios::trunc);
		in.close();
}

//---------------CHAR---------------------
DataManager<char>::DataManager() {
	N = 0;
	arr = new char[64];
}
void DataManager<char>::push(char elem) {
	if (elem == '.' || elem == '-' || elem == ',' || elem == '?' || elem == '!' || elem == ';' || elem == ' ' || elem == ':' || elem == '/' || elem == '\\') {
		elem = '_';
	}
	if (N == 0) {
		arr[0] = elem;
		N++;
	}
	else {
		for (int i = N - 1; i >= 0; i--) {
			if (N < 64) {
				arr[i + 1] = arr[i];
			}
			else
			{
				std::ofstream out;
				out.open("dump.dat", std::ios::app);
				for (int i = 0; i < N; i++) {
					out << arr[i] << std::endl;
				}
				out.close();
				N = 0;
			}
		}
		arr[0] = elem;
		N++;
	}
}
char DataManager<char>::popUpper() {
	if (N != 0) {
		if (N % 2 == 0) {
			char temp = arr[N / 2 - 1];
			for (int i = N / 2; i < N; i++) {
				arr[i - 1] = arr[i];
			}
			N--;
			readFromFile();
			return toupper(temp);
		}
		else
		{
			char temp = arr[N / 2];
			for (int i = N / 2 + 1; i < N; i++) {
				arr[i - 1] = arr[i];
			}
			N--;
			readFromFile();
			return toupper(temp);
		}
	}
}
char DataManager<char>::popLower() {
	if (N != 0) {
		if (N % 2 == 0) {
			char temp = arr[N / 2 - 1];
			for (int i = N / 2; i < N; i++) {
				arr[i - 1] = arr[i];
			}
			N--;
			readFromFile();
			return tolower(temp);
		}
		else
		{
			char temp = arr[N / 2];
			for (int i = N / 2 + 1; i < N; i++) {
				arr[i - 1] = arr[i];
			}
			N--;
			readFromFile();
			return tolower(temp);
		}
	}
}
void DataManager<char>::readFromFile() {
	std::ifstream in;
	std::ofstream out;
	std::vector<char> tempVector;
	in.open("dump.dat", std::ios::app);
	while (in.peek() != EOF) {
		char temp;
		in >> temp;
		tempVector.push_back(temp);
	}
	if (tempVector.size() > 64) {
		for (int i = 0; i < 64; i++) {
			arr[i] = tempVector[i];
		}
		out.open("dump.dat", std::ios::app);
		for (int i = 64; i < tempVector.size(); i++) {
			out << tempVector[i] << std::endl;
		}
		out.close();
		tempVector.clear();
	}
	else {
		for (int i = 0; i < tempVector.size(); i++) {
			arr[i] = tempVector[i];
		}
		tempVector.clear();
	}
	in.close();
	in.open("dump.dat", std::ios::out | std::ios::trunc);
	in.close();
}
void DataManager<char>::print() {
	std::copy(arr, arr + N, std::ostream_iterator<char>(std::cout, " "));
}*/
