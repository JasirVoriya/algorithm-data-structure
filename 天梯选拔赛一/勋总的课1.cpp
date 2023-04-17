#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    while (cin >> n)
    {
        char bit[33] = {"00000000000000000000000000000000"};
        unsigned int x = n;
        for (int i = 31; x; i--)
        {
            bit[i] += x % 2;
            x /= 2;
        }
        for (int i = 0; i < 32; i++)
        {
            cout << bit[i];
            if ((i + 1) % 8 == 0)
                cout << " ";
        }
        cout << "<->" << n << endl;
        
    }
    return 0;
}