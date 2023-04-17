#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
P vec[100010];
int main(void)
{
    //freopen("input.txt","r",stdin);
    int n, m, x;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        set<int> rabbit;
        for (int i = 0; i < n; i++) //输入兔子的HP
        {
            scanf("%d", &x);
            rabbit.insert(x);
        }
        for (int i = 0; i < m; i++) //输入弓箭的伤害
        {
            scanf("%d", &x);
            vec[i].second = x;
        }
        for (int i = 0; i < m; i++) //输入弓箭的价值
        {
            scanf("%d", &x);
            vec[i].first = x;
        }
        sort(vec, vec + m);
        long long ans = 0;
        for (int i = 0; i < m && rabbit.size(); i++)
        {
            set<int>::iterator killed = rabbit.lower_bound(vec[i].second);
            if (killed == rabbit.begin() && *killed > vec[i].second) //伤害不够,杀不了
                continue;
            if (killed == rabbit.end() || *killed > vec[i].second) //伤害能够杀兔子
                killed--;                                          //定位到当前箭能杀死的兔子
            //cout <<"killed:"<< *killed << " value: " << arrow.first << " second: " << arrow.second << endl;
            rabbit.erase(killed); //将被杀死的兔子移除
            ans += vec[i].first;  //累加箭的价值
        }
        if (rabbit.size())
            cout << "No" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}