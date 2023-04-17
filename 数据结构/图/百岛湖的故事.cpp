#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int times = 100;
const int INF = (unsigned)(-1) >> 1;
int n;
struct Pos
{
    int x, y;
};
Pos island[maxn];          //小岛的位置
double cost[maxn][maxn];   //两个小岛之间的最短距离
double mincost[maxn];      //树外的点到树的最小距离，这个可以用堆来维护
bool uesd[maxn];           //小岛是否加入了树
double setup(Pos a, Pos b) //计算两个小岛之间搭桥的花费
{
    double x = a.x - b.x, y = a.y - b.y;
    double dist = sqrt(x * x + y * y);
    if (dist >= 10 * times && dist <= 1000 * times)
        return dist;
    return INF;
}
double solove()
{
    for (int i = 0; i < n; i++)
    {
        mincost[i] = INF;
        uesd[i] = false;
    }
    mincost[0] = 0;
    double res = 0;
    while (true)
    {
        int v = -1;
        for (int i = 0; i < n; i++)
        {
            if (!uesd[i] && (v == -1 || mincost[i] < mincost[v]))
                v = i;
        }
        if (mincost[v] == INF)
            return -1;
        if (v == -1)
            return res;
        uesd[v] = true;
        res += mincost[v];
        for (int i = 0; i < n; i++) //更新树外的点到树的最短距离
            mincost[i] = min(mincost[i], cost[v][i]);
    }
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> island[i].x >> island[i].y;
            island[i].x *= times, island[i].y *= times;
        }
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
            {
                cost[j][i] = cost[i][j] = setup(island[i], island[j]); //计算每两个小岛之间搭桥的花费
            }
        double ans = solove();
        if (ans == -1)
            cout << "oh!" << endl;
        else
            printf("%.1lf\n", ans);
    }
    return 0;
}