#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    pair<int, int> s[1005];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i].second >> s[i].first;
    }
    sort(s, s + n);
    int ans = 1;
    pair<int, int> pre = s[0];
    for (int i = 1; i < n; i++)
    {
        if (pre.first <= s[i].second)
            pre = s[i], ans++;
    }
    cout << ans;
    return 0;
}