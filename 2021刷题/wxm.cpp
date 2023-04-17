#include <bits/stdc++.h>
const int max_n = 2e4 + 100;
int a[max_n] = { 0 };
using namespace std;
int main()
{
    ifstream cin;
    ofstream cout;
    cin.open("test2.in");
    cout.open("test2.out");
    int n;
    while (cin >> n) {
        float j;
        for (int i = 0; i < max_n; i++)
            a[i] = 0;
        for (int i = 0; i < n; i++) {
            cin >> j;
            a[(int)(j * 100) + 10000]++;
        }
        int max = a[0];
        for (int i = 1; i < max_n; i++)
            if (a[i] > max)
                max = a[i];
        cout << max << endl;
    }
}