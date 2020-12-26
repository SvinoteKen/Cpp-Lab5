#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "Book.h"
#include <functional>
int main()
{
    /*-------------------3------------------
      ������� ����� ����� Book, � ������� �������� ��������, ����� � ��� ������� �����. �
      ������� ������� ������� ��������� ���� (���������� �). ������������������
      ���������� ���� �� ������ (��������� ����) � �������� (��������� ����).
      ������������������ ����� � ���������: ����� ��� �����, ��� ������� �������
      ��������� � ��������� ���������. ������������ ��������� std::vector � ��������.*/
    setlocale(LC_ALL, "Russian");
    std::vector<Book*> books;
    books.push_back(new Book("����� � ���", "������� �.�.", 2010));
    books.push_back(new Book("���������", "����������� �.�.", 2004));
    books.push_back(new Book("�����", "�������� �.�.", 2010));
    books.push_back(new Book("���� ��������", "������� �.�.", 1999));
    books.push_back(new Book("������������ �������", "�������� �.�.", 2011));
    books.push_back(new Book("���������� �������", "������� �.", 2009));
    books.push_back(new Book("������ �����", "������� �.", 2001));
    books.push_back(new Book("�����", "ø�� �.�.", 2010));
    books.push_back(new Book("����� ������", "������� �.", 1998));
    BookSorter book_sorter(2);
    std::sort(books.begin(), books.end(), book_sorter);
    std::vector<Book*>::iterator i;
    for (i = books.begin(); i != books.end(); ++i)
    {
        std::cout << (*i)->getAuthor() << " \""
            << (*i)->getName() << "\"" << std::endl;
    }
    BookFinder book_finder(2005, 2014);
    std::vector<Book*>::iterator finder = std::find_if(books.begin(), books.end(), book_finder);
    std::cout << "\n����� � ��������� ���� ������� 2005 - 2014:\n\n";
    while (finder != books.end()) {
        std::cout << (*finder)->getAuthor() << "\"" << (*finder)->getName() << "\"" << std::endl;
        finder = std::find_if(++finder, books.end(), book_finder);
    }

      /*-----------------------4--------------------
      ���������� � ������� �� ������� ���������� ���� ���� ����� 2009 ����, ���������
      ������ ����������� ��������� � �������� STL (���c�����: std::count_if,
      std::greater<>, std::bind2nd).*/
    std::vector<int> years = Book::toYears(books);
    int count = std::count_if(years.begin(), years.end(), std::bind2nd(std::greater<int>(), 2009));
    std::cout << std::endl;
    std::cout <<count<<" ����� ����� 2009 ����"<<std::endl;
    for (i = books.begin(); i != books.end(); i++) {
        delete (*i);
    }
}