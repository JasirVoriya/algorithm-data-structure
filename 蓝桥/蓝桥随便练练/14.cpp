#include <bits/stdc++.h>
using namespace std;
int fun(int n)
{
    if (n <= 0)
        return 1;
    return n * fun(n - 1);
}
int comb(int n, int m)
{
    return fun(n) / (fun(n - m) * fun(m));
}
bool check(int A, int B, double P)
{
    int sum = A * 5, m = 0;
    while (sum < B)
        sum += A, m++;
    double ans = 0;
    for (int i = m; i <= 5; i++)
        ans += comb(5, i) * pow(P, i) * pow(1 - P, 5 - i);
    if (ans >= 0.9)
        return true;
    return false;
}
int main(void)
{
    int n;
    cin >> n;
    while (n--)
    {
        int A, B;
        cin >> A >> B;
        if (A * 10 < B)
        {
            cout << "HZWZ" << endl;
            continue;
        }
        double l = 0, r = 1, mid = (l + r) / 2;
        for (int i = 0; i < 100; i++)
        {
            if (check(A, B, mid))
                r = mid;
            else
                l = mid;
            mid = (l + r) / 2;
        }
        printf("%.2f\n", mid * 100);
    }
    return 0;
}