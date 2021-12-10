#pragma once

#include <stdlib.h>
#include <iostream>
#include "stdexcept"

using bad_length = std::runtime_error;
using bad_range = std::out_of_range;

template <typename T>
class Array
{
private:
    int _length;
    T* _data;

public:
    Array();
    Array(int length);
    ~Array();

    void erase();
    void remove(int index);
    inline void removeLast();
    inline void removeFirst();

    void reallocate(int newLength);
    void resize(int newLength);

    void insertBefore(T value, int index);
    void insertAtBeginning(T value);
    void insertAtEnd(T value);

    inline int getLength() const;

    T& operator [](int index);

    void print() const;

    inline void sort();
};

template<typename T>
Array<T>::Array() : _length(0), _data(nullptr)
{

}

template<typename T>
Array<T>::Array(int length) : _length(length), _data(nullptr)
{
    if (length < 1)
        throw bad_length(std::string(__PRETTY_FUNCTION__) + "; Bad array size. Size = " + std::to_string(length));

    _data = new T[length];
}

template<typename T>
Array<T>::~Array()
{
    delete[] _data;
}

template<typename T>
void Array<T>::erase()
{
    delete[] _data;
    _data = nullptr;
    _length = 0;
}

template<typename T>
T& Array<T>::operator[](int index)
{
    if (index < 0 || index >= _length)
        throw bad_range(std::string(__PRETTY_FUNCTION__) + "; Bad array index. Index = " + std::to_string(index) + ", array length = " + std::to_string(_length));

    return _data[index];
}

template<typename T>
void Array<T>::print() const
{
    for (int i = 0; i < _length; ++i)
        std::cout << _data[i] << " ";

    std::cout << std::endl;
}

template<typename T>
void Array<T>::sort()
{
    qsort(_data,
          _length,
          sizeof(T),
          [](const void *a, const void *b) {return *(T*)a - *(T*)b; });
}

template<typename T>
void Array<T>::reallocate(int newLength)
{
    if (newLength <= 0)
        return;

    erase();

    _data = new T[newLength];
    _length = newLength;
}

template<typename T>
void Array<T>::resize(int newLength)
{
    if (newLength == _length)
        return;

    if (newLength <= 0)
    {
        erase();
        return;
    }

    T* data = new T[newLength];

    int elementsToCopy = (newLength > _length) ? _length : newLength;

    for (int index = 0; index < elementsToCopy; ++index)
        data[index] = _data[index];

    delete[] _data;

    _data = data;
    _length = newLength;
}

template<typename T>
void Array<T>::insertBefore(T value, int index)
{
    if (index < 0 || index > _length)
        throw bad_range(std::string(__PRETTY_FUNCTION__) + "; Bad array index. Index = " + std::to_string(index) + ", array length = " + std::to_string(_length));

    T* data = new T [_length + 1];

    memcpy(data, _data, sizeof(T) * index);
    data[index] = value;
    memcpy(data + index + 1, _data + index, sizeof(T) * _length - index - 1);

    delete[] _data;
    _data = data;
    ++_length;
}

template<typename T>
void Array<T>::remove(int index)
{
    if (index < 0 || index >= _length)
        throw bad_range(std::string(__PRETTY_FUNCTION__) + "; Bad array index. Index = " + std::to_string(index) + ", array length = " + std::to_string(_length));

    if (_length == 1)
    {
        erase();
        return;
    }

    T* data = new T[_length-1];

    for (int before = 0; before  < index; ++before)
        data[before] = _data[before];

    for (int after = index + 1 ; after < _length; ++after)
        data[after-1] = _data[after];

    delete[] _data;
    _data = data;
    --_length;
}

template<typename T>
void Array<T>::removeLast()
{
    remove(_length - 1);
}

template<typename T>
void Array<T>::removeFirst()
{
    remove(0);
}

template<typename T>
void Array<T>::insertAtBeginning(T value)
{
    insertBefore(value, 0);
}

template<typename T>
void Array<T>::insertAtEnd(T value)
{
    insertBefore(value, _length);
}

template<typename T>
int Array<T>::getLength() const
{
    return _length;
}
