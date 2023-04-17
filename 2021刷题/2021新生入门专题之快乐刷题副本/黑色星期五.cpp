// 问题 A: 黑色星期五
// 描述
// 13号又是星期五是一个不寻常的日子吗? 13号在星期五比在其他日少吗?为了回答这个问题,写一个程序来计算在n年里13 日落在星期一,星期二......星期日的次数.这个测试从1900年1月1日到 1900+n-1年12月31日.n是一个非负数且不大于400. 这里有一些你要知道的: 1900年1月1日是星期一. 4,6,11和9月有30天.其他月份除了2月有31天.闰年2月有29天,平年2月有28天. 年份可以被4整除的为闰年(1992=4*498 所以 1992年是闰年,但是1990年不是闰年) 以上规则不适合于世纪年.可以被400整除的世纪年为闰年,否则为平年.所以,1700,1800,1900和2100年是平年,而2000年是闰年. 请不要预先算好数据!

// 格式
// 输入格式
// 一个整数n.

// 输出格式
// 七个在一行且相分开的整数,它们代表13日是星期六,星期日,星期一.....星期五的次数.

// 样例
// 样例输入 Copy
// 20
// 样例输出 Copy
// 36 33 34 33 35 35 34
#include <bits/stdc++.h>
using namespace std;
bool IsLeap(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
int Date(int year, int month)
{
    if (month == 2)
        return 28 + IsLeap(year);
    for (int m : vector<int> { 1, 3, 5, 7, 8, 10, 12 })
        if (m == month)
            return 31;
    return 30;
}
int main(void)
{
    int n;
    cin >> n;
    int x = 6;
    for (int year = 1990; year < n; year++) {
        for (int month = 1; month <= 12; month++) {
            int day = Date(year, month);
        }
    }
    return 0;
}