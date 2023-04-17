#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    string str;
    cin >> str;
    unsigned long long int c = 0, sum = 0, ans = 0;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (str[i] == 'C')
            c++;
        if (str[i] == 'U')
            sum += c * (c - 1) / 2;
        if (str[i] == 'Z')
            ans += sum;
    }
    cout << ans << endl;
    return 0;
}