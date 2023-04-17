// 分糖果
// 描述
// DpprZ有n(1≤n≤2e5)颗糖果，每颗糖果的重量为a[i](0≤ai≤1e9)，现在他为了展示他的大度想分出一部分糖果给其他人，但是他又不想分出去太多，想让自己能剩下的糖果总重量只比之前少1。他需要你来帮助他求出有多少种符合他要求的分糖果方案，结果对1000000007取模

// 格式
// 输入格式
// 输入t组，每组输入两行，每组第一行输入一个数n(1≤n≤2e5)糖果的数量，第二行输入n个数a[i](0≤ai≤1e9)每颗糖果的重量,t组n的和不超过2e5

// 输出格式
// 输出一个数，有多少种分糖果的方案满足题目要求

// 样例
// 样例输入 Copy
// 5
// 5
// 1 2 3 4 5
// 2
// 1000 1000
// 2
// 1 0
// 5
// 3 0 2 1 1
// 5
// 2 1 0 3 0
// 样例输出 Copy
// 1
// 0
// 2
// 4
// 4
// 提示
// 2e5代表200000,ACM中(x)e(y)通常代表x乘10的y次方

// 信息
// ID		问题 C
// 提交		2
// 解决		1
// 时间限制		1 Sec
// 内存限制		128 MB
// 命题人		2019401359
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
int main(void)
{
    // ifstream cin;
    // ofstream cout;
    // cin.open("test1.in");
    // cout.open("test1.out");
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> vec;
        for (ll i = 0, x = 0; i < n; i++) {
            cin >> x;
            vec.push_back(x);
        }
        ll cnt0 = count(vec.begin(), vec.end(), 0);
        ll cnt1 = count(vec.begin(), vec.end(), 1);
        ll x = 1;
        for (int i = 0; i < cnt0; i++)
            x = (x << 1) % mod;
        cout << x * cnt1 % mod << endl;
    }
    return 0;
}