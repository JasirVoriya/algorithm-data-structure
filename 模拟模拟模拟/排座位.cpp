#include <bits/stdc++.h>
using namespace std;
bool solove(string &str)
{
    if (str.size() == 1)
        return str == "1";
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '0')
        {
            if (i == 0 && str[i + 1] == '0' || i == str.size() - 1 && str[i - 1] == '0')
                return false;
            if (str[i - 1] == '0' && str[i + 1] == '0')
                return false;
        }
        else if (str[i] == '1')
        {
            if (i - 1 >= 0 && str[i - 1] == '1')
                return false;
            if (i + 1 < str.size() && str[i + 1] == '1')
                return false;
        }
    }
    return true;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string str;
        cin >> n >> str;
        // cout<<str;
        if (solove(str))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}