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
int main(void)
{
    int n, m, q;
    cin >> n >> m >> q;
    UnionFind u(n);
    int x, y;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        u.unionSet(x, y);
    }
    for (int i = 0; i < q; i++)
    {
        cin >> x >> y;
        if (u.isSame(x, y))
            cout << "In the same gang." << endl;
        else
            cout << "In different gangs." << endl;
    }
    cout << u.getCount() << endl;
    return 0;
}