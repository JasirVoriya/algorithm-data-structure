#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 5;
int P[maxn];
struct node
{
    int id = 0;
    double l = 0;
};
node data[1000 + 10][1000 + 10];
int main(void)
{
    // map<map<int, int>, double> data;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        for (int i = 0, x; i < k; i++)
        {
            cin >> P[i];
            // P[i] = abs(P[i]);
        }
        for (int i = 0; i < k; i++)
            for (int j = 0; j < k; j++)
                if (P[i] != P[j])
                {
                    data[abs(P[i])][abs(P[j])].l += 1.0 / k;
                    data[abs(P[i])][abs(P[j])].id = P[j];
                }
    }
    int A, B;
    cin >> A >> B;
    int AA = abs(A), AB = abs(B);
    double PA = 0, PB = 0;
    sort(data[AA], data[AA] + n);
    sort(data[AB], data[AB] + n);
    // PA = data[AA][n - 1], PB = data[AB][n - 1];
    if (PA == PB)
        cout << A << " " << B << endl;
    else
    {
    }
    return 0;
}