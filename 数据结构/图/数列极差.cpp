#include <bits/stdc++.h>
using namespace std;
const int maxn = 50100;
int main(void)
{
    int a[maxn], b[maxn];
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", a + i);
            b[i] = a[i];
        }
        int *pa = a, na = n, *pb = b, nb = n;
        while (na > 1)
        {
            sort(pa, pa + na);
            pa[1] = pa[0] * pa[1] + 1;
            pa++, na--;
        }
        while (nb > 1)
        {
            sort(pb, pb + nb);
            pb[nb - 2] = pb[nb-1] * pb[nb - 2] + 1;
            nb--;
        }
        printf("%d\n", pa[0] - pb[0]);
    }
    return 0;
}