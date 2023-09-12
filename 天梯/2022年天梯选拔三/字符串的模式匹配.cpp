#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int main(void)
{
    int n;
    cin >> n;
    while (n--) {
        string str1, str2;
        cin >> str1 >> str2;
        if (str1.find_first_of(str2) != -1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}