/*
1030: C语言实验题——某年某月的天数(JSU-ZJJ)
描述
输入年和月，判断该月有几天？

格式
输入格式
输入年和月，格式为年月

输出格式
输出该月的天数。

样例
样例输入 Copy
2009\1
样例输出 Copy
31
*/
#include <stdio.h>
int main()
{
    int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, month;
    scanf("%d\\%d", &year, &month);
    if (year < 0 || month < 0 || month > 12)
        return 1;

    if (month == 2)
        if (year % 4 == 0 && year % 100 || year % 400 == 0)
            a[1]++;
    printf("%d", a[month - 1]);
}
