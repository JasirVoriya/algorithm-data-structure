#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int data[5] = {81, 27, 9, 3, 1}, x;
    set<int> s[5];
    vector<int> v[5][122];
    v[0][81].push_back(1), s[0].insert(81);
    v[0][0].push_back(0), s[0].insert(0);
    for (int i = 1; i < 5; i++)
    {
        for (auto it = s[i - 1].begin(); it != s[i - 1].end(); it++)
        {
            x = *it - data[i];
            if (x > 0)
                s[i].insert(x), v[i][x] = v[i - 1][*it], v[i][x].push_back(-1);

            x = *it;
            s[i].insert(x), v[i][x] = v[i - 1][*it], v[i][x].push_back(0);

            x = *it + data[i];
            s[i].insert(x), v[i][x] = v[i - 1][*it], v[i][x].push_back(1);
        }
    }
    int n;
    while (cin >> n)
    {
        vector<int> &ans = v[4][n];
        int i = 0;
        while (ans[i] == 0)
            i++;
        cout << ans[i] * data[i];
        for (i++; i < ans.size(); i++)
        {
            if (ans[i] == 1)
                cout << "+" << data[i];
            else if (ans[i] == -1)
                cout << "-" << data[i];
        }
        cout << endl;
    }
    return 0;
}