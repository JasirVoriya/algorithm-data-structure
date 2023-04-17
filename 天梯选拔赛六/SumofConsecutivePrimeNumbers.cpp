#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int prime[maxn], ans[maxn];
int cnt = 0;
void init()
{
    for (int i = 2; i < maxn; i++)
    {
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
                goto end;
        }
        prime[cnt++] = i;
    end:;
    }
}
void solove()
{
    init();
    for (int i = 2; i < maxn; i++)
    {
        for (int x = 0; prime[x] <= i && x < cnt; x++) //x是起点
        {
            for (int k = x, sum = 0; k < cnt; k++)
            {
                sum += prime[k];
                if (sum == i)
                    ans[i]++;
                else if (sum > i)
                    break;
            }
        }
    }
}
int main(void)
{
    solove();
    int n;
    while (cin >> n)
    {
        if(n==0)return 0;
        cout << ans[n] << endl;
    }
    return 0;
}