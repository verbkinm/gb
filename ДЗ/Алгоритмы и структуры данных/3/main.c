#include <stdio.h>

// 1 Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.
void decToBin(unsigned a)
{
   if(a)
   {
      decToBin(a >> 1);
      printf("%d", a & 1);
   }
}

// 2 Реализовать функцию возведения числа [a] в степень [b]
int _pow(int a, int b)
{
    int base = a;
    for(int i = 1; i < b; i++)
        a = a * base;

    return a;
}

// 3 Рекурсивно
int recPow(int a, int b)
{
    if(!b)
        return 1;

    return a*recPow(a,--b);
}

// 4 Рекурсивно, используя свойство чётности степени
int evenPow(int a, int b);
int evenPowBase(int a, int b, int base)
{
    if(!b)
        return 1;
    if(b == 1)
        return a;

    if(b % 2 == 0)
        return evenPowBase(a*a, (b >> 1), base);

    return evenPowBase(a*base, --b, base);
}

int evenPow(int a, int b)
{
    return evenPowBase(a, b, a);
}

int main()
{
   int a, b;

   scanf("%d%d", &a, &b);
   printf("%d\n", _pow(a, b));
   printf("%d\n", evenPow(a, b));
   printf("%d\n", recPow(a, b));

   return 0;
}
