#include <bits/stdc++.h>
using namespace std;
class UnionFind
{
private:
    static const int maxn = 1e4 + 10;
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
    int getCount()
    {
        return count;
    }
    int getRoot(int a)
    {
        while (a != root[a])
            a = root[a] = root[root[a]];
        return a;
    }
    bool isSame(int a, int b)
    {
        return getRoot(a) == getRoot(b);
    }
    void unionSet(int a, int b)
    {
        if (isSame(a, b))
            return;
        root[getRoot(a)] = root[getRoot(b)];
        count--;
    }
};
int main(void)
{
    int n;
    cin >> n;
    UnionFind u(n);
    char sign;
    while (cin >> sign)
    {
        if (sign == 'S')
            break;
        int c1, c2;
        cin >> c1 >> c2;
        if (sign == 'I')
            u.unionSet(c1, c2);
        else if (sign == 'C')
        {
            if (u.isSame(c1, c2))
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
    }
    if (u.getCount() == 1)
        cout << "The network is connected." << endl;
    else
        cout << "There are " << u.getCount() << " components." << endl;
    return 0;
}