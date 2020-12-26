#include <iostream>
#include "DataManager.h"
int main()
{
     /* -------------------1----------------
        Написать шаблонный класс DataManager<T> для специфической работы с набором
        однотипных данных(максимальная вместимость равна 64 элементам).В набор можно
        добавлять данные(метод push(T elem) для добавления одного элемента и метод
            push(T elems[], size_t n) для добавления группы из n элементов), считывать без
        извлечения(метод T peek()) и извлекать(метод T pop()) по некоторым алгоритмам
        (в соответствии с вариантом, приложение А).Если набор заполнен на 100 % и
        поступает команда добавления нового элемента(ов), то данные полностью
        выгружаются(дописываются) в специальный файл dump.dat, а сам массив очищается
        и новые данные записываются уже в обновленный набор.Если из массива удаляется
        последний элемент, то он заполняется ранее выгруженными в файл данными(если
            файл не пуст).
        Необходимо также реализовать явную специализацию шаблонного класса для
        символьного типа.В ней надо запрограммировать следующее : при добавлении
        символа в набор все знаки пунктуации должны автоматически заменяться на символ
        подчеркивания; добавить методы char popUpper() и char popLower(), которые
        позволяют при извлечении символа из набора привести его к верхнему или нижнему
        регистру, соответственно.
        В функции main() продемонстрировать применение шаблонного класса DataManager
        для типов int, double и char.Элементы контейнера должны выводиться на консоль с
        помощью std::ostream_iterator.
        push(): данные пишутся в начало набора, остальные смещаются вправо;
        peek(): возвращает центральный элемент в наборе или 0, если число элементов четно;
        pop(): извлекает средний элемент из набора (если элементов четное число, то первый
        элемент слева от центра раздела набора).*/

    DataManager<int> manager;
    manager.push(-9);
    int a[60] = { 0 };
    manager.push(a, 60);
    manager.print();
    int x = manager.peek();
    for (int i = 1; i < 15; ++i) {
        manager.push(i);
    }
    std::cout << std::endl;
    manager.print();
    x = manager.pop();
    std::cout << std::endl << "X = " << x << std::endl;
    std::cout << std::endl;
    std::cout << "Char Manager:"<<std::endl;;
    DataManager<char> char_manager;
    char_manager.push('h');
    char_manager.push('e');
    char_manager.push('l');
    char_manager.push('l');
    char_manager.push('o');
    char_manager.print();
    char ch = char_manager.popUpper();
    char ch2 = char_manager.popLower();
    std::cout << "Ch = " << ch << std::endl;
    std::cout << std::endl;
    std::cout << "Double Manager:"<<std::endl;;
    DataManager<double> double_manager;
    double_manager.push(3.14);
    double_manager.push(0.757);
    double_manager.push(0.1);
    double_manager.push(10.567);
    double_manager.print();
    double y = double_manager.pop();
    std::cout << "Y = " << y << std::endl;
}
