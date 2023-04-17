/*
问题 B: 字符串改造（串）
描述
一个字符串，存放在一个数组中，编程序将其改造之后输出：

（1）将S的所有第偶数个字符按照从大到小的次序放在S的后半部分；

（2）将S的所有第奇数个字符按照从小到大的次序放在S的前半部分；

格式
输入格式
输入一个字符串

输出格式
输出改造后的字符串

样例
样例输入 Copy
ABCDEFGHIJKL
样例输出 Copy
ACEGIKLJHFDB
*/
#include <stdio.h>
#include <string.h>
void sort(char *a, int n, int s)
{
    int i, j;
    char t;
    if (s)
    {
        for (i = 1; i < n; i++)
        {
            t = a[i];
            for (j = i - 1; j >= 0 && a[j] < t; j--)
                a[j + 1] = a[j];
            a[j + 1] = t;
        }
    }
    else
    {
        for (i = 1; i < n; i++)
        {
            t = a[i];
            for (j = i - 1; j >= 0 && a[j] > t; j--)
                a[j + 1] = a[j];
            a[j + 1] = t;
        }
    }
}
int main()
{
    char a[1000], b[1000];
    int i, j, len, len2;
    scanf("%s", a), len = strlen(a);
    for (j = i = 0; i < len; i += 2)
        b[j++] = a[i];
    b[len2 = j] = 0;
    for (i = 1, j = 0; i < len; i += 2)
        a[j++] = a[i];
    a[len = j] = 0;
    sort(a, len, 1), sort(b, len2, 0);
    printf("%s%s\n", b, a);
}