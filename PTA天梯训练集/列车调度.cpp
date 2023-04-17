#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int que[maxn];
int main(void)
{
    int n;
    cin >> n;
    int size = 0;
    int k;
    scanf("%d", &k);
    que[size++] = k;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &k);
        if (k < que[size - 1])
        {
            int l = 1, r = size - 1, mid = (l + r) / 2;
            while (l <= r)
            {
                if (que[mid] < k)
                    l = mid + 1;
                else
                    r = mid - 1;
                mid = (l + r) / 2;
            }
            que[l] = k;
        }
        else
            que[size++] = k;
    }
    cout << size << endl;
    return 0;
}