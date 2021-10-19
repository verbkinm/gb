#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sz = 1;

bool check(char v)
{
    char t;
    scanf("%c", &t);
    if(t == EOF || t == '\n' || t == 0)
    {
        return (!sz ? true : false);
    }

    if(t == ')')
    {
        if(v == '(')
        {
            sz--;
            return true;
        }
        return false;
    }

    if(t == '}')
    {
        if(v == '{')
        {
            sz--;
            return true;
        }
        return false;
    }

    if(t == ']')
    {
        if(v == ']')
        {
            sz--;
            return false;
        }
        return true;
    }

    if(t == '{' || t == '[' || t == '(')
    {
        sz++;
        if(check(t))
            return check(v);
        else
            return false;
    }

    return check(v);
}

int main()
{
    char t;
    scanf("%c", &t);

    while(t != EOF && t != '\n' && t != 0)
    {
        if(!check(t))
        {
            printf("no\n");
            return 0;
        }
        scanf("%c", &t);
    }

    printf("yes\n");
    return 0;
}
