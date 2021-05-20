#include <iostream>
#include <ostream>
#include <algorithm>
#include <fstream>
#include "Timer.h"
#include <set>
#include <map>
#include <vector>
#include <iterator>

//template <class iterator>
//void print(iterator begin, iterator end) {
//	set<string> s;
//	for (auto i = begin; i != end; i++) {
//		s.insert(*i);
//	}
//	for (auto word : s) {
//		cout << word << endl;
//	}
//}

void break_string(string& str) {
    int i = 0;
    size_t size;
    string s = "";
    vector<string> vs;
    multimap <size_t, string> m_map;
    for_each(str.begin(), str.end(),                           //Разбиваем исходный текст на предложения
        [&](char c) {
            if (c == '.') {
                vs.push_back(s);
                s = "";
                i = 0;
            }
            else {
                s.push_back(c);
            }
        });

    for_each(vs.begin(), vs.end(), [&size, &m_map](string& s) {             //Удаляем случайные пробелы в начале строки.
        if (s.at(0) == ' ') s.erase(0, 1);
        size = s.size();
        m_map.insert(pair<size_t,string>(size, s));
        });

    for_each(m_map.begin(), m_map.end(), [](pair<size_t, string> elem) {                   //Вывод результата на экран.
        cout << elem.first << " characters in this string: " << elem.second << endl;
        });
};



int main()
{
    string s, text;
    getline(cin, text);
    break_string(text);
}
   //1. Создать шаблонную функцию, которая принимает итераторы на начало и конец последовательности слов, 
   //и выводящую в консоль список уникальных слов(если слово повторяется больше 1 раза, то вывести его надо один раз).
   //Продемонстрировать работу функции, передав итераторы различных типов.
   //
   //2. Используя ассоциативный контейнер, напишите программу, которая будет считывать данные введенные пользователем из стандартного 
   //потока ввода и разбивать их на предложения.Далее программа должна вывести пользователю все предложения, отсортировав их по длине.

