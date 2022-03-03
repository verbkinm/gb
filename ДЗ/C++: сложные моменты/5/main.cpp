#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cstring>

using namespace std;

// Задание №1
template <typename T>
void printUniqWords(T IteratorFirst, T IteratorLast)
{
    unordered_map<string, int> unordered_map;
    for(; IteratorFirst != IteratorLast; IteratorFirst = next(IteratorFirst))
        unordered_map[*IteratorFirst]++;

    for(const auto &[key, value] : unordered_map)
        if(value > 1)
            cout << key << endl;
}

int main()
{
    // Задание №1

    vector<string> vec {"hi", "the", "a", "on", "off", "on", "hi", "the", "world", "word"};
    printUniqWords(vec.begin(), vec.end());

    cout << endl;
    multiset<string> mset {"hi", "the", "a", "on", "off", "on", "hi", "the", "world", "word"};
    printUniqWords(mset.begin(), mset.end());

    cout << endl;
    list<string> list {"hi", "the", "a", "on", "off", "on", "hi", "the", "world", "word"};
    printUniqWords(list.begin(), list.end());

    cout << endl;

    // Задание №2
    string input;
    getline(cin, input);
    istringstream ss(input);

    set<string> sentences;
    for (string line; getline(ss, line, '.'); )
    {
        if(line.at(0) == ' ')
            line = line.substr(1);

        sentences.insert(line);
    }

    copy(sentences.begin(), sentences.end(), ostream_iterator<string>{cout, "\n"});


}
