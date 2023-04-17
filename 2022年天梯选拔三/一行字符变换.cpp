#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int main(void)
{
    string str;
    getline(cin,str);
    for (char& ch : str) {
        if (ch >= 'a' && ch <= 'z') {
            ch -= 'a' - 'A';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch += 'a' - 'A';
        }
    }
    cout << str << endl;
    return 0;
}