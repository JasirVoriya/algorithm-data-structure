#include <stdio.h>
#include <string.h>
int fun(const char *str, int n)
{
    for (int i = 0, j = n - 1; i < j; i++, j--)
        if (str[i] != str[j])
            return 0;
    return 1;
}
char *itoa(int n, char *str, int radxi)
{
    int i = 0;
    while (n)
    {
        str[i++] = n % radxi + '0';
        n /= radxi;
    }
    str[i] = 0;
    return str;
}
int main(void)
{
    int n, s;
    while (~scanf("%d%d", &n, &s))
    {
        while (n--)
        {
            char str[100];
            s++;
            int count = 0;
            for (int i = 2; i <= 10; i++)
            {
                itoa(s, str, i);
                if (fun(str, strlen(str)))
                    count++;
            }
            if (count >= 2)
                printf("%d\n", s);
        }
    }
    return 0;
}