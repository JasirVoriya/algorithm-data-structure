#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int q;
    cin >> q;
    string x, y;
    map<string, string> m;
    while (q--)
    {
        cin >> x >> y;
        auto it = m.find(x);
        if (it != m.end())
        {
            m[y] = it->second;
            m.erase(it->first);
        }
        else
            m[y] = x;
    }
    cout << m.size() << endl;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->second << " " << it->first << endl;
    }

    return 0;
}