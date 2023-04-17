#include <iostream>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;
int main()
{
    priority_queue<ll, vector<ll>, greater<ll>> prique;
    // cout<<"YES"<<endl;
    ll n, value;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> value;
        prique.push(value);
    }
    ll sum = 0, a, b;
    for (ll i = 0; i < n - 1; i++)
    {
        a = prique.top(), prique.pop();
        b = prique.top(), prique.pop();
        sum += a + b;
        prique.push(a + b);
    }
    cout << sum << endl;
    return 0;
}