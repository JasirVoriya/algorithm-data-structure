#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    string str;
    getline(cin, str);
    int first = str.find_first_of(','), second = str.find_last_of(',');
    string s = str.substr(0, first);
    string s1 = str.substr(first + 1, second - (first + 1));
    string s2 = str.substr(second + 1, str.size() - (second + 1));
    int start = s.find_first_of(s1), end = s.find_last_of(s2);
    cout << max(-1, (int)((end - s2.size()) - (start + s1.size()) + 1));
    return 0;
}