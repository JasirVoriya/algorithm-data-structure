#include<stdio.h>
#include<string.h>
int main(void)
{
    char str[2000];
    while(gets(str))
    {
        int i=0,j=strlen(str)-1;
        while(i<j)
        {
            putchar(str[i++]);
            putchar(str[j--]);
        }
        if(i==j)putchar(str[i]);
        putchar('\n');
    }
    return 0;
}