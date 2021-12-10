#ifndef PAIR1_H
#define PAIR1_H

template <typename T>
class Pair1
{
private:
    T _first, _second;

public:
    Pair1(T first, T second);
    const T &first() const;
    void setFirst(const T &newFirst);
    const T &second() const;
    void setSecond(const T &newLast);
};

template<class T> Pair1<T>::Pair1(T first, T second) : _first(first), _second(second)
{

}

template <typename  T>
inline const T &Pair1<T>::second() const
{
    return _second;
}

template <typename  T>
inline void Pair1<T>::setSecond(const T &newLast)
{
    _second = newLast;
}

template <typename  T>
inline const T &Pair1<T>::first() const
{
    return _first;
}

template <typename  T>
inline void Pair1<T>::setFirst(const T &newFirst)
{
    _first = newFirst;
}

#endif // PAIR1_H
