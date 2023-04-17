#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    stack<int> s1;
    stack<char> s2;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s1.push(x);
    }
    char ch;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> ch;
        s2.push(ch);
    }
    int ans;
    while (true)
    {
        int x = s1.top();
        s1.pop();
        int y = s1.top();
        s1.pop();
        char ch = s2.top();
        s2.pop();
        switch (ch)
        {
        case '+':
            ans = y + x;
            break;
        case '-':
            ans = y - x;
            break;
        case '*':
            ans = y * x;
            break;
        case '/':
            if (x == 0)
            {
                printf("ERROR: %d/0\n", y);
                return 0;
            }
            ans = y / x;
            break;
        }
        if (s1.empty() && s2.empty())
        {
            cout << ans << endl;
            return 0;
        }
        s1.push(ans);
    }
}