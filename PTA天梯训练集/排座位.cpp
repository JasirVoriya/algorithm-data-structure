#include <bits/stdc++.h>
using namespace std;
static const int maxn = 1e2 + 5;
class UnionFind
{
private:
    int root[maxn];
    int count;
    int size;

public:
    UnionFind(int n)
    {
        size = count = n;
        for (int i = 0; i <= n; i++)
            root[i] = i;
    }
    int getRoot(int x)
    {
        while (x != root[x])
            x = root[x] = root[root[x]];
        return x;
    }
    bool same(int a, int b)
    {
        return getRoot(a) == getRoot(b);
    }
    bool unionSet(int a, int b)
    {
        if (getRoot(a) == getRoot(b))
            return false;
        root[getRoot(a)] = root[getRoot(b)];
        count--;
        return true;
    }
};
int book[maxn][maxn];
int main(void)
{
    int n, m, k;
    cin >> n >> m >> k;
    UnionFind friends(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == -1)
            book[a][b] = book[b][a] = -1;
        else
            friends.unionSet(a, b);
    }
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        if (book[a][b] == -1) //是敌人
        {
            if (friends.same(a, b)) //有共同的是朋友
                cout << "OK but..." << endl;
            else
                cout << "No way" << endl; //没有共同的朋友
        }
        else if (friends.same(a, b))//是朋友
            cout << "No problem" << endl;
        else
            cout << "OK" << endl;//不是朋友
    }
    return 0;
}