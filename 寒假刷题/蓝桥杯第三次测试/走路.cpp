#include <bits/stdc++.h>
using namespace std;
const int INF = unsigned(-1) >> 1;
const int maxn = 1e3 + 10;
int n, m;
struct Dis
{
    int d, c;
};
Dis d[maxn];
struct Edge
{
    int x, y, d, c;
};
Edge es[100000 + 10];
void fun(int s)
{
    for (int i = 1; i <= n; i++)
        d[i].c = d[i].d = INF;
    bool updata = false;
    d[s].c = d[s].d = 0;
    while (true)
    {
        updata = false;
        for (int i = 1; i <= m; i++)
        {
            Edge e = es[i];
            if (d[e.x].d > d[e.y].d)
                swap(e.x, e.y);
            if (d[e.x].d != INF)
            {
                if (d[e.x].d + e.d < d[e.y].d)
                {
                    d[e.y].d = d[e.x].d + e.d;
                    d[e.y].c = d[e.x].c + e.c;
                    updata = true;
                }
                else if (d[e.y].d + e.d == d[e.x].d && d[e.x].c + e.c < d[e.y].c)
                {
                    d[e.y].c = d[e.x].c + e.c;
                    updata = true;
                }
            }
            // if (d[e.y].d != INF)
            // {
            //     if (d[e.y].d + e.d < d[e.x].d)
            //     {
            //         d[e.x].d = d[e.y].d + e.d;
            //         d[e.x].c = d[e.y].c + e.c;
            //         updata = true;
            //     }
            //     else if (d[e.y].d + e.d == d[e.x].d && d[e.y].c + e.c < d[e.x].c)
            //     {
            //         d[e.x].c = d[e.y].c + e.c;
            //         updata = true;
            //     }
            // }
        }
        if (updata == false)
            break;
    }
}
int main(void)
{
    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            return 0;
        for (int i = 1; i <= m; i++)
            cin >> es[i].x >> es[i].y >> es[i].d >> es[i].c;
        int s, t;
        cin >> s >> t;
        fun(s);
        cout << d[t].d << " " << d[t].c << endl;
    }
    return 0;
}