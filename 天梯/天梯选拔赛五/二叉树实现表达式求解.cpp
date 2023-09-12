#include <bits/stdc++.h>
using namespace std;
string ex;
double fun()
{
    stack<char> optr;
    stack<double> opnd;
    char temp[5] = {0};
    int j = 0;
    double x;
    for (int i = 0; i < ex.size(); i++)
    {
        switch (ex[i])
        {
        case '(':
            j = 0;
            while (ex[++i] != ')')
                temp[j++] = ex[i];
            temp[0] -= '0', temp[2] -= '0';
            switch (temp[1])
            {
            case '+':
                opnd.push(temp[0] + temp[2]);
                break;
            case '-':
                opnd.push(temp[0] - temp[2]);
                break;
            case '*':
                opnd.push(temp[0] * temp[2]);
                break;
            case '/':
                if (temp[2] == 0)
                {
                    cout << "divide 0 error!";
                    exit(0);
                }
                opnd.push(1.0 * temp[0] / temp[2]);
                break;
            }
            break;
        case '+':
            optr.push(ex[i]);
            break;
        case '-':
            optr.push(ex[i]);
            break;
        case '*':
            x = opnd.top(); //数据出栈
            opnd.pop();
            i++;
            opnd.push(x * (ex[i] - '0'));
            break;
        case '/':
            x = opnd.top(); //数据出栈
            opnd.pop();
            i++;
            if (ex[i] - '0' == 0)
            {
                cout << "divide 0 error!";
                exit(0);
            }
            opnd.push(x / (ex[i] - '0'));
            break;
        default:
            opnd.push(ex[i] - '0');
            break;
        }
    }
    stack<char> ptr;
    while (optr.size())
    {
        ptr.push(optr.top());
        optr.pop();
    }
    stack<double> pnd;
    while (opnd.size())
    {
        pnd.push(opnd.top());
        opnd.pop();
    }
    double ans = pnd.top();
    pnd.pop();
    while (ptr.size())
    {
        char sign = ptr.top();
        ptr.pop();
        switch (sign)
        {
        case '-':
            ans -= pnd.top();
            pnd.pop();
            break;
        case '+':
            ans += pnd.top();
            pnd.pop();
            break;
        default:
            break;
        }
    }
    return ans;
}
int main(void)
{
    cin >> ex;
    printf("%lg", fun());
    return 0;
}