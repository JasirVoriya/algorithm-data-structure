#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
const int INF = (unsigned)(-1) >> 1;
class union_find //并查集
{
private:
    int root[maxn];   //节点之间的附属关系
    int height[maxn]; //节点树的高度
public:
    union_find()
    {
        init();
    }
    int getroot(int x)
    {
        while (x != root[x])
            x = root[x] = root[root[x]];
        return x;
    }
    void unionset(int a, int b)
    {
        int roota = getroot(a), rootb = getroot(b);
        if (roota == rootb)
            return;
        if (height[roota] < height[rootb]) //把低的树连接到高的树上，能够降低合并后的高度，提高查找速度
            root[roota] = rootb;
        else
        {
            if (height[rootb] == height[roota]) //如果b树和a树高度相等，那么b树连接到a树的时候，a树的高度要+1
                height[roota]++;
            root[rootb] = roota; //把b树连接到a树上面
        }
    }
    void init()
    {
        memset(root, -1, sizeof(root));
        for (int i = 0; i < maxn; i++)
            height[i] = 1;
    }
};
struct Pos
{
    int x, y, index;
};
class Edge //边
{
public:
    static const int times = 100;
    Pos a, b;
    double cost;
    double setup(Pos a, Pos b) //计算两个小岛之间搭桥的花费
    {
        double x = (a.x - b.x) * times, y = (a.y - b.y) * times;
        double dist = sqrt(x * x + y * y);
        if (dist >= 10 * times && dist <= 1000 * times)
            return dist;
        return INF;
    }
    Edge(Pos a, Pos b)
    {
        this->a = a, this->b = b;
        this->cost = setup(a, b);
    }
    friend bool operator<(const Edge &a, const Edge &b)
    {
        return a.cost > b.cost;
    }
};
Pos island[maxn]; //小岛的位置
double solove(priority_queue<Edge> es)
{
    union_find u;
    double res = 0;
    while (es.size())
    {
        Edge e = es.top();
        es.pop();
        if (e.cost == INF)
            return -1;
        if (u.getroot(e.a.index) != u.getroot(e.b.index))
        {
            u.unionset(e.a.index, e.b.index);
            res += e.cost;
        }
    }
    return res;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int c;
        cin >> c;
        for (int i = 0; i < c; i++)
        {
            cin >> island[i].x >> island[i].y;
            island[i].index = i;
        }
        for (int i = 0; i < c; i++)
        {
            cout << island[i].x << ' ' << island[i].y << ' ' << island[i].index << endl;
        }
        priority_queue<Edge> es;
        for (int i = 0; i < c - 1; i++)
            for (int j = i + 1; j < c; j++)
            {
                es.push(Edge(island[i], island[j]));
                cout << es.top().cost << endl;
            }
        double ans = solove(es);
        if (ans == -1)
            cout << "oh!" << endl;
        else
            printf("%.1lf\n", ans);
    }
    return 0;
}