/*
问题 L: 最值
描述
有一个长度为n的整数序列。请写一个程序，先把序列中的最小值与第一个数交换，然后最大值与最后一个数交换。输出转换好的序列。 

格式
输入格式
输入包括两行。 
第一行为正整数n（1≤n≤10）。 
第二行为n个正整数组成的序列。 

输出格式
输出转换好的序列。数据之间用空格隔开。 

样例
样例输入 Copy
5
2 1 5 4 3
样例输出 Copy
1 2 3 4 5		
*/
#include <stdio.h>
#include <stdlib.h>
#define swap(x, y)             \
    {                          \
        int te;                \
        te = x, x = y, y = te; \
    }
void sort(int n)
{
    int *a = (int *)malloc(sizeof(int) * n);
    int i, j, t;
    scanf("%d", a);
    j = t = 0;
    for (i = 1; i < n; i++)
    {
        scanf("%d", a + i);
        if (a[i] > a[t])
            t = i;
        else if (a[i] < a[j])
            j = i;
    }
    if (t == 0 && j == n - 1) //双错位
    {
        swap(a[0], a[j]);
    }
    else if (t == 0) //最大值错位
    {
        swap(a[n - 1], a[t]);
        swap(a[0], a[j]);
    }
    else //最小值错位或者没有错位
    {
        swap(a[0], a[j]);
        swap(a[n - 1], a[t]);
    }

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 0 || n >= 11)
        return 0;
    sort(n);
}