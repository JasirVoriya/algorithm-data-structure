#include <bits/stdc++.h>
using namespace std;
struct member
{
    string name;
    int score[15];
    int res = 0;
    bool operator<(const member &a) const
    {
        if (res == a.res)
            return name < a.name;
        return res > a.res;
    }
};
struct team
{
    string teamname;
    member mem[10];
    int sum1, sum2, sum3;
    int res;
    bool operator<(const team &a) const
    {
        if (res == a.res)
            return teamname < a.teamname;
        return res > a.res;
    }
    team(set<member> &m)
    {
        sum1 = sum2 = sum3 = res = 0;
        cin >> teamname;
        for (int i = 0; i < 10; i++)
        {
            cin >> mem[i].name;
            for (int k = 0; k < 15; k++)
            {
                cin >> mem[i].score[k];
                mem[i].res += mem[i].score[k];
                if (k < 8)
                    sum1 += mem[i].score[k];
                else if (k < 12)
                    sum2 += mem[i].score[k];
                else
                    sum3 += mem[i].score[k];
            }
            m.insert(mem[i]);
        }
        res += sum1;
        if (sum1 >= 800)
        {
            res += sum2;
            if (sum2 >= 400)
                res += sum3;
        }
    }
};
int main(void)
{
    int n, c = 0;
    cin >> n;
    set<team> t;
    set<member> m;
    for (int i = 1; i <= n; i++)
    {
        team tt(m);
        t.insert(tt);
    }
    //
    auto it = t.begin();
    int i = 2, rank = 1, res = it->res;
    cout << it->teamname << ' ' << it->sum1 << ' ' << it->sum2 << ' ' << it->sum3 << ' ' << it->res << ' ' << rank << endl;
    for (it++; it != t.end(); it++)
    {
        if (it->res != res)
            rank = i;
        cout << it->teamname << ' ' << it->sum1 << ' ' << it->sum2 << ' ' << it->sum3 << ' ' << it->res << ' ' << rank << endl;
        res = it->res;
        i++;
    }
    //
    int max = m.begin()->res;
    cout << max;
    for (auto it = m.begin(); it != m.end() && it->res == max; it++)
        cout << ' ' << it->name;
    return 0;
}