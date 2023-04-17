#include <stdio.h>
#include <bits/stdc++.h>
void input(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
void output(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
void huan(int a[], int n)
{
    int i, j, min, max;
    for (i = 0; i < n; i++)
    {
        min = 0;
        if (a[i] < a[min])
        {
            min = i;
        }
        j = a[0];
        a[0] = a[min];
        a[min] = j;
    }
    for (i = 9; i >= 0; i--)
    {
        max = 9;
        if (a[i] > a[max])
        {
            max = i;
        }
        j = a[9];
        a[9] = a[max];
        a[max] = j;
    }
}
char *mystrcpy(char *str1, const char *str2, int m)
{
    int len = 0;
    while (str2[len])
        len++;
    if (m > len)
        return *str1 = '\0', str1;
    str2 += m - 1;
    char *a = str1;
    while (*str2)
        *str1++ = *str2++;
    *str1 = '\0';
    return a;
}
int num(char *str, int *a)
{
    int count = 0;
    while (*str)
    {
        if (*str >= '0' && *str <= '9')
        {
            int t = 0;
            while (*str && *str >= '0' && *str <= '9')
            {
                t = t * 10 + *str - '0';
                *str++;
            }
            a[count++] = t;
            str--;
        }
        str++;
    }
    return count;
}
int main()
{
    int a[100];
    input(a, 10);
    huan(a, 10);
    output(a, 10);
    printf("\n");
    char str[100];
    printf("%s\n", mystrcpy(str, "qwertyuiop", 20));
    char str2[] = "123rrr243rw2re3";
    int count = num(str2, a);
    output(a, count);
}
