#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
void print(std::pair<std::string, int> pair) {
    if (pair.first.length() > 3 && pair.second >= 7)
        std::cout << pair.first << " " << pair.second << std::endl;
}
int main()
{
    /*----------------------------2-----------------------
      Ќаписать код дл€ чтени€ произвольного текстового файла и вывода на экран всех слов
      размером более 3 букв, встречающихс€ в нем не менее 7 раз, в пор€дке убывани€
      частоты встречаемости (приложение ј). ¬ качестве разделителей слов рассматривать
      пробел, точку, зап€тую, тире, двоеточие, восклицательный знак, точку с зап€той.
      »спользовать контейнер std::map.*/
    std::map<std::string, int> map;
    std::ifstream fin;
    fin.open("Text.txt", std::ios::app);
    while (fin.peek() != EOF)
    {
        const size_t MAXLEN = 1000;
        char text[MAXLEN];
        fin.getline(text, MAXLEN);
        char* substr = std::strtok(text, ".,:!;? ");
        while (substr != 0) {
            std::string word = substr;
            std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            std::map<std::string, int>::iterator founded = map.find(word);
            if (founded == map.cend()) {
                map.insert(std::make_pair(word, 1));
            }
            else
            {
                map[word]++;
            }
            substr = std::strtok(NULL, ".,:!;? ");
        }
    }
    std::vector < std::pair<std::string, int> > words(map.begin(), map.end());
    std::sort(words.begin(), words.end(), [](auto lhs, auto rhs) {return lhs.second > rhs.second; });
    std::for_each(words.begin(), words.end(), print);
}