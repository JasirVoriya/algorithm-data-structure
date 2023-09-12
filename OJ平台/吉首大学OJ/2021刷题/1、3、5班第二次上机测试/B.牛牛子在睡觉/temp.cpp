#include <bits/stdc++.h>
using namespace std;
// 输入一行长度为n（1<=n<=1000）的字符串，字符串表示上帝丢下来的水果，A表示苹果，B表示香蕉，P表示梨子，S表示草莓。
int main(void)
{
    ofstream cout;
    cout.open("test1.in");
    srand(time(NULL));
    int n = rand() % 1000 + 1;
    char str[4] = { 'A', 'B', 'P', 'S' };
    for (int i = 0; i < n; i++) {
        cout << str[rand() % 4];
    }
    return 0;
}