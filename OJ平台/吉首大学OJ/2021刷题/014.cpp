/*
问题 D: 和排序
描述
给定n个正整数，根据各位数字之和从小到大进行排序,如果数字之和相同，则按给定正整数从小到大排序。

格式
输入格式
输入数据有多组，每组数据占一行，每行的第一个数正整数n，表示整数个数，后面接n个正整数。当n为0时，不作任何处理，输入结束。 

输出格式
输出每组排序的结果。

样例
样例输入 Copy
2 1 2
3 121 10 111
0
样例输出 Copy
1 2
10 111 121
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct data
{
    int a, b;
} data;
int fun(int n)
{
    int sum = 0;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
void swap(data *x, data *y)
{
    data t = *x;
    *x = *y;
    *y = t;
}
void sort(data *s, int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (s[min].b > s[j].b || s[min].b == s[j].b && s[min].a > s[j].a)
                min = j;
        if (min != i)
            swap(s + min, s + i);
    }
    return;
}
void print(data *s, int n)
{
    int i;
    for (i = 0; i < n; i++, s++)
        printf("%d ", s->a);
    putchar('\n');
}
int main(void)
{
    data *s = NULL;
    int i, n;
    while (scanf("%d", &n), n > 0)
    {
        s = (data *)malloc(sizeof(data) * n);
        for (i = 0; i < n; i++)
        {
            scanf("%d", &s[i].a);
            s[i].b = fun(s[i].a);
        }
        sort(s, n);
        print(s, n);
        free(s);
    }
}