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
    for (int i = 0; i < n; i++)
        d[i].dis = INF;
    d[s].dis = 0;
    while (true)
    {
        bool updata = false;
        for (int i = 0; i < m; i++) //遍历所有的边
        {
            edge e = es[i];
            if (d[e.x].dis != INF) //如果遍历过e.x点
            {
                if (d[e.x].dis + G[e.x][e.y].dis < d[e.y].dis) //如果从e.x点走到e.y点的路径 比 其他点走到e.y的路径要短
                {
                    d[e.y].dis = d[e.x].dis + G[e.x][e.y].dis; //更新e.y的路径为更短的
                    updata = true;
                }
            }
            if (d[e.y].dis != INF) //如果遍历过e.y点
            {
                if (d[e.y].dis + G[e.x][e.y].dis < d[e.x].dis) //如果从e.y点走到e.x点的路径 比 其他点走到e.x的路径要短
                {
                    d[e.x].dis = d[e.y].dis + G[e.x][e.y].dis; //更新e.x的路径为更短的
                    updata = true;
                }
            }
        }
        if (updata == false) //如果所有的边都遍历过了，路径信息没有更新过，说明已经遍历完了，结束搜索
            break;
    }
}
int main()
{
    while (scanf("%d%d", &n, &m) != EOF)
    {
        int dis;
        if (n == 0 && m == 0)
            break;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                G[i][j].dis = INF;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &es[i].x, &es[i].y, &dis);
            if (dis < G[es[i].x][es[i].y].dis)
                G[es[i].x][es[i].y].dis = G[es[i].y][es[i].x].dis = dis;
        }
        scanf("%d%d", &s, &t);
        fun(s);
        if (d[t].dis == INF)
            puts("-1");
        else
            printf("%d\n", d[t].dis);
    }
    return 0;
}