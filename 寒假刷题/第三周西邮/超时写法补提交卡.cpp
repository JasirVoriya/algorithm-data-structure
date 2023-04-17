#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
bool book[110];
int ans;
int cont(int n)//计算第1天到第i天最长连续签到的天数
{
    int sum[110], count = 0;
    sum[1] = !book[1];
    for (int i = 2; i <= n; i++)
    {
        sum[i] = !book[i];
        if (sum[i] != 0)
        {
            sum[i] += sum[i - 1];
            count = max(count, sum[i]);
        }
    }
    return count;
}
void fun(int n, int m, int i)
//n：从第i天到100天,未签到的天数
//m：剩余补登卡的数量
//i：当天是第i天
{
    if (m == 0)//如果补登卡用完了
    {
        ans = max(ans, cont(100));//计算连续天数最长的
        return;
    }
    if (n <= m)//如果未签到天数<=补登卡的数量
    {
        ans = max(max(ans, cont(i - 1)), 100 - i + 1);
        return;
    }
    while (i <= 100)
    {
        if (book[i] == true)//如果第i天没有签到
        {
            //第i-1天和第i+1天都签到过
            if ((i - 1 >= 1 && book[i - 1] == false || i + 1 <= 100 && book[i + 1] == false))
            {
                book[i] = false;//补上第i天
                fun(n - 1, m - 1, i + 1);
                book[i] = true;
            }
            else
                fun(n - 1, m, i + 1);//需不要补第i天，直接进入下一天
        }
        i++;
    }
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(book, 0, sizeof(book));
        int n, m;
        cin >> n >> m;
        for (int i = 1, x; i <= n; i++)
        {
            cin >> x;
            book[x] = true;
        }
        ans = 0;
        fun(n, m, 1);
        cout << ans << endl;
    }
    return 0;
}