// 问题 A: 牛牛子当体委的那些年
// 描述
// 牛牛子是一个非常善解人意的人，在牛牛子当体委的那些年，经常会有人体育课找他请假。牛牛子非常理解当代大学生的想法，都给他们批假了。
// 题目要求统计一个由字母A、B组成的字符串，表示一节体育课的出勤情况，A代表正常上课，B代表请假，请你帮牛子爷统计一下，每节课一共有多少人请假。

// 格式
// 输入格式
// 第一行两个个整形n、m（1<=n,m<=100），n表示需要统计n节体育课的出勤情况，m表示牛子爷班上一共有m个人。
// 接下来有n行，每行有m个A、B字符字符，表示一节体育课的出勤情况。

// 输出格式
// 一共有n行，每行一个数字，表示n节体育课请假的人数。

// 样例
// 样例输入 Copy
// 3 10
// ABAABAAABA
// AAAAAAAAAA
// BBBBBBBBBB
// 样例输出 Copy
// 3
// 0
// 10

#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        cout << count(str.begin(), str.end(), 'B') << endl;
    }
    return 0;
}