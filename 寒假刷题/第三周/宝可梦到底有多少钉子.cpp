#include <stdio.h>
const int maxn = 50100;
int relative[3 * maxn]; //节点之间的附属关系
int height[3 * maxn];   //节点树的高度
int n, m;
#define A(x) (x)
#define B(x) (x + n)
#define C(x) (x + 2 * n)
void init(int n)
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
    int n, k, ans = 0;
    scanf("%d%d", &n, &k);
    //cin >> n >> k;
    init(3 * n);
    int d, x, y;
    while (k--)
    {
        scanf("%d%d%d", &d, &x, &y);
        x--, y--;
        if ((!(x >= 0 && x < n)) || (!(y >= 0 && y < n)))
        {
            ans++;
            continue;
        }
        if (d == 1)
        {
            if (getroot(A(x)) != getroot(B(y)) && getroot(A(x)) != getroot(C(y)))
                //x不能吃y，y不能吃x
                unionset(A(x), A(y)), unionset(B(x), B(y)), unionset(C(x), C(y));
            else
                ans++;
        }
        else
        {
            if (x == y)
            {
                ans++;
                continue;
            }
            if (getroot(A(x)) != getroot(A(y)) && getroot(A(x)) != getroot(C(y)))
                //x和y不是同类，y不能吃x
                unionset(A(x), B(y)), unionset(B(x), C(y)), unionset(C(x), A(y));
            else
                ans++;
        }
    }
    printf("%d\n", ans);
    //cout << ans << endl;
    return 0;
}