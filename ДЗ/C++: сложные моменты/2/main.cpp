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

std::string iso_8859_1_to_utf8(std::string &str)
{
    string strOut;
    for (std::string::iterator it = str.begin(); it != str.end(); ++it)
    {
        uint8_t ch = *it;
        if (ch < 0x80) {
            strOut.push_back(ch);
        }
        else {
            strOut.push_back(0xc0 | ch >> 6);
            strOut.push_back(0x80 | (ch & 0x3f));
        }
    }
    return strOut;
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

//        setlocale(LC_ALL, "RUS");
//        ifstream file("text.txt");
        ifstream file("1.txt");
        char ch;
        while(!file.eof())
        {
            string str;
            getline(file, str);
            string compstr = "о";
            auto f = count_if(str.begin(), str.end(), [](const char &el)
            {
                cout << el << endl;
                return false;
            });
//            string strUtf = iso_8859_1_to_utf8(str);
//            cout << str << endl;
//            file.read(&ch, 1);/
        }
    }
    return 0;
}
