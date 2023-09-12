#include <stdio.h>
#include <string.h>
int main()
{
    char s[100];
    while (gets(s))
    {
        int count[256] = {0}, i;
        for (i = 0; s[i]; i++)
        {
            if (s[i] <= 'Z' && s[i] >= 'A')
                s[i] = s[i] + 32;
            count[s[i]]++;
        }
        int max = count[s[0]], ch = s[0], index = 0;
        for (i = 1; i < 256; i++)
        {
            if (count[i] >= max)
            {
                int iindex = 0;
                for (int j = 0; s[j]; j++)
                    if (s[j] == i)
                    {
                        iindex = j;
                        break;
                    }
                if (count[i] == max && iindex < index)
                {
                    ch = i;
                    index = iindex;
                }
                else if (count[i] > max)
                {
                    ch = i;
                    index = iindex;
                    max = count[i];
                }
            }
        }
        printf("%c %d\n", ch, max);
    }
}
