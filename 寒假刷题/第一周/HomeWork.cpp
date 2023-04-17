#include <bits/stdc++.h>
using namespace std;
struct node
{
    double t = 0, v = 0;
    bool operator<(const node &a) const
    {
        if (this->t == 0)
            return true;
        if (a.t == 0)
            return false;
        return this->v / this->t > a.v / a.t;
    }
};
int main(void)
{
    double m, n;
    while ((cin >> m >> n) && !(m == 0 && n == 0))
    {
        set<node> a;
        node x;
        for (int i = 0; i < m; i++)
        {
            cin >> x.t >> x.v;
            a.insert(x);
        }
        auto it = a.begin();
        double ans = 0;
        while (n > 0 && it != a.end())
        {
            ans += it->v;
            n -= it->t;
            it++;
        }
        if (n < 0)
        {
            it--;
            ans += n * (it->v / it->t);
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}