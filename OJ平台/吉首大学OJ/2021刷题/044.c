/*
问题 D: 求逆序数
描述
在一个排列中，如果一对数的前后位置与大小顺序相反，即前面的数大于后面的数，那么它们就称为一个逆序。一个排列中逆序的总数就称为这个排列的逆序数。

现在，给你一个N个元素的序列，请你判断出它的逆序数是多少。

比如 1 3 2 的逆序数就是1。

格式
输入格式
第一行输入一个整数T表示测试数据的组数（1<=T<=5)
每组测试数据的每一行是一个整数N表示数列中共有N个元素（2〈=N〈=100000）
随后的一行共有N个整数Ai(0<=Ai<1000000000)，表示数列中的所有元素。

数据保证在多组测试数据中，多于10万个数的测试数据最多只有一组。

输出格式
输出该数列的逆序数

样例
样例输入 Copy
2
2
1 1
3
1 3 2
样例输出 Copy
0
1
*/
#include <stdio.h>
#include <stdlib.h>
long long  sum = 0;//全局变量，逆序数
void fun(long long *a, int low, int high)
{
    int index = 0, size = high - low + 1;
    int mid = (low + high) / 2, l = low, h = mid + 1;
    long long *temp = (long long *)malloc(sizeof(long long) * size);
    while (l <= mid && h <= high)
    {
        if (a[l] <= a[h])
            temp[index++] = a[l++];
        else
            temp[index++] = a[h++], sum += mid - l + 1;//逆序数增加
    }
    while (l <= mid)
        temp[index++] = a[l++];
    while (h <= high)
        temp[index++] = a[h++];
    for (index = 0; index < size; index++)
        a[low + index] = temp[index];
    free(temp);
}
void sort(long long  *a, int low, int high)
{
    if (low < high)//至少两个元素
    {
        int mid = (low + high) / 2;
        sort(a, low, mid);//左半部分
        sort(a, mid + 1, high);//右半部分
        fun(a, low, high);//左右归并
    }
}
int main(void)
{
    int n, t, i;
    long long *arry;
    scanf("%d", &t);//组数
    while (t--)
    {
        sum = 0;
        scanf("%d", &n);
        arry = (long long *)malloc(sizeof(long long) * n);
        for (i = 0; i < n; i++)
            scanf("%lld", arry + i);
        sort(arry, 0, n - 1);//归并排序
        printf("%lld\n", sum);//逆序数
        free(arry);
    }
}