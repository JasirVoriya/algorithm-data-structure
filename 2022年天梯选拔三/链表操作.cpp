#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int main(void)
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        list<int> link;
        while (n--) {
            int x;
            cin >> x;
            bool success = true;
            for (auto l : link) {
                if (x % l == 0) {
                    success = false;
                    break;
                }
            }
            if (success)
                link.push_back(x);
        }
        cout << link.size() << endl;
        {
            auto it = link.begin();
            cout << *it;
            it++;
            while (it != link.end()) {
                cout << " " << *it;
                it++;
            }
            cout << endl;
        }
        {
            auto it = link.rbegin();
            cout << *it;
            it++;
            while (it != link.rend()) {
                cout << " " << *it;
                it++;
            }
            cout << endl;
        }
    }

    return 0;
}