// 问题 A: 牛牛子在睡觉
// 描述
// 牛牛子经常学到很晚，导致白天睡觉，上帝看到了，就往牛子爷那里丢水果。
// 不同的水果砸到睡觉的牛子爷，牛子爷会发出不同的叫声。
// 上帝一共会丢四种水果：苹果、香蕉、梨子和草莓。
// 苹果砸到牛子爷会发出“哎呀”，香蕉会发出“啊呀”，梨子会发出“啊嘞”，草莓会发出“呀嘞”。
// 
// 格式
// 输入格式
// 输入一行长度为n（1<=n<=1000）的字符串，字符串表示上帝丢下来的水果，A表示苹果，B表示香蕉，P表示梨子，S表示草莓。
// 
// 输出格式
// 输出n行，每行表示牛子爷被对应水果砸到的反应。
// 
// 样例
// 样例输入 Copy
// ABPSPSABAAPSPS
// 
// 样例输出 Copy
// 牛子爷：“哎呀！”
// 牛子爷：“啊呀！”
// 牛子爷：“啊嘞！”
// 牛子爷：“呀嘞！”
// 牛子爷：“啊嘞！”
// 牛子爷：“呀嘞！”
// 牛子爷：“哎呀！”
// 牛子爷：“啊呀！”
// 牛子爷：“哎呀！”
// 牛子爷：“哎呀！”
// 牛子爷：“啊嘞！”
// 牛子爷：“呀嘞！”
// 牛子爷：“啊嘞！”
// 牛子爷：“呀嘞！”


#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n, m;
    ifstream cin;
    ofstream cout;
    cin.open("test1.in");
    cout.open("test1.out");
    string str;
    cin >> str;
    for (auto ch : str) {
        switch (ch) {
        case 'A':
            cout << "牛子爷：“哎呀！”" << endl;
            break;
        case 'B':
            cout << "牛子爷：“啊呀！”" << endl;
            break;
        case 'P':
            cout << "牛子爷：“啊嘞！”" << endl;
            break;
        case 'S':
            cout << "牛子爷：“呀嘞！”" << endl;
            break;
        }
    }
    return 0;
}