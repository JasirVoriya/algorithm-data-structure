#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        ull n, k;
        cin >> n >> k;
        ull a = n / k + ((n % k) > 0);//找出系数
        k *= a;
        cout << (k / n + ((k % n) > 0)) << endl;
    }
}