#ifndef PAIR_H
#define PAIR_H

template <typename T1, typename T2>
class Pair
{
private:
    T1 _first;
    T2 _second;

public:
    Pair(T1 first, T2 second);
    const T1 &first() const;
    void setFirst(const T1 &newFirst);
    const T2 &second() const;
    void setSecond(const T2 &newLast);
};

template <typename T1, typename T2>
Pair<T1, T2>::Pair(T1 first, T2 second) : _first(first), _second(second)
{

}

template <typename T1, typename T2>
inline const T2 &Pair<T1, T2>::second() const
{
    return _second;
}

template <typename T1, typename T2>
inline void Pair<T1, T2>::setSecond(const T2 &newLast)
{
    _second = newLast;
}

template <typename T1, typename T2>
inline const T1 &Pair<T1, T2>::first() const
{
    return _first;
}

template <typename T1, typename T2>
inline void Pair<T1, T2>::setFirst(const T1 &newFirst)
{
    _first = newFirst;
}

#endif // PAIR_H
