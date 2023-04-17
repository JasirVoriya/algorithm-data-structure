#include <bits/stdc++.h>
using namespace std;
const int INF = unsigned(-1) >> 1;
const int maxn = 1e3 + 10;
int n, m, h;
typedef int Dis;
Dis d1[maxn];
Dis d2[maxn];
Dis d3[maxn];
struct Edge
{
    int x, y, d;
};
Edge es[100000 + 10];
void fun1(Dis *d)//去
{
    memset(d, 0, sizeof(Dis) * maxn);
    d[h] = INF;
    bool updata = false;
    while (true)
    {
        updata = false;
        for (int i = 1; i <= m; i++)
        {
            Edge e = es[i];
            if (d[e.x] != INF)
            {
                if (d[e.x] + e.d < d[e.y])
                {
                    d[e.y] = d[e.x] + e.d;
                    updata = true;
                }
            }
        }
        if (updata == false)
            break;
    }
}
void fun2(Dis *d)//回
{
    for (int i = 1; i <= n; i++)
        d[i] = INF;
    bool updata = false;
    d[h] = 0;
    while (true)
    {
        updata = false;
        for (int i = 1; i <= m; i++)
        {
            Edge e = es[i];
            if (d[e.x] != INF)
            {
                if (d[e.x] + e.d < d[e.y])
                {
                    d[e.y] = d[e.x] + e.d;
                    updata = true;
                }
            }
        }
        if (updata == false)
            break;
    }
}
int main(void)
{
    cin >> n >> m >> h;
    for (int i = 1; i <= m; i++)
        cin >> es[i].x >> es[i].y >> es[i].d;
    fun1(d1);
    fun2(d2);
    for (int i = 1; i <= n; i++)
        d3[i] = d1[i] + d2[i];
    sort(d3 + 1, d3 + 1 + n);
    cout << d3[n] << endl;
    return 0;
}