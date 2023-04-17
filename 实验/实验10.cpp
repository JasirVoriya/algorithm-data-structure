#include <stdio.h>
#include <ctype.h>
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    return;
}
void print(int *array, int n)
{
    int *begin = array, *end = array + n;
    for (int *it = begin; it < end; it++)
        printf("%d ", *it);
    putchar('\n');
    return;
}
void fun1(int *a, int n)
{
    int *begin = a, *end = a + n;
    int *max = a, *min = a;
    for (int *it = begin; it < end; it++)
    {
        if (*it > *max) max = it;
        else if (*it < *min) min = it;
    }
    swap(min, begin);
    if (max == begin) max = min;
    swap(max, end - 1);
    return;
}
void fun2(char *str1, const char *str2, int n)
{
    const char *str3 = str2;
    while (*str3) str3++;
    if (str3 - str2 < n) return;
    str2 += n - 1;
    while (*str2) *str1++ = *str2++;
    *str1 = '\0';
    return;
}
int fun3(int *num, const char *str)
{
    int count = 0;
    while (*str)
    {
        if (*str>='0'&&*str<='9')
        {
            *(num + count) = 0;
            while (*str>='0'&&*str<='9')
            {
                *(num + count) = *(num + count) * 10 + *str - '0';
                str++;
            }
            str--,count++;
        }
        str++;
    }
    return count;
}
int main(void)
{
    int array[] = {9, 5, 3, 8, 1, 2, 6, 4, 7, 0};
    fun1(array, sizeof(array) / sizeof(int));
    print(array, sizeof(array) / sizeof(int));
    char str[20];
    fun2(str, "123456789qwertyuiop", 10);
    puts(str);
    char str2[100] = "123fdaffa213fg1g3";
    int num[20];
    int count = fun3(num, str2);
    print(num,count);
    return 0;
}