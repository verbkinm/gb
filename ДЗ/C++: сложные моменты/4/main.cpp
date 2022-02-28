#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>
#include <random>

using namespace std;

//Задание №1
template <class T, template <class...> class C, class U>
void insert_sorted(C<U> &cont, U value)
{
    fill_n(std::back_inserter(cont), 1, value);
    sort(begin(cont), end(cont));
}

int main()
{
    //Задание №1
    vector<float> vf = {1.2, 2.6, 3.7};
    insert_sorted<float>(vf, 1.8f);
    copy(vf.begin(), vf.end(), ostream_iterator<float>{cout, " "});

    //Задание №2
    const int MAX_DIGIT = 100;
    const int VECTOR_SIZE = 10;

    random_device rd;
    mt19937_64 mersenne(rd());

    auto rand_float_func = [&](){return (mersenne() % MAX_DIGIT) + (mersenne() % MAX_DIGIT ) * 0.001;};

    vector<float> vecAnalog(VECTOR_SIZE);
    vector<int> vecDigit(VECTOR_SIZE);

    generate(vecAnalog.begin(), vecAnalog.end(), rand_float_func);
    copy(vecAnalog.begin(), vecAnalog.end(), ostream_iterator<float>{cout, "\n"});

    copy(vecAnalog.begin(), vecAnalog.end(), vecDigit.begin());
    copy(vecDigit.begin(), vecDigit.end(), ostream_iterator<float>{cout, "\n"});

}
