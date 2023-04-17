#include <bits/stdc++.h>
#define INF ((unsigned(-1)) >> 1)
using namespace std;
const int maxn = 1001000;
int A[maxn];
int main(void)
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &A[i]);
        sort(A, A + n);
        int x;
        cin >> x;
        int l = 0, r = n - 1, mid = l + r >> 1, count = 0;
        while (l <= r)
        {
            count++;
            if (A[mid] < x)
                l = mid + 1;
            else if (A[mid] > x)
                r = mid - 1;
            else
                break;
            mid = l + r >> 1;
        }
        if (A[mid] == x)
            cout << count << endl;
        else
            cout << "NO." << endl;
    }
    return 0;
}