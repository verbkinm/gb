#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* alphabet = "abcdefghjklmnopqrstuvwxyz";

char *coder(char* s, int w)
{
    int  h;
    if (strlen(s) % w != 0)
        h = strlen(s) / w + 1;
    else
        h=strlen(s) / w;

    char a[h][w];

    int k=0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (k < strlen(s))
            {
                a[i][j] = s[k];
                k++;
            }
            else
                a[i][j] = ' ';
        }
    }
    char code[h*w];
    char* ptrCode = code;

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {
            *ptrCode = a[j][i];
            ptrCode++;
        }
    }
    *ptrCode = '\0';
    ptrCode = code;

    return ptrCode;
}

char* decoder(char* s, int w)
{
    int h = strlen(s) / w;
    char a[w][h];
    int k=0;

    for (int i=0;i<w;i++)
    {
        for (int j=0;j<h;j++)
        {
            a[i][j]=s[k];
            k++;
        }
    }

    char decode[h*w];
    char* ptrCode = decode;

    for (int i=0;i<h;i++)
    {
        for (int j=0;j<w;j++)
        {
            *ptrCode = a[j][i];
            ptrCode++;
        }
    }
    *ptrCode = '\0';
    ptrCode = decode;
    return ptrCode;
}

char encryptOneChar(char c, int key)
{
    if(isalpha(c) == 0)
        return c;

    char result = c + key;
    if(result > 122)
        result -= strlen(alphabet) + 1;
    else if (result < 97)
        result += strlen(alphabet) + 1;;

    return result;
}

char* encrypt(char* str, int key)
{
    int len = strlen(str);

    for(int i = 0; i < len;  i++)
        str[i] = encryptOneChar(str[i], key);

    return str;
}

int main()
{
    char str[] = "a hello world!";
    int key = 1;
    printf("%s\n", encrypt(str, key)) ;
    printf("%s\n", encrypt(str, -key)) ;

    char *code = coder("test this code", 5);
    printf("%s\n", code);
    printf("%s\n", decoder(code, 5));
    return 0;
}
