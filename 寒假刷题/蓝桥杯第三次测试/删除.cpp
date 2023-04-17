#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    string str1, str2;
    cin >> str1 >> str2;
    int x = 0;
    while (true)
    {
        int d1 = str1.size() - 1 - x, d2 = str2.size() - 1 - x;
        // cout << d1 << ' ' << d2 << endl;
        if (d1 < 0 || d2 < 0)
                    break;
        if (str1[d1] == str2[d2])
            x++;
        else
            break;
    }
    cout << str1.size() + str2.size() - 2 * x;
    return 0;
}