#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    string email;
    cin >> email;
    bool flag = false;
    bool True = false;
    for (int i = 0; i < email.size(); i++)
    {
        if (email[i] == '.')
        {
            if (flag && (i + 4 == email.size()) && email[i - 1] != '@' && email[i + 1] == 'c' && email[i + 2] == 'o' && email[i + 3] == 'm')
                True = true;
        }
        else if (email[i] == '@')
        {
            if (i != 0)
                flag = true;
        }
        else if (!(email[i] == '_' || email[i]>='0'&&email[i]<='9' || email[i]>='a'&&email[i]<='z'||email[i]>='A'&&email[i]<='Z'))
        {
            cout << "NO";
            return 0;
        }
    }
    if (True)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}