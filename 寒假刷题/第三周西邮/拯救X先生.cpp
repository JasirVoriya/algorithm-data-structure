#include <bits/stdc++.h>
using namespace std;
struct obj
{
    int p, m;
} objs[110];
bool cmp(obj &a, obj &b)
{
    return a.p > b.p;
}
int main(void)
{
    int v, n;
    while (1)
    {
        scanf("%d", &v);
        if (v == 0)
            break;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &objs[i].p, &objs[i].m);
        sort(objs, objs + n, cmp);
        int ans, i;
        for (ans = i = 0; i < n && v >= 0; i++)
        {
            ans += objs[i].m * objs[i].p;
            v -= objs[i].m;
        }
        if (v < 0)
        {
            i--;
            ans += objs[i].p * v;
        }
        printf("%d\n", ans);
    }
    return 0;
}