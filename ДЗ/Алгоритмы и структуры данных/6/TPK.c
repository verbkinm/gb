#include <stdio.h>
#include <math.h>

float f (float x)
{
    return (sqrt(fabs(x)) + 5.0 * pow(x, 3.0));
}

int main ()
{
    float arr[11];

    for(int i = 10; i >= 0; i--)
        scanf("%f", (arr + i));

    for (int i = 0; i < 11; i++)
    {
        if (f(*(arr + i)) > 400.0)
            printf ("arr[%d] > 400\n", i);
    }

    return 0;
}