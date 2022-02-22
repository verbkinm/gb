#include <iostream>
#include <list>
#include <random>

using namespace std;

#define LIST_SIZE 100
#define MAX_DIGIT 1000

//Задание №2
template <class T>
class Matrix
{
    T*           _data;
    unsigned int _rows;
    unsigned int _cols;

public:
    Matrix(unsigned int rows, unsigned int cols) : _rows(rows), _cols(cols)
    {

    }

    T*  data()
    {
        return _data;
    }

    // определитель
    T determinant() const
    {

    };

    // чтение-запись
//    friend std::istream& operator>>(std::istream& is, Matrix& m);
//    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
};

//Задание №3
template<typename T>
class Iterator
{
private:
    T *_ptr;
public:
    Iterator() : _ptr(nullptr)
    {};
    Iterator(T *ptr) : _ptr(ptr)
    {};

    T &operator*()
    {
        return *_ptr;
    }

    Iterator &operator++()
    {
        ++_ptr;
        return *this;
    }

    friend bool operator!=(const Iterator &lhs, const Iterator &rhs)
    {
        return lhs._ptr != rhs._ptr;
    }

};

int main()
{
    //Задание №1
    {
        list<double> list;

        random_device rd;
        mt19937_64 mersenne(rd());

        for (int i = 0; i < LIST_SIZE; ++i)
            list.push_back((mersenne() % MAX_DIGIT) + (mersenne() % MAX_DIGIT ) * 0.00001);

        for(auto const &el : list)
            cout << el << ' ';

        //    double avrg = accumulate(list.begin(), list.end(), 0) / list.size(); //  возмоно переполнение!
        double avrg = 0;
        for(const auto&el : list)
            avrg = (avrg + el) / 2;

        cout << "\nСреднее арифметическое = " << avrg << '\n';
        list.push_back(avrg);
    }
    //Задание №2
    {

    }
    //Задание №3
    {
        vector<int> vec{1, 2, 3, 4 , 5};
        Iterator<int> it;
        Iterator<int> it2 = &(*vec.end());

        for(it = &(*vec.begin()); it != it2; ++it)
        {
            cout << *it << ' ';
        }
    }
    return 0;
}
