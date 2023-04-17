#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
bool isright(int ch)
{
    return ch == ']' || ch == '}' || ch == ')';
}
bool isleft(int ch)
{
    return ch == '[' || ch == '{' || ch == '(';
}
bool ispair(int ch1, int ch2)
{
    return ch1 == '[' && ch2 == ']' || ch2 == '[' && ch1 == ']' ||
           ch1 == '{' && ch2 == '}' || ch2 == '{' && ch1 == '}' ||
           ch1 == '(' && ch2 == ')' || ch2 == '(' && ch1 == ')';
}
int main(void)
{
    char str[200];
    while (gets(str))
    {
        stack<int> s;
        int size = strlen(str);
        for (int i = 0; i < size; i++)
        {
            if (isright(str[i]))
            {
                if (s.size() == 0)
                {
                    cout << "no" << endl;
                    goto end;
                }
                else if (ispair(s.top(), str[i]))
                {
                    s.pop();
                }
                else
                {
                    cout << "no" << endl;
                    goto end;
                }
            }
            else if (isleft(str[i]))
            {
                s.push(str[i]);
            }
        }
        if (s.size() == 0)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    end:;
    }
}