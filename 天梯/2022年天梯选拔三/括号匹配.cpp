#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2;
const int INF = 0x3f3f3f3f;
typedef long long ll;
bool check(char l, char r)
{
    return l == '[' && r == ']' || l == '(' && r == ')' || l == '{' && r == '}';
}
bool solove(string& str)
{
    stack<char> left;
    for (char ch : str) {
        if (ch == '{' || ch == '[' || ch == '(')
            left.push(ch);
        else {
            if (ch == '}' || ch == ']' || ch == ')') {
                if (left.size() == 0 || check(left.top(), ch)==false)
                    return false;
                left.pop();
            }
        }
    }
    return left.size() == 0;
}
int main(void)
{
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        if (solove(str))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}