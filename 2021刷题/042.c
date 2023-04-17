/*
问题 A: 对，就是那道讲过的题！
描述
给定一个非递减的序列a1,a2,......,an,(ai≤ai+1)。
找到三个索引 i,j,k (1≤i<j<k≤n),ai,aj,ak不可能构成一个非退化三角形（三点不共线的普通三角形）
例如：3,4,5可以构成一个非退化三角形但3,4,7不可能构成一个非退化三角形。

格式
输入格式
第一行输入一个整数T (1≤T≤1000）代表测试数据组数
每组测试的第一行输入一个整数n（3≤n≤5×104）表示给定序列的长度
第二行包括n个整数a1,a2,......,an（1≤ai≤109；ai-1≤ai）代表给定序列

输出格式
对于每组测试数据输出一行。
如果能找到三个索引 i,j,k (1<i<j<k≤n),ai,aj,ak不可能构成一个非退化三角形，
按升序打印三个索引。如果有多个答案，请打印其中的任何一个。
否则输出-1。

样例
样例输入 Copy
3
7
4 6 11 11 15 18 20
4
10 10 10 11
3
1 1 1000000000
样例输出 Copy
2 3 6
-1
1 2 3		
提示
在第一个测试案例中，侧面6、11和18是不可能的。请注意，这不是唯一的正确答案。
在第二个测试用例中，您始终可以构造一个非退化三角形。 
*/
#include <stdio.h>
int main(void)
{
    int t, n, s;
    long long i, j, k;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        scanf("%lld%lld", &i, &j);
        for (s = 2; s < n; s++)
            scanf("%lld", &k);
        if (i + j <= k)
            printf("1 2 %d\n", n);
        else
            puts("-1");
    }
}