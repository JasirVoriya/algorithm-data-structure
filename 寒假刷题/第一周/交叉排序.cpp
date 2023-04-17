#include <bits/stdc++.h>
using namespace std;
bool cmp1(int a, int b)
{
    return a < b;
}
bool cmp2(int a, int b)
{
    return a > b;
}
int main(void)
{
    array<int, 11000> a;
    int n, l1, r1, l2, r2;
    cin >> n >> l1 >> r1 >> l2 >> r2;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin() + l1 - 1, a.begin() + r1, cmp1);
    sort(a.begin() + l2 - 1, a.begin() + r2, cmp2);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}