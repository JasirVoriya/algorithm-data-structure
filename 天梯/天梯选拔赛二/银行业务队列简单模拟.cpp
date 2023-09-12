#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int A[1000 + 10], B[1000 + 10];
    int n, As = 0, Bs = 0;
    cin >> n;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        if (x % 2 == 1)
            A[As++] = x;
        else
            B[Bs++] = x;
    }
    int i = 0, j = 0;
    bool b = false;
    if (i < As)
    {
        cout << A[i++];
        b = true;
    }
    if (i < As)
        cout << " " << A[i++];
    if (j < Bs)
    {
        if (b == true)
            cout << " " << B[j++];
        else
            cout << B[j++];
    }
    while (i < As && j < Bs)
    {
        if (i < As)
            cout << " " << A[i++];
        if (i < As)
            cout << " " << A[i++];
        if (j < Bs)
            cout << " " << B[j++];
    }
    while (i < As)
        cout << " " << A[i++];
    while (j < Bs)
        cout << " " << B[j++];
    return 0;
}