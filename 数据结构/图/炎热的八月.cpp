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
    int dis, cost;
};
Graph G[maxv][maxv];
struct dist
{
    int dis, cost;
};
dist d[maxv];
void fun(int s)
{
    for (int i = 1; i <= n; i++)
        d[i].dis = d[i].cost = INF;
    d[s].dis = d[s].cost = 0;
    while (true)
    {
        bool updata = false;
        for (int i = 0; i < m; i++) //遍历所有的边
        {
            edge e = es[i];
            if (d[e.x].dis > d[e.y].dis)//我们只需要更新x、y中较远那个点。
                swap(e.x, e.y);
            // printf("%d:%d %d ->%d:%d %d\n", e.x, d[e.x].dis, d[e.x].cost, e.y, d[e.x].dis + G[e.x][e.y].dis, d[e.x].cost + G[e.x][e.y].cost);
            if (d[e.x].dis != INF) //如果遍历过e.x点
            {
                if (d[e.x].dis + G[e.x][e.y].dis < d[e.y].dis) //如果从e.x点走到e.y点的路径 比 其他点走到e.y的路径要短
                {
                    d[e.y].dis = d[e.x].dis + G[e.x][e.y].dis;    //更新e.y的路径为更短的
                    d[e.y].cost = d[e.x].cost + G[e.x][e.y].cost; //花费也要更新
                    // printf("%d->%d: %d %d\n", e.x, e.y, d[e.y].dis, d[e.y].cost);
                    updata = true;
                }
                else if (d[e.x].dis + G[e.x][e.y].dis == d[e.y].dis) //如果从e.x点走到e.y点的路径 和 其他点走到e.y的路径一样长
                {
                    if (d[e.x].cost + G[e.x][e.y].cost < d[e.y].cost) //就取花费最小的路
                    {
                        d[e.y].cost = d[e.x].cost + G[e.x][e.y].cost;
                        // printf("%d->%d: %d %d\n", e.x, e.y, d[e.y].dis, d[e.y].cost);
                        updata = true;
                    }
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
        int dis, cost;
        if (n == 0 && m == 0)
            break;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                G[i][j].dis = G[i][j].cost = INF;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d%d", &es[i].x, &es[i].y, &dis, &cost);
            if (dis < G[es[i].x][es[i].y].dis)
            {
                G[es[i].x][es[i].y].dis = G[es[i].y][es[i].x].dis = dis;
                G[es[i].x][es[i].y].cost = G[es[i].y][es[i].x].cost = cost;
            }
            else if (dis == G[es[i].x][es[i].y].dis && cost < G[es[i].x][es[i].y].cost)
            {
                G[es[i].x][es[i].y].cost = G[es[i].y][es[i].x].cost = cost;
            }
        }
        scanf("%d%d", &s, &t);
        fun(s);
        printf("%d %d\n", d[t].dis, d[t].cost);
    }
    return 0;
}