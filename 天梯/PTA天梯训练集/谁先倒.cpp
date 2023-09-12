#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int A, B;
    cin >> A >> B;
    int x = A, y = B;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (A == -1 || B == -1)
            continue;
        if (a + c == b && a + c == d)
            continue;
        if (a + c == b)
            A--;
        else if (a + c == d)
            B--;
    }
    if (A == -1)
        cout << "A\n"
             << y - B;
    else
        cout << "B\n"
             << x - A;
    return 0;
}