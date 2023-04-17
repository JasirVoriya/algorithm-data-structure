#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, index = 0, max = 1, a, b;
        int num[100]={0};
        cin >> n;
        cin >> a;
        num[index]++;
        while (--n)
        {

            cin >> b;
            if (b != a)
            {
                a = b;
                index++;
            }
            num[index]++;
        }
        max = num[0];
        for (int i = 1; i < index; i++)
            if (num[index] > max)
                max = num[index];
        cout << max << endl;
    }
}