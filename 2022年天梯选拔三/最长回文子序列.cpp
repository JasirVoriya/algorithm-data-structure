#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e4;
const int INF = 0x3f3f3f3f;
typedef long long ll;
string str;
int dp[MAX_N][MAX_N];
int solove(int l, int r)
{
    if (l == r)
        return 1;
    if (l > r)
        return 0;
    if (dp[l][r])
        return dp[l][r];
    if (str[l] == str[r])
        return dp[l][r] = solove(l + 1, r - 1) + 2;
    return dp[l][r] = max(max(solove(l + 1, r), solove(l, r - 1)), solove(l + 1, r - 1));
}
int main(void)
{
    cin >> str;
    cout << solove(0, str.size() - 1) << endl;
    return 0;
}