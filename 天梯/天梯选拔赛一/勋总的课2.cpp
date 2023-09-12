#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    char signs[6] = "+-*/=";
    map<char, long long> m = {
        {'0', 0},
        {'1', 1},
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'9', 9},
        {'A', 10},
        {'B', 11},
        {'C', 12},
        {'E', 13},
        {'D', 14},
        {'F', 15}};
    string str;
    while (cin >> str)
    {
        char a[100] = {0}, b[100] = {0}, c[100] = {0};
        long long x, y;
        for (long long i = 0; i < 5; i++)
        {
            long long index = str.find(signs[i]);
            if (index != str.npos)
            {
                if (str[index] == '=')
                    y = index;
                else
                    x = index;
            }
        }
        char sign = str[x];
        long long maxn = 1;
        for (long long i = 0; i < x; i++)
        {
            maxn = max(maxn, m[str[i]]);
            a[i] = str[i];
        }
        for (long long i = x + 1, j = 0; i < y; i++, j++)
        {
            maxn = max(maxn, m[str[i]]);
            b[j] = str[i];
        }
        for (long long i = y + 1, j = 0; i < str.size(); i++, j++)
        {
            maxn = max(maxn, m[str[i]]);
            c[j] = str[i];
        }
        // cout << maxn;
        // cout << sign << endl;
        // cout << a << endl;
        // cout << b << endl;
        // cout << c << endl;
        for (long long i = maxn + 1; i <= 16; i++)
        {
            long long na = stoll(a, 0, i), nb = stoll(b, 0, i), nc = stoll(c, 0, i);
            switch (sign)
            {
            case '+':
                if (na + nb == nc)
                {
                    cout << i << endl;
                    goto end;
                }
                break;
            case '-':
                if (na - nb == nc)
                {
                    cout << i << endl;
                    goto end;
                }
                break;
            case '*':
                if (na * nb == nc)
                {
                    cout << i << endl;
                    goto end;
                }
                break;
            case '/':
                if (na % nb == 0 && na / nb == nc)
                {
                    cout << i << endl;
                    goto end;
                }
                break;
            }
        }
        cout << -1 << endl;
    end:;
    }

    // cout << it;
    return 0;
}