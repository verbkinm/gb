#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>

using namespace std;

// Задание №1
template <typename T>
void Swap(T &p1, T &p2)
{
    T pbuf = p1;
    p1 = p2;
    p2 = pbuf;
}

// Задание №2
template <typename T>
void SortPointers(T &container)
{
    sort(container.begin(), container.end(), [](const auto &lhs, const auto &rhs)
    {
        return *lhs < *rhs;
    });
}

// Задание №3
bool isVowel(char ch)
{
    ch = tolower(ch);
    switch(ch)
    {
        case 'a':
        case 'e':
        case 'o':
        case 'u':
        case 'i':
            return true;
        break;
    }

    return false;
}

int main()
{
    // Задание №1
    {
        int *p1 = new int(5);
        int *p2 = new int(6);

        Swap(p1, p2);

        cout << *p1 << ' ' << *p2 <<  endl;

        delete p1;
        delete p2;
    }

    // Задание №2
    {
        const int VECTOR_SIZE = 10'000;
        vector<int *> vec;

        random_device rd;
        mt19937_64 mersenne(rd());

        for (int i = 0; i < VECTOR_SIZE; ++i)
        {
            int* random_value = new int(mersenne());
            vec.push_back(random_value);
        }

        SortPointers(vec);

        for(auto &el : vec)
            delete el;

        vec.clear();
    }

    // Задание №3
    {
        ifstream file("War and peace.txt");
        int count = 0;
        while(!file.eof())
        {
            string str;
            getline(file, str);
            count += count_if(str.begin(), str.end(), [](char ch)
            {
                return isVowel(ch);
            });
        }
        file.close();

        cout << count << endl;
    }

    return 0;
}
