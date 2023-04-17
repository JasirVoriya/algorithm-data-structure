#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int main(void)
{
    stack<string> ops;
    stack<double> num;
    string op;
    while (cin >> op) {
        ops.push(op);
    }
    while (ops.size()) {
        op = ops.top();
        ops.pop();
        if (op == "+" || op == "-" || op == "*" || op == "/") {
            double x = num.top();
            num.pop();
            double y = num.top();
            num.pop();
            switch (op[0]) {
            case '+':
                num.push(x + y);
                break;
            case '-':
                num.push(x - y);
                break;
            case '*':
                num.push(x * y);
                break;
            case '/':
                num.push(x / y);
                break;
            }
        } else {
            num.push(stod(op));
        }
    }
    printf("%.6lf", num.top());
    return 0;
}