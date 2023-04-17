#include <bits/stdc++.h>
const int maxn = 12;
int root[maxn];   //节点之间的附属关系
int height[maxn]; //节点树的高度
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
int main(void)
{
    int t;
    char str[1100];
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        init();
        int a, b;
        while (n--)
        {
            scanf("%s", str);
            int len = strlen(str);
            a = str[0] - '0';
            if (root[a] == -1)
                root[a] = a;
            for (int i = 1; i < len; i++)
            {
                b = str[i] - '0';
                if (root[b] == -1)
                    root[b] = b;
                unionset(a, b);
            }
        }
        int count[10] = {0}, ans = 0;
        for (int i = 0; i < 10; i++)//计算有几个根节点
        {
            if (root[i] != -1)
                count[getroot(i)] = 1;
        }
        for (int i = 0; i < 10; i++)//求根节点的个数
            ans += count[i];
        printf("%d\n", ans);
    }
    return 0;
}