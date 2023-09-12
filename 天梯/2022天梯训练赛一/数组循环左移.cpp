#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5;
int arr[MAX_N];
int main(void)
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << arr[(0 + m) % n];
    for (int i = 1; i < n; i++) {
        cout << " " << arr[(i + m) % n];
    }
    cout << endl;
    return 0;
}