#include <cstdio>
#include <algorithm>
const int base = 131;
const int mod = 1e5 / 2;
struct node
{
    int snow[6];
};
bool same(node &a, node &b)
{
    for (int i = 0; i < 6; i++)
        if (a.snow[i] != b.snow[i])
            return false;
    return true;
}
node snows[mod][30];
int book[mod];
int main(void)
{
    int n;
    scanf("%d", &n);
    bool found = false;
    while (n--)
    {
        int hash = 0;
        node a;
        for (int i = 0; i < 6; i++)
        {
            scanf("%d", a.snow + i);
            hash = (hash + a.snow[i] * base % mod) % mod;
        }
        if (!found)
        {
            std::sort(a.snow, a.snow + 6);
            for (int i = 0; i < book[hash]; i++)
            {
                if (same(a, snows[hash][i]))
                    found = true;
            }
            snows[hash][book[hash]++] = a;
        }
    }
    if (found)
        puts("Twin snowflakes found.");
    else
        puts("No two snowflakes are alike.");
    return 0;
}