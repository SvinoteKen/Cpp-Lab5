#include <iostream>
#include "Cache.h"
int main()
{
     /* Написать шаблонный класс кэша данных Cache<T> с методом добавления элемента в
        кеш put(T elem) и его аналогом – оператором +=, а также методом проверки наличия
        элемента в кеше bool contains(T elem).Написать явную специализацию шаблона
        для типа std::string с такими нюансами : метод contains() должен возвращать true
        по совпадению первого символа строки; метод add() должен генерировать
        исключение, если в кеше уже есть 100 строк.В главной функции инстанцировать
        Cache с типами int и std::string, добавить в каждый несколько элементов и
        продемонстрировать для каждого работу метода contains() (см.Приложение А).*/

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