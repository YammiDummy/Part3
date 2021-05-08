#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void average(list<double>& l) {
    double sum = 0;
    for (auto num : l) {
        sum += num;
    };
    double av = sum / (l.size());
    l.push_back(av);
};

class Matrix {
private:
    int m_size;
    int** m_a;
public:

    Matrix(int size)
        :m_size(size) {
        m_a = new int* [m_size]; //Объявляем двумерный целочисленный динамический массив (матрицу)
        for (int i = 0; i < m_size; i++) {
            m_a[i] = new int[m_size];
        }
        cout << "Enter a matrix:" << endl;
        for (int i = 0; i < m_size; i++) {
            for (int j = 0; j < m_size; j++) {
                cin >> m_a[i][j]; //Вводим элементы матрицы
            }
        }

    }

    ~Matrix() {
        clearMemory(m_a, m_size);
    };

    double findDet() {
        return rec_func(m_a, m_size);
    };

    void clearMemory(int** a, int size) { //Функция освобождения памяти, выделенной под двумерный динамический массив
        for (int i = 0; i < size; i++) {
            delete[] a[i];
        }
        delete[] a;
    }

    int rec_func(int** a, int size) { //Рекурсивная функция вычисления определителя матрицы
        if (size == 1)
            return a[0][0];
        else if (size == 2)
            return a[0][0] * a[1][1] - a[0][1] * a[1][0];
        else {
            int d = 0;
            for (int k = 0; k < size; k++) {
                int** m = new int* [size - 1];
                for (int i = 0; i < size - 1; i++) {
                    m[i] = new int[size - 1];
                }
                for (int i = 1; i < size; i++) {
                    int t = 0;
                    for (int j = 0; j < size; j++) {
                        if (j == k)
                            continue;
                        m[i - 1][t] = a[i][j];
                        t++;
                    }
                }
                d += pow(-1, k + 2) * a[0][k] * rec_func(m, size - 1);
                clearMemory(m, size - 1); //Освобождаем память, выделенную под алгебраическое дополнение
            }
            return d; //Возвращаем определитель матрицы
        }
    }
};

class num_iterator {
    int i;
public:
    explicit num_iterator(int position = 0)
        :i( position ) {}

    int operator*() const { return i; }

    bool operator != (const num_iterator& other) const {
        return i != other.i;
    }

    num_iterator& operator++() {
        ++i;
        return *this;
    }
};

class num_range {
private:
    int m_begin;
    int m_end;

public:
    num_range(int begin, int end)
    :m_begin(begin), m_end(end) {}

    num_iterator begin() { 
        return num_iterator(m_begin); 
    }

    num_iterator end() { 
        return num_iterator(m_end); 
    }
};

int main() {
    //int n;
    //cout << "Enter a matrix size:" << endl;
    //cout << "n = ";
    //cin >> n; //Вводим размерность матрицы
    //
    //Matrix mat1(n);
    //
    //cout << "Found determinant: " << mat1.findDet() << endl; //Вызываем рекурсивную функцию вычисления определителя матрицы
    //system("pause");
    
    for (int x : num_range(100, 110)) {
        cout << x << " ";
    };
}

//1. Написать функцию, добавляющую в конец списка вещественных чисел элемент, значение которого равно среднему арифметическому всех его элементов.
//2. Создать класс, представляющий матрицу.Реализовать в нем метод, вычисляющий определитель матрицы.
//3. Реализовать собственный класс итератора, с помощью которого можно будет проитерироваться по диапазону целых чисел в цикле for - range - based.
