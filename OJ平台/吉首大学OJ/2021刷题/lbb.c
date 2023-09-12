#include <stdio.h>
#include <string.h>
int main()
{
    int i, lena, n;
    char a[10000], b[10000];
    while (~scanf("%s", a))
    {
        lena = strlen(a);
        if (lena % 2 == 1)
        {
            n = lena / 2;           //中间字符串下标,现在可以拆成三个区间 [0,n-1], [n,n], [n+1,lnea-1]
            for (i = 0; i < n; i++) //第一个区间反转
                b[n - 1 - i] = a[i];
            b[n] = a[n];                   //第二个区间不需要反转
            for (i = n + 1; i < lena; i++) //第三个区间反转
                b[lena + n - i] = a[i];//b[lena-1+(n+1-i)]
        }
        else
        {
            n = lena / 2; //拆成两个区间：[0,n-1],[n,lena-1]
            for (i = 0; i < n; i++)
                b[n - 1 - i] = a[i];
            for (i = n; i < lena; i++)
                b[lena - 1 + n - i] = a[i];//b[lena-1+(n-i)]
        }
        b[lena] = '\0';
        puts(b);
    }
}
