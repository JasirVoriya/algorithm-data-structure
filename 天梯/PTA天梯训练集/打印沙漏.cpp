#include <bits/stdc++.h>
using namespace std;
string put_ch(char ch, int cnt)
{
    string str;
    while (cnt--)
        str.push_back(ch);
    return str;
}
void solove(int h, char ch, int ch_cnt, int space_cnt)
{
    if (h == 1) {
        cout << put_ch(' ', space_cnt) << put_ch(ch, ch_cnt) << endl;
        return;
    }
    cout << put_ch(' ', space_cnt) << put_ch(ch, ch_cnt) << endl;
    solove(h - 1, ch, ch_cnt - 2, space_cnt + 1);
    cout << put_ch(' ', space_cnt) << put_ch(ch, ch_cnt) << endl;
}
int main(void)
{
    int n;
    char ch;
    cin >> n >> ch;
    int i = 3, h = 1;
    while ((i + 3) * h + 1 <= n)
        i += 2, h++;
    i -= 2;
    solove(h, ch, i, 0);
    cout << n - ((i + 3) * (h - 1) + 1)<<endl;
    return 0;
}