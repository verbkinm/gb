#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool simple_true(int n)
{
    if (n != 2 && n % 2 == 0)
        return false;

    int s = sqrt(n);

    for (int i = 3; i <= s; i++)
    {
        if ( (n % i) == 0 )
            return false;
    }

    return true;
}

int main()
{
    for (int i = 2; i < 101; i++)
    {
        if(simple_true(i))
            printf("Число %d - простое!\n", i);
    }

    return 0;
}
