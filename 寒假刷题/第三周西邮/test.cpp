#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int main(void)
{
    //freopen("input.txt","r",stdin);
    int n, m, x;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        vector<P> vec;
        set<int> rabbit;
        for (int i = 0; i < n; i++) //输入兔子的HP
        {
            scanf("%d", &x);
            rabbit.insert(x);
        }
        for (int i = 0; i < m; i++) //输入弓箭的伤害
        {
            scanf("%d", &x);
            vec.push_back(P(0, x));
        }
        for (int i = 0; i < m; i++) //输入弓箭的价值
        {
            scanf("%d", &x);
            vec[i].first = x;
        }
        sort(vec.begin(), vec.end());
        long long ans = 0;
        while (rabbit.size() && vec.size())
        {
            set<int>::iterator killed = rabbit.lower_bound(vec.begin()->second);
            P arrow = *vec.begin();
            vec.erase(vec.begin());
            if (killed == rabbit.begin() && *killed > arrow.second) //伤害不够,杀不了
                continue;
            if (killed == rabbit.end() || *killed > arrow.second) //伤害能够杀兔子
                killed--;                                         //定位到当前箭能杀死的兔子
            //cout <<"killed:"<< *killed << " value: " << arrow.first << " second: " << arrow.second << endl;
            rabbit.erase(killed); //将被杀死的兔子移除
            ans += arrow.first;  //累加箭的价值
        }
        if (rabbit.size())
            cout << "No" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}