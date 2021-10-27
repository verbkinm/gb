#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash(char *S)
{
     int r=0;
     while(*S)
     {
         r += (int)(*S);
         S++;
     }
     return r;
}

int profitCaculation(int* coin, const int maxN)
{
    int sum = 0;
    int o = 0;
    for (int i = 0; i < maxN; i++)
    {
        if ((sum + coin[i]) <= 98)
        {
            sum += coin[i];
            o++;
            --i;
        }
        if (sum >= 98)
            return o;
    }
    return o;
}

int main()
{
    printf("%d\n", hash("hello"));
    const int maxN = 98;
    int coin[] = { 50, 10, 5, 2, 1 };

    printf("%d\n",profitCaculation(coin, maxN));
    return 0;
}
