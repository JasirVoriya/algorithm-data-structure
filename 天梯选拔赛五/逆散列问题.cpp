#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
bool uesd[maxn], book[maxn];
int data[maxn];
int ans[maxn];
int cnt;
int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> data[i];
    sort(data, data + n);
    for (int i = 0; i < n; i++)
    {
        if (data[i] == -1)
            continue;
        int mod = data[i] % n;
        if (book[mod])
            continue;
        ans[cnt++] = data[i];
        book[mod] = true;
    }
    
    return 0;
}