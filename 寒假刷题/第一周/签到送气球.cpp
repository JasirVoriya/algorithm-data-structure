#include <bits/stdc++.h>
using namespace std;
struct team
{
    bool problem[256] = {false};
    int ac = 0;
};
int main(void)
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        team teams[60];
        int n, m;
        cin >> n >> m;
        for (int j = 1; j <= m; j++)
        {
            int tid;
            char proid;
            string sub;
            cin >> tid >> proid >> sub;
            if (sub == "AC")
            {
                if (teams[tid].problem[proid] == false)
                    teams[tid].ac++;
                teams[tid].problem[proid] = true;
            }
        }
        cout << "Case #" << i << ":\n";
        for (int i = 1; i <= n; i++)
            cout << teams[i].ac << ' ';
        cout << endl;
    }
    return 0;
}