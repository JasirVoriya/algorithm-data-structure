#include <bits/stdc++.h>
using namespace std;
unsigned mark[4];
struct IPv4
{
    unsigned char ip[4];
    unsigned char subNet[4];
    void init()
    {
        scanf("%d.%d.%d.%d", ip, ip + 1, ip + 2, ip + 3), getchar();
        for (int i = 0; i < 4; i++)
        {
            subNet[i] = mark[i] & ip[i];
        }
    }
};
int main(void)
{
    unsigned char ip[4], subNet[4];
    scanf("%d.%d.%d.%d", ip, ip + 1, ip + 2, ip + 3), getchar();
    scanf("%d.%d.%d.%d", mark, mark + 1, mark + 2, mark + 3), getchar();
    for (int i = 0; i < 4; i++)
    {
        subNet[i] = mark[i] & ip[i];
    }
    int n;
    scanf("%d", &n), getchar();
    while (n--)
    {
        IPv4 a;
        a.init();
        for (int i = 0; i < 4; i++)
        {
            if (subNet[i] != a.subNet[i])
            {
                cout << "OUTER" << endl;
                goto end;
            }
        }
        cout << "INNER" << endl;
    end:;
    }
    return 0;
}