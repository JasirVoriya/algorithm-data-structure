#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int main(void)
{
    int n;
    cin >> n;
    vector<double> arr;
    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    printf("%.2lf\n",arr[arr.size() - 1]);
    return 0;
}