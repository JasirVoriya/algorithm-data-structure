#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<string, int> &a, pair<string, int> &b) {
    if (a.second != b.second) return a.second > b.second;
    return a.first < b.first;
}
int main(void) {
    string str;
    map<string, int> dict;
    vector<pair<string, int>> list;
    while (cin >> str) {
        dict[str]++;
    }
    for (auto it = dict.begin(); it != dict.end(); it++) {
        // if (it->second >= 3) cout << it->first << endl;
        list.push_back(*it);
    }
    sort(list.begin(), list.end(), cmp);
    for (auto it = list.begin(); it != list.end(); it++) {
        if (it->second >= 3) cout << it->first << endl;
    }
    return 0;
}