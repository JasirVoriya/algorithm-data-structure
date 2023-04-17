#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
    ll x, y, z;
    cin >> x >> y >> z;
    set<ll> s[13];
    s[0].insert(0);
    for (ll i = 1; i < 13; i++)
    {
        for (auto it = s[i - 1].begin(); it != s[i - 1].end(); it++)
        {
            s[i].insert(*it + x);
            s[i].insert(*it - x);
            //
            s[i].insert(*it + y);
            s[i].insert(*it - y);
            //
            s[i].insert(*it + z);
            s[i].insert(*it - z);
        }
    }
    ll begin = 0;
    ll q;
    cin >> q;
    while (q--)
    {
        ll end;
        cin >> end;
        ll o = end - begin;
        if (s[12].count(o))
        {
            puts("YES");
            begin = o > 0 ? o : -o;
        }
        else
        {
            puts("NO");
            begin = 0;
        }
    }
    return 0;
}