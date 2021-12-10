#include <iostream>

#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int dat()
{
    return rand()%10+1;
}

int main()
{
    // Задание №2
    vector<int> vec(10);
    generate(vec.begin(), vec.end(), dat);
    set<int> s(vec.begin(), vec.end());

    cout << s.size() << endl;

    return 0;
}
