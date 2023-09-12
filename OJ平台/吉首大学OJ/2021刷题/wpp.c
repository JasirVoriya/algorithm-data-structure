#include <stdio.h>
#include <string.h>
int main()
{
    int a[100], b[100], c[100], i, sum;
    char s1[100], s2[100];
    int L1, L2, na, nb, nc;
    scanf("%d", &sum);
    while (sum--)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c)); //数组清零
        scanf("%s%s", s1, s2);   //读入字符串s1和s2，并转换成a和b数组，用c数组存放数组和b数组的和
        L1 = strlen(s1);
        L2 = strlen(s2);
        for (i = 0; i < L1; i++)
            a[i] = s1[L1 - i - 1] - '0'; //字符转数值反向存储
        na = L1;
        for (i = 0; i < L2; i++)
            b[i] = s2[L2 - i - 1] - '0'; //字符转数值反向存储
        nb = L2;

        if (na > nb)
            nc = na;
        else
            nc = nb;
        for (i = 0; i < nc; i++)
        {
            c[i] = c[i] + a[i] + b[i]; //计算c=a+b
            c[i + 1] += c[i] / 10;     //进位
            c[i] = c[i] % 10;          //进位后的数值
        }
        if (c[i])
            nc++;

        for (i = nc - 1; i >= 0; i--) //输出c数组

            printf("%d", c[i]);
        printf("\n");
    }
}
