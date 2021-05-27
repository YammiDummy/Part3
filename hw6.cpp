#include <iostream>
#include <thread>
#include <mutex>
#include <algorithm>

using namespace std;
mutex m;

template <typename T>
void pcout(T& temp) {               
    m.lock();
    cout << temp;
    m.unlock();
}

bool PrimeCheck (int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;    // must be prime
}

void GetPrime(int index) {
    lock_guard lg(m);
    int current = 2;
    for (int count = 0; count < index;) {
        if (PrimeCheck(current)) {++count;}
        ++current;
        cout << "Number checking: " << current << endl;
    }
    cout << "Prime number #" << index << " is " << --current;
}

int main()
{
    int a = 5;
    string s = "Carrot";
    thread t1([](auto temp) {pcout(temp); }, a);
    thread t2([](auto temp) {pcout(temp); }, s);
    t1.join();
    t2.join();

    thread t3(GetPrime, 500);
    t3.join();
};