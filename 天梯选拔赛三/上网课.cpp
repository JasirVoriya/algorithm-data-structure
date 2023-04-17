#include <bits/stdc++.h>
using namespace std;
const int maxn = 25005;
const int maxt = 1e6 + 5;
int main(void)
{
    pair<int, int> tools[maxn];
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> tools[i].second >> tools[i].first;
    }
    sort(tools, tools + n);
    pair<int, int> temp = tools[0];
    int ans = 1;
    if (temp.first >= t)
    {
        cout << ans << endl;
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        // cout << temp.first << endl;
        if (temp.first >= tools[i].second)
            temp = tools[i], ans++;
        else
            break;
        if (temp.first >= t)
        {
            cout << ans << endl;
            return 0;
        }
    }
    cout << "xie'e" << endl;
    return 0;
}