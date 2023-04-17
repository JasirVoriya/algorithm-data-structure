#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int main(void)
{
    map<string, string> trans;
    string key, val;
    char str[MAX_N];
    while (true) {
        getline(cin, val);
        if (val == "")
            break;
        int index = val.find_first_of(" ");
        key = val.substr(index + 1, val.size() - (index + 1));
        val = val.substr(0, index);
        trans[key] = val;
    }
    while (cin >> key) {
        if (trans.count(key)) {
            cout << trans[key] << endl;
        } else {
            cout << "eh" << endl;
        }
    }
    return 0;
}