#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int arr1[MAX_N], arr2[MAX_N];
bool cmp(int a, int b)
{
    return a > b;
}
int main(void)
{
    int n;
    while (cin >> n, n > 0) {
        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        for (int i = 0; i < n; i++)
            cin >> arr2[i];
        sort(arr1, arr1 + n, cmp);
        sort(arr2, arr2 + n);
        
    }

    return 0;
}