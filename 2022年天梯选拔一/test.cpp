#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 1100;
int prime[maxn];
bool vis[maxn];
int cnt = 0;
void euler(int n)
{

    memset(prime, 0, sizeof prime);
    memset(vis, false, sizeof vis);
    for (int i = 2; i <= n; i++) {
        if (vis[i] == false)
            prime[cnt++] = i;
        for (int j = 0; j < cnt && i * prime[j] <= n; j++) {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}
bool fun(int n)
{
    int len = 0;
    char a[100];
    while (n) {
        a[len++] = n % 10 + '0';
        n /= 10;
    }
    for (int i = 0; i < len / 2; i++) {
        if (a[i] != a[len - i - 1])
            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    euler(1e6 + 1);
    // int t;
    // cin>>t;
    // while(t--) {
    // 	int n;
    // 	cin >> n;
    ofstream cout("test1.out");
    for (int n = 0; n <= 65539; n++) {
        for (int i = 0; i < cnt; i++) {
            if (prime[i] > n && fun(prime[i]) == true) {
                cout << n << ":" << prime[i] << endl;
                break;
            }
        }
    }

    return 0;
}
