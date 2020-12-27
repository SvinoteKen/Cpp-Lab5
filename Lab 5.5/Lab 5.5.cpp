#include <iostream>
#include "Cache.h"
int main()
{
     /* �������� ��������� ����� ���� ������ Cache<T> � ������� ���������� �������� �
        ��� put(T elem) � ��� �������� � ���������� +=, � ����� ������� �������� �������
        �������� � ���� bool contains(T elem).�������� ����� ������������� �������
        ��� ���� std::string � ������ �������� : ����� contains() ������ ���������� true
        �� ���������� ������� ������� ������; ����� add() ������ ������������
        ����������, ���� � ���� ��� ���� 100 �����.� ������� ������� ��������������
        Cache � ������ int � std::string, �������� � ������ ��������� ��������� �
        ������������������ ��� ������� ������ ������ contains() (��.���������� �).*/

    Cache<int> cache;
    cache.put(1);
    cache.put(2);
    cache.put(3);
    cache += 5;
    Cache<std::string> voc;
    voc.add("OK");
    std::cout << voc.contains("Only") << std::endl;
    std::cout << cache.contains(5) << std::endl;
}