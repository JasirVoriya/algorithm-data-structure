#include <bits/stdc++.h>
using namespace std;
long int num, temp;
int main() {
    ifstream cin("data.in");
    ofstream cout("data2.out");
    while (cin >> num) {
        int first = 0, len = 0, maxn = sqrt(num) + 1;
        for (int i = 2; i <= maxn; i++) {
            int j;
            temp = 1;
            for (j = i; j <= maxn; j++) {
                temp *= j;
                if (num % temp != 0) break;
            }
            if (j - i > len) {
                len = j - i;
                first = i;
            }
        }
        if (first == 0) {
            cout << num << endl << num;
        } else {
            cout << num << endl;
            for (int i = 0; i < len; i++) {
                cout << first + i;
                if (i != len - 1) cout << '*';
            }
        }
        cout << endl;
    }
    return 0;
}