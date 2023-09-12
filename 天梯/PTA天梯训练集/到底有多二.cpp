#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    string num;
    cin >> num;
    double base = 1;
    double l = num.size(), cnt = count(num.begin(), num.end(), '2');
    if (num[0] == '-') {
        base += 0.5;
        l--;
    }
    if ((num[num.size() - 1] - '0') % 2 == 0) {
        base *= 2;
    }
    printf("%.2lf%%", base * (cnt / l) * 100);
    return 0;
}