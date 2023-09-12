#include <bits/stdc++.h>
#define PI acos(-1)
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MAX_N = 1e3;
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    map<string, string> m;
    m["ChuiZi"] = "Bu";
    m["Bu"] = "JianDao";
    m["JianDao"] = "ChuiZi";
    for (int i = 1; true; i++) {
        string str;
        cin >> str;
        if (str == "End")
            break;
        if (i % (n + 1) == 0)
            cout << str << endl;
        else
            cout << m[str] << endl;
    }

    return 0;
}