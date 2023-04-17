#include <bits/stdc++.h>
using namespace std;
const int maxe = 100100, maxv = 1100;
const int INF = unsigned(-1) >> 1;
int m, s, n;
struct edge
{
    int x, y;
};
edge es[maxe]; //边
struct Graph
{
    int dis;
};
Graph G[maxv][maxv]; //邻接矩阵
struct dist
{
    int dis;
};
dist d[maxv]; //最短路径
void fun(int s)
{
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
    while (scanf("%d%d%d", &m, &s, &n) != EOF)
    {
        int dis;
        for (int i = 1; i < maxv; i++) //初始化邻接矩阵
            for (int j = 1; j < maxv; j++)
                G[i][j].dis = INF;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &es[i].x, &es[i].y, &dis);

            if (dis < G[es[i].x][es[i].y].dis) //构建邻接矩阵
                G[es[i].x][es[i].y].dis = G[es[i].y][es[i].x].dis = dis;
        }
        for (int i = 0; i < maxv; i++) //初始化最短距离
            d[i].dis = INF;
        int city[maxv];
        for (int i = 0, x; i < s; i++) //草儿的邻居
        {
            scanf("%d", &x);
            d[x].dis = 0;
        }
        for (int i = 0; i < n; i++) //草儿喜欢的城市
            scanf("%d", city + i);
        int ans = INF;
        fun(0);
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, d[city[i]].dis);
        }
        printf("%d\n", ans);
    }
    return 0;
}