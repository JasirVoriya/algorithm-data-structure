#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5;
typedef long long ll;
typedef unsigned long long ull;
int main(void)
{
    ull s, d;
    while (cin >> s >> d) {
        ull i = s;
        for (ull sum = i; sum < d; sum += i)
            i++;
        i--;
        cout << i << endl;
    }

    return 0;
}