#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <cmath>
#include <random>
#include <iterator>
#include <algorithm>

using namespace std;

mutex m, w;

// Задание №1
void pcout(const string &str)
{
    lock_guard lg(m);
    cout << str;
}

// Задание №2
bool isPrime(long long n)
{
    for(long long i = 2; i <= sqrtl(n); i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

void primeNumber(long long n, long long counter)
{
    lock_guard lg(m);
    long long i = 2;
    for(; counter < n; i++)
    {
        if(isPrime(i))
            counter++;
    }
    cout << endl << --i << endl;
    w.unlock();
}

// Задание №3
void master(vector<int> &vec)
{
    random_device rd;
    mt19937_64 mersenne(rd());

    for(int i = 0; i < 100; i++)
    {
        this_thread::sleep_for(1s);
        lock_guard lg(m);
        vec.push_back(mersenne());

        cout << "master: ";
        copy(vec.begin(), vec.end(), ostream_iterator<int>{cout, " "});
        cout << endl;
    }
}

void thief(vector<int> &vec)
{
    for(int i = 0; i < 100; i++)
    {
        this_thread::sleep_for(500ms);
        lock_guard lg(m);

        auto it = max_element(vec.begin(), vec.end());
        if(it != vec.end())
            vec.erase(it);

        cout << "thief: ";
        copy(vec.begin(), vec.end(), ostream_iterator<int>{cout, " "});
        cout << endl;
    }
}

int main()
{
    // Задание №1
    {
        thread th1(pcout, "string\n");
        thread th2(pcout, "long string string\n");
        thread th3(pcout, "abc\n");

        th1.join();
        th2.join();
        th3.join();
        cout << endl;
    }

    // Задание №2
    {
        long long n = 0,
                counter = 0;
        cin >> n;

        w.lock();
        thread th(primeNumber, n, counter);

        cout << "progress";
        cout.flush();
        while(!w.try_lock())
        {
            cout << ".";
            cout.flush();
            this_thread::sleep_for(1s);
        }
        w.unlock();
        th.join();

        cout << endl;
    }

    // Задание №3
    {
        vector<int> vec;

        thread th1(master, ref(vec));
        thread th2(thief, ref(vec));

        th1.join();
        th2.join();
    }
}
