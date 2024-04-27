#include <stdio.h>
int main()
{
    char s[1000];
    while (scanf("%s", s) != EOF)
    {
        printf("hello, %s\n", s);
    }
    return 0;
}