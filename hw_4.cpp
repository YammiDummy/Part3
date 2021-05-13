#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <random>

using namespace std;

template <class cont, typename T>
void insert_sorted(cont& m_v, T var) {
   
    cont v_temp = m_v;
    sort(v_temp.begin(), v_temp.end());
    
    if (equal(m_v.begin(), m_v.end(), v_temp.begin())) {                        //Проверка на сортированность контейнера.
        auto low = lower_bound(m_v.begin(), m_v.end(), var);
        m_v.insert(low, var);
    }
    else cout << "Your vector isn't sorted" << endl;
};

template <typename T>
void insert_sorted(list<T>& m_v, T var) {

    list<T> v_temp = m_v;
    v_temp.sort();

    if (equal(m_v.begin(), m_v.end(), v_temp.begin())) {                        //Проверка на сортированность листа.
        auto low = lower_bound(m_v.begin(), m_v.end(), var);
        m_v.insert(low, var);
    }
    else cout << "Your vector isn't sorted" << endl;
};

template <typename T>
void generate_vector(vector<T>& v, size_t n) {
    const size_t data_points{ n };
    random_device rd;
    mt19937 gen{ rd() };
    // первый параметр - математическое ожидание
    // второй параметр - квадратическое отклонение
    normal_distribution<> d{ 10, 3 };
    v.reserve(data_points);
    generate_n(back_inserter(v), data_points, [&] { return d(gen); });
}

void digit_vector(vector<double>& a, vector<int>& d) {
    transform(a.begin(), a.end(), back_inserter(d), [](double i) {return i; });
};

int main()
{
    //vector<int> v{ 10, 24, 38, 40, 43, 51, 77 };
    //insert_sorted(v, 32.2);
    //for (int x : v) {
    //    cout << x << " ";
    //};
    vector<double> analog;
    vector<int> digit;
    generate_vector(analog, 10);
    
    for (double x : analog) {
        cout << x << endl;
    };

    digit_vector(analog, digit);

    for (int x : digit) {
        cout << x << endl;
    };

}
