#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e6;
int cnt;
bool IsDouble;
char ans[maxn];
char str[maxn];
void fun(int i, int j)
{
    if (i > j)
        return;
    if (i == j)
    {
        IsDouble = false;
        ans[cnt++] = str[i];
        return;
    }
    if (str[i] != str[j])
    {
        ans[cnt++] = str[i];
        fun(i + 1, j);
    }
    else
    {
        ans[cnt++] = str[i];
        fun(i + 1, j - 1);
    }
}
int main(void)
{
    while (cin >> str)
    {
        cnt = 0;
        IsDouble = true;
        fun(0, strlen(str) - 1);
        for (int i = 0; i < cnt; i++)
            cout << ans[i];
        if (!IsDouble)
            cnt--;
        while (--cnt >= 0)
            cout << ans[cnt];
        cout << endl;
    }
    return 0;
}