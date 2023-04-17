#include<iostream>
using namespace std;
const int maxn = 30100;
int relative[maxn]; //节点之间的附属关系
int height[maxn];   //节点树的高度
int n, m;
void init()
{
    for (int i = 0; i < n; i++)
        height[i] = 1, relative[i] = i;
}
int getroot(int x)
{
    while (x != relative[x])
        x = relative[x] = relative[relative[x]];
    return x;
}
void unionset(int a, int b)
{
    int roota = getroot(a), rootb = getroot(b);
    if (roota == rootb)
        return;
    if (height[roota] < height[rootb]) //把低的树连接到高的树上，能够降低合并后的高度，提高查找速度
        relative[roota] = rootb;
    else
    {
        if (height[rootb] == height[roota]) //如果b树和a树高度相等，那么b树连接到a树的时候，a树的高度要+1
            height[roota]++;
        relative[rootb] = roota; //把b树连接到a树上面
    }
}
int main(void)
{
    while ((cin >> n >> m))
    {
        if (n == 0 && m == 0)
            break;
        init();
        int t, a, b;
        int ans = 1;
        while (m--)
        {
            cin >> t;
            cin >> a;
            for (int i = 2; i <= t; i++)
                cin >> b, unionset(a, b);//合并a树和b树
        }
        int root = getroot(0);
        for (int i = 1; i < n; i++)
        {
            //cout << i << " : " << getroot(i) << endl;
            ans += getroot(i) == root;
        }
        cout << ans << endl;
    }
    return 0;
}