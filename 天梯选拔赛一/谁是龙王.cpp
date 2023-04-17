#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    map<string, int> m;
    string name;
    cin >> n;
    while (n--)
    {
        cin >> name;
        m[name]++;
    }
    auto it = m.begin();
    string ans = it->first;
    it++;
    while (it != m.end())
    {
        if (m[ans] < it->second)
        {
            ans = it->first;
        }
        it++;
    }
    cout << ans;
}