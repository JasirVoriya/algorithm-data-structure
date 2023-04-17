#include <bits/stdc++.h>
using namespace std;
const int maxe = 100100, maxv = 1100;
const int INF = unsigned(-1) >> 1;
int n, m, s, t;
struct edge
{
    int x, y;
};
edge es[maxe];
struct Graph
{
    int dis;
};
Graph G[maxv][maxv];
struct dist
{
    int dis;
};
dist d[maxv];
void fun(int s)
{
    for (int i = 0; i <= n; i++)
        d[i].dis = INF;
    d[s].dis = 0;
    while (true)
    {
        bool updata = false;
        for (int i = 0; i < m; i++) 
        {
            edge e = es[i];
            if (d[e.x].dis != INF) 
            {
                if (d[e.x].dis + G[e.x][e.y].dis < d[e.y].dis) 
                {
                    d[e.y].dis = d[e.x].dis + G[e.x][e.y].dis; 
                    updata = true;
                }
            }
            if (d[e.y].dis != INF) 
            {
                if (d[e.y].dis + G[e.x][e.y].dis < d[e.x].dis) 
                {
                    d[e.x].dis = d[e.y].dis + G[e.x][e.y].dis; 
                    updata = true;
                }
            }
        }
        if (updata == false) 
            break;
    }
}
int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                G[i][j].dis = INF;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &es[i].x, &es[i].y);
                G[es[i].x][es[i].y].dis = G[es[i].y][es[i].x].dis = 1;
        }
        scanf("%d%d", &s, &t);
        fun(s);
        if (d[t].dis == INF)
            puts("!");
        else
            printf("%d\n", d[t].dis);
    }
    return 0;
}