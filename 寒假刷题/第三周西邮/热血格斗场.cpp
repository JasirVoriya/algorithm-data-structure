#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int main(void)
{
    set<P> s;
    P temp(1000000000, 1);
    s.insert(temp);
    int n;
    cin >> n;
    while (n--)
    {
        scanf("%lld%lld", &temp.second, &temp.first);
        auto right = s.lower_bound(temp);
        if (right == s.end()) //如果老会员的实力都没有新会员的高
            // cout << temp.second << ' ' << (--right)->second << endl;
            printf("%lld %lld\n",temp.second,(--right)->second);
        else
        {
            if (right == s.begin()) //如果第一个老会员的实力比新会员高
                // cout << temp.second << ' ' << right->second << endl;
                printf("%lld %lld\n",temp.second,right->second);
            else
            {
                auto left = right;
                left--;
                if (temp.first - left->first > right->first - temp.first) //判断新会员和老会员之间实力绝对值的大小
                    // cout << temp.second << ' ' << right->second << endl;
                    printf("%lld %lld\n",temp.second,right->second);
                else
                    // cout << temp.second << ' ' << left->second << endl;
                    printf("%lld %lld\n",temp.second,left->second);
            }
        }
        s.insert(temp);
    }
    return 0;
}