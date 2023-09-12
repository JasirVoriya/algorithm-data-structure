#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int index, data;
};
const int maxn = 1e2 + 5;
Node arr[maxn];
bool cmp(Node &a, Node &b)
{
    return a.data > b.data;
}
int main(void)
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].data;
            arr[i].index = i + 1;
        }
        sort(arr, arr + n, cmp);
        cout << arr[0].index << " " << arr[1].index << endl;
    }
    return 0;
}