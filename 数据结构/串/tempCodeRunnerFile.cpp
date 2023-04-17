#include <bits/stdc++.h>
using namespace std;
int m, n, sum, ans;
int parent[20000];
struct node {
    int u;
    int v;
    int w;
} edge[20000];
bool cmp(node a, node b)
{
    return a.w < b.w;
}
int finds(int o)
{
    if (o == parent[o])
        return o;
    else {
        parent[o] = finds(parent[o]);
        return parent[o];
    }
}
int main()
{
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; i++)
        parent[i] = i;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
    }
    sort(edge + 1, edge + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        int xx = finds(edge[i].u);
        int yy = finds(edge[i].v);
        if (xx == yy)
            continue;
        parent[xx] = yy;
        ans++;
        sum += edge[i].w;
        if (ans == m - 1) {
            printf("%d", sum);
            return 0;
        }
    }
    printf("-1");
    return 0;
}