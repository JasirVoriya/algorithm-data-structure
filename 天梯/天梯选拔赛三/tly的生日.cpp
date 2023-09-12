#include <bits/stdc++.h>
using namespace std;
int fun(int n)
{
    n++;
    while (!(n % 400 == 0 || n % 4 == 0 && n % 100 != 0))
        n++;
    return n;
}
int main(void)
{
    int n;
    cin >> n;
    cout << fun(n);
    return 0;
}