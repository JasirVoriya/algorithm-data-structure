#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int main(void)
{
    string str;
    cin >> str;
    int num = 0, sum = 0;
    for (char ch : str) {
        if ((ch >= '0' && ch <= '9') == false) {
            sum += num;
            num = 0;
        } else
            num = num * 10 + ch - '0';
    }
    cout << sum << endl;
    return 0;
}