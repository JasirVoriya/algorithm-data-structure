#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
bool IsPrime(int x)
{
    if (x <= 1)
        return false;
    for (int j = 2; j * j <= x; j++)
        if (x % j == 0)
            return false;
    return true;
}
int main(void)
{
    int n;
    cin >> n;
    if (n <= 2)
        cout << "3 5" << endl;
    else
    {
        n += n % 2 == 0 ? 1 : 2;
        while (!(IsPrime(n) && IsPrime(n + 2)))
            n += 2;
        cout << n << " " << n + 2 << endl;
    }
    return 0;
}