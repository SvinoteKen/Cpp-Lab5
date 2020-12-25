#include <iostream>
#include "DataManager.h"
int main()
{
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
