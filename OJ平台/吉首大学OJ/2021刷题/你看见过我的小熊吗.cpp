#include <stdio.h>
int main(void)
{
    //freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, value, len = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &value);
            if (value == 8)
            {
                i++;
                int l = 1;
                while (i < n && scanf("%d", &value) && value == 8)
                    l++, i++;
                if (l > len)
                    len = l;
            }
        }
        printf("%d\n", len);
    }
    return 0;
}