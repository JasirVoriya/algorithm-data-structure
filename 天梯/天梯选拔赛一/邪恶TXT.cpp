#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    string a = "104", b = "TXT", c = "neredeeixiuzihs";
    for (int i = 0, j = c.size() - 1; i < j; i++, j--)
        swap(c[i], c[j]);
    cout << a + b + c;
}