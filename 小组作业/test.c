#include <stdio.h>
#include <string.h>
int main(void)
{
    char str[2000];
    while (gets(str))
    {
        int center = strlen(str) / 2;
        if (str[center] == '&')
        {
            int i;
            for (i = 1; str[center + i]; i++)
                if (str[center + i] != str[center - i]||str[center+i]=='&')
                {
                    break;
                }
            if(str[center+i]==0&&center-i==-1)puts("YES");
            else puts("NO");
        }
        else
            puts("NO");
    }
}