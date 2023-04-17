#include <stdio.h>
char input()
{
    char ch = getchar();
    getchar();
    return ch;
}
int main(void)
{
    char ch;
    int n;
    while (~scanf("%d", &n))
    {
        getchar();
        int sandwich, i, num;
        for (sandwich = num = i = 0; i < n; i++)
        {
            ch = input();
            if (ch == 'v')
                num++;
            else
            {
                if (num >= 3)
                    sandwich += num - 2;
                num = 0;
            }
        }
        if (num >= 3)
            sandwich += num - 2;
        printf("%d\n", sandwich);
    }
}