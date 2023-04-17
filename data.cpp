#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull MAX_N = 1e10;
const ull STEP = 23452314;
int main(void) {
    ofstream cout;
    cout.open("in.txt", ios::out);
    for (ull a = 1; a < MAX_N; a += STEP) {
        for (ull b = 1; b < MAX_N; b += STEP)
            for (ull p = 1; p < MAX_N; p += STEP)
                cout << a << " " << b << " " << p << endl;
    }
    cout.close();
    return 0;
}