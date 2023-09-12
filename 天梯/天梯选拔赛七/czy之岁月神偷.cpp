#include <bits/stdc++.h>
using namespace std;
int fun(int x)
{
    int sum = 0;
    while (x)
    {
        sum += x % 10;
        x /= 10;
    }
    // cout<<sum<<endl;
    return sum;
}
int main(void)
{
    int n;
    while (cin >> n)
    {
        set<int> ans;
        for (int i = 0, x; i < n; i++)
        {
            cin >> x;
            ans.insert(fun(x));
        }
        cout << ans.size() << endl;
        auto it = ans.begin();
        cout << *it++;
        while (it != ans.end())
            cout << " " <<* it++;
        cout << endl;
    }
    return 0;
}