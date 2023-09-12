#include <bits/stdc++.h>
using namespace std;
long long Pow(long long x, long long n)
{
    long long base = x;
    long long ans = 1;
    while (n)
    {
        if (n & 1)
            ans *= base;
        n >>= 1;
        base *= x;
    }
    return ans;
}
int main(void)
{
    long long n;
    while (cin >> n)
    {
        long long cnt = 0;
        long long i = 2;
        while (i * i < n)
        {
            if (n % i == 0)
                cnt++;
            i++;
        }
        if (i * i == n)
            cout << pow(n, cnt) * i << endl;
        else
            cout << pow(n, cnt) << endl;
    }
    return 0;
}