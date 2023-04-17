#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> P;
int main(void)
{
    int n;
    cin >> n;
    vector<P> vec;
    while (n--) {
        int score;
        string name;
        cin >> name >> score;
        vec.push_back(P(score, name));
    }
    sort(vec.begin(), vec.end(), [](P a, P b) -> bool {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    });
    for (auto val : vec) {
        cout << val.second << " " << val.first << endl;
    }
    return 0;
}