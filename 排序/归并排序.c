#include <stdio.h>
#include <stdlib.h>
void fun(int *a, int low, int high)
{
    int index = 0, size = high - low + 1;
    int mid = (low + high) / 2, l = low, h = mid + 1;
    int *temp = (int *)malloc(sizeof(int) * size);
    while (l <= mid && h <= high)
    {
        if (a[l] <= a[h])
            temp[index++] = a[l++];
        else
            temp[index++] = a[h++];
    }
    while (l <= mid)
        temp[index++] = a[l++];
    while (h <= high)
        temp[index++] = a[h++];
    for (index = 0; index < size; index++)
        a[low + index] = temp[index];
    free(temp);
}
void sort(int *a, int low, int high)
{
    if (low < high) //至少两个元素
    {
        int mid = (low + high) / 2;
        sort(a, low, mid);      //左半部分
        sort(a, mid + 1, high); //右半部分
        fun(a, low, high);      //左右归并
    }
}
int main(void)
{
    int n;
    while (~scanf("%d", &n))
    {
        int *arry = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
            scanf("%d", arry + i);
        sort(arry, 0, n - 1);
        free(arry);
    }
}