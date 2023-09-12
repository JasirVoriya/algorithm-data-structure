
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int main(void)
{
    string arr[21] = {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
        "twenty"
    };
    map<string, int> s_to_i;
    map<int, string> i_to_s;
    for (int i = 0; i <= 20; i++) {
        s_to_i[arr[i]] = i;
        i_to_s[i] = arr[i];
    }
    int t;
    cin >> t;
    while (t--) {
        string first, second;
        cin >> first >> second;
        int x = s_to_i[first] + s_to_i[second];
        cout << i_to_s[x] << endl;
    }
    return 0;
}