#include <iostream>
#include <thread>
#include <mutex>
#include <cmath>

using namespace std;

mutex m;

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
int main()
{
    // Задание №1
    //    thread th1(pcout, "string\n");
    //    thread th2(pcout, "long string string\n");
    //    thread th3(pcout, "abc\n");

    //    th1.join();
    //    th2.join();
    //    th3.join();

    // Задание №2
    long long n = 0,
              counter = 0;
    cin >> n;

    long long i = 2;
    for(; counter < n; i++)
    {
        if(isPrime(i))
            counter++;
    }
    cout << --i;
}
