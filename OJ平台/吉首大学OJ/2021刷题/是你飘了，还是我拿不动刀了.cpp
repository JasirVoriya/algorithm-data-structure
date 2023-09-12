#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char str[2000];
    while (gets(str))
    {
        int count = 0;
        for (int i = 0; str[i]; i++)
        {
            while (str[i] && !isalpha(str[i]))
                i++;
            if (str[i])
                count++;
            while (str[i] && isalpha(str[i]))
                i++;
        }
    }
    return 0;
}