/*
问题 I: 分治法求最大值和最小值
描述
给定若干个整数，要求使用分治算法求出最大值和最小值。
格式
输入格式
输入只包括若干个用例，每个用例占两行，第一行为整数个数n(1<=n<=100)。第二行为n个整数
输出格式
每个用例用一行输出其最小值和最大值，用空格隔开。
样例
样例输入 Copy
2
5
9 5 7 3 10
10
1 2 3 6 5 4 7 8 9 0
样例输出 Copy
3 10
0 9
*/
#include <stdio.h>
int main(void)
{
    int i, t, s, n, min, max;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &s);
        scanf("%d", &n);
        min = max = n;
        i = 1;
        while (i < s)
        {
            scanf("%d", &n);
            if (n > max)
                max = n;
            else if (n < min)
                min = n;
            i++;
        }
        printf("%d %d\n", min, max);
    }
}