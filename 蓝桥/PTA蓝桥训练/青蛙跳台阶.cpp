#include <bits/stdc++.h>
using namespace std;
const int maxn = 70;
typedef long long ll;
ll a[maxn] = {1, 1, 2, 3};
int main(void)
{
    for (int i = 4; i < maxn; i++)
        a[i] = a[i - 1] + a[i - 2];
    int n;
    cin >> n;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        cout << a[x] << endl;
    }
}