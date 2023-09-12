#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
private:
    static const int maxn = 1e5;
    int root[maxn];
    int size;
    int count;

public:
    UnionFind(int n)
    {
        size = count = n;
        for (int i = 1; i <= n; i++)
            root[i] = i;
    }
    int getRoot(int x)
    {
        while (x != root[x])
        {
            x = root[x] = root[root[x]];
        }
        return x;
    }
    bool isSame(int a, int b)
    {
        return getRoot(a) == getRoot(b);
    }
    int getCount()
    {
        return count;
    }
    void unionSet(int a, int b)
    {
        a = getRoot(a), b = getRoot(b);
        if (!isSame(a, b))
        {
            root[a] = root[b];
            count--;
        }
    }
};
class Edge
{
public:
    int x, y, cost;
    friend bool operator<(const Edge &a, const Edge &b)
    {
        return a.cost > b.cost;
    }
};
priority_queue<Edge> es;
int solove(int m)
{
    UnionFind u(m);
    int res = 0;
    while (es.size())
    {
        Edge e = es.top();
        es.pop();
        if (!u.isSame(e.x, e.y))
        {
            u.unionSet(e.x, e.y);
            res += e.cost;
        }
    }
    if (u.getCount() == 1)
        return res;
    return -1;
}
int main(void)
{
    int m, n;
    cin >> m >> n;
    Edge e;
    for (int i = 1; i <= n; i++)
    {
        cin >> e.x >> e.y >> e.cost;
        es.push(e);
    }
    cout << solove(m);
    return 0;
}