#include <stdio.h>
#include <string.h>
int main()
{
    char str1[100], str2[100];
    int j, i, k;
    gets(str1);
    gets(str2);
    for (i = 0; str2[i] != '\0'; i++)
    {
        for (j = 0; str1[j] != '\0'; j++)
        {
            if (str1[j] == str2[i])
            {
                for (k = j; k < strlen(str1); k++)
                {
                    str1[k] = str1[k + 1];
                }
                j--;
            }
        }
    }
    printf("%s\n", str1);
}
