#include <bits/stdc++.h>
using namespace std;
map<string, string> Pair = {
    {"]", "["},
    {")", "("},
    {"}", "{"},
    {"*/", "/*"},
    {"[", "]"},
    {"{", "}"},
    {"(", ")"},
    {"/*", "*/"}};
bool isPair(string a, string b)
{
    return Pair[a] == b || Pair[b] == a;
}
int main(void)
{
    stack<string> s;
    char str[200], ch;
    int size = 0;
    while ((ch = getchar()) != '.')
        str[size++] = ch;
    string t;
    for (int i = 0; i < size; i++)
    {
        if (str[i] == '/')
        {
            if (i + 1 < size && str[i + 1] == '*')
            {
                t = "/*";
                s.push(t);
                cout << "push: " << t << endl;
                i++;
            }
        }
        else if (str[i] == '{' || str[i] == '(' || str[i] == '[') //左括号
        {
            t = str[i];
            s.push(t);
            cout << "push: " << t << endl;
        }
        else if (str[i] == '*')
        {
            if (i + 1 < size && str[i + 1] == '/')
            {
                t = "*/";
                if (s.size() != 0 && isPair(s.top(), t))
                    s.pop();
                else
                {
                    cout << "NO" << endl;
                    cout << "?-" << t << endl;
                    goto end;
                }
                i++;
            }
        }
        else if (str[i] == '}' || str[i] == ')' || str[i] == ']') //右括号
        {
            t = str[i];
            if (s.size() != 0 && isPair(s.top(), t))
                s.pop();
            else
            {
                cout << "NO" << endl;
                cout << s.top() << "-?" << endl;
                goto end;
            }
        }
    }
    if (s.size()) //缺右括号
    {
        t = s.top();
        cout << "NO" << endl;
        cout << "?-" << Pair[t] << endl;
    }
    else
        cout << "YES" << endl;
end:;
    return 0;
}