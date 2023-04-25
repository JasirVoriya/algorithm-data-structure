#include <bits/stdc++.h>
using namespace std;
int main(void) {
    ifstream cin1("data1.out"), cin2("data2.out");
    ofstream cout("check.txt");
    int n1, n2;
    string s1, s2;
    while (cin1 >> n1 >> s1) {
        cin2 >> n2 >> s2;
        if (n1 != n2 || s1 != s2) {
            cout << n1 << endl << s1 << endl;
            cout << n2 << endl << s2 << endl;
            cout << endl;
        }
    }
    return 0;
}