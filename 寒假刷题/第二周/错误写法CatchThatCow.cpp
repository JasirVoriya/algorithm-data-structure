#include <bits/stdc++.h>
using namespace std;
int n, k;
int min(int a, int b)
{
    return a < b ? a : b;
}
int solove(int i)
{
    if (i < 0)
        return 100000;
    if (i == k)
        return 0;
    if (i < k)
    {
        int a = solove(2 * i) + 1, b = solove(i + 1) + 1, c = solove(i - 1) + 1;
        return min(min(a, b), c);
    }
    return solove(i - 1) + 1;
}
int main(void)
{
    while (cin >> n >> k)
        cout << solove(n) << endl;
    return 0;
}