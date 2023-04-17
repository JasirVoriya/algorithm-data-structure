#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
pair<int, int> pro[maxn];
int main(void)
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            cin >> pro[i].second; //输入开始时间
            cin >> pro[i].first;  //输入结束时间
        }
        sort(pro, pro + n); //sort对于pair的排序，默认按照first排升序
        int ans = 0, end = 0;
        for (int i = 0; i < n; i++)
        {
            if (pro[i].second >= end) //开始时间大于结束时间
            {
                ans++;
                end = pro[i].first;
            }
        }
        cout << ans << endl;
    }
    return 0;
}