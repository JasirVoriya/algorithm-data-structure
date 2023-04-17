#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e6 + 5;
typedef long long ll;
typedef unsigned long long ull;
int arr[MAX_N];
void init()
{
    for (int i = 1; i < MAX_N; i++) {
        arr[i] = arr[i - 1] + i * (i + 1);
    }
}
ull solove(ull n, ull m)
{
    if(n==0)n++;
    if(m==0)m++;
    return arr[m] - arr[n-1];
}
int main(void)
{
    init();
    int t;
    cin >> t;
    while (t--) {
        ull n, m;
        cin >> n >> m;
        cout << solove(n, m) << endl;
    }

    return 0;
}