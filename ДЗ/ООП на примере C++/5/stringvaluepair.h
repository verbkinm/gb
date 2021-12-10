#ifndef STRINGVALUEPAIR_H
#define STRINGVALUEPAIR_H

#include <string>
#include "pair.h"

template<typename T>
class StringValuePair : public Pair<std::string, T>
{
public:
    StringValuePair(std::string first, T second);
};

template<typename T>
StringValuePair<T>::StringValuePair(std::string first, T second) : Pair<std::string, T> (first, second)
{

}

#endif // STRINGVALUEPAIR_H
