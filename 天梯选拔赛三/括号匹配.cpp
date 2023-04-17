#include <bits/stdc++.h>
using namespace std;
bool isLeft(char ch)
{
    return ch == '(' || ch == '{' || ch == '[';
}
bool isRight(char ch)
{
    return ch == ')' || ch == '}' || ch == ']';
}
bool isPair(char ch1, char ch2)
{
    return ch1 == '[' && ch2 == ']' ||
           ch1 == ']' && ch2 == '[' ||
           ch1 == '(' && ch2 == ')' ||
           ch1 == ')' && ch2 == '(' ||
           ch1 == '{' && ch2 == '}' ||
           ch1 == '}' && ch2 == '{';
}
int main(void)
{
    string str;
    cin >> str;
    stack<char> s;
    for (auto v : str)
    {
        if (isLeft(v))
        {
            s.push(v);
        }
        else if (isRight(v))
        {
            if (s.size() == 0 || !isPair(s.top(), v))
            {
                cout << "NO" << endl;
                return 0;
            }
            else
                s.pop();
        }
    }
    if (s.size()==0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}