#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string str;
    while (cin >> str)
    {
        bool flag = true;
        stack<char> s;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(')
                s.push(str[i]);
            else if (str[i] == ')')
            {
                if (s.size()==0)
                {
                    flag = false;
                    break;
                }
                else
                    s.pop();
            }
        }
        if (flag == false)
        {
            cout << "NO" << endl;
            continue;
        }
        if (s.size() == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}