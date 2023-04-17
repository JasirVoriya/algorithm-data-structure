#include <iostream>
#include <cstring>
using namespace std;
typedef long long ull;
const ull maxn = 1e6 + 10;
const ull base = 65535;
ull ha[maxn];
ull pro[maxn];
char dna[maxn];
void init()
{
    ha[0] = 0;
    pro[0] = 1;
    for (ull i = 1; dna[i]; i++)
    {
        ha[i] = ha[i - 1] * base + dna[i];
        pro[i] = pro[i - 1] * base;
    }
}
bool fun(ull l1, ull r1, ull l2, ull r2)
{
    return ha[r1] - ha[l1 - 1] * pro[r1 - l1 + 1] == ha[r2] - ha[l2 - 1] * pro[r2 - l2 + 1];
}
int main(void)
{
    cin >> (dna + 1);
    init();
    ull m;
    cin >> m;
    while (m--)
    {
        ull l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (fun(l1, r1, l2, r2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}