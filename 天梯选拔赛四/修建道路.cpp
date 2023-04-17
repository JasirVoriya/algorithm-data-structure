#include <bits/stdc++.h>
using namespace std;
class UnionSet
{
public:
    const static int maxn = 120;
    int root[maxn];
    UnionSet(int n)
    {
        for (int i = 0; i < maxn; i++)
            root[i] = i;
    }
    int GetRoot(int x)
    {
        while (x != root[x])
            x = root[x] = root[root[x]];
    }
    bool IsSame(int a, int b)
    {
        return GetRoot(a) == GetRoot(b);
    }
    void Union(int a, int b)
    {
        root[GetRoot(b)] = GetRoot(a);
    }
};
struct Edge
{
    int x = 0, y = 0, e = 0;
};
bool cmp(Edge &a, Edge &b)
{
    return a.e < b.e;
}
Edge es[10000 + 5];
int main(void)
{
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            es[cnt].x = i;
            es[cnt].y = j;
            cin >> es[cnt].e;
            cnt++;
        }
    }
    sort(es, es + cnt, cmp);
    for(int i=0;i<cnt;i++)
    {

    }
    return 0;
}