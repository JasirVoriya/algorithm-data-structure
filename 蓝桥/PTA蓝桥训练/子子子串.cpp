#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
int vis[maxn][maxn] = {0};
string str1, str2;
int solove(int a, int b)
{
    if (a < 0 || b < 0)
        return 0;
    if (vis[a][b])
        return vis[a][b];
    if (str1[a] != str2[b])
        return vis[a][b] = max(solove(a - 1, b), solove(a, b - 1));
    return vis[a][b] = solove(a - 1, b - 1) + 1;
}
int main(void)
{
    cin >> str1 >> str2;
    cout<<solove(str1.size() - 1, str2.size() - 1);
    // cout << vis[str1.size() - 1][str2.size() - 1];
    return 0;
}