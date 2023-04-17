#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define INF ((unsigned(-1)) >> 1)
const int maxn = 100100;
struct cows
{
    ll w, s;
};
cows Cows[maxn];
bool cmp(cows &a, cows &b)
{
    return a.w + a.s > b.w + b.s;
    //交换后的压力如果大于交换前的压力
}
int main(void)
{
    int n;
    cin >> n;
    cows temp;
    for (int i = 0; i < n; i++)
        cin >> Cows[i].w >> Cows[i].s;
    sort(Cows, Cows + n, cmp);
    ll w = 0, ans = w - Cows[n - 1].s;
    for (int i = n - 2; i >= 0; i--)
    {
        //cout << "data: " << (it - 1)->w << " " << (it - 1)->s;
        w += Cows[i + 1].w;
        //cout << " w: " << w << " it->s: " << it->s << " ans: " << ans << endl;
        if (ans < w - Cows[i].s)
            ans = w - Cows[i].s;
    }
    cout << ans;
}