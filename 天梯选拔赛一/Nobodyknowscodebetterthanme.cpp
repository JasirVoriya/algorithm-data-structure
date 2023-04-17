#include <bits/stdc++.h>
using namespace std;
struct node
{
    long long int id, score, rank;
};
const int maxn = 5 * 1e3 + 10;
node a[maxn];
bool cmp1(node &a, node &b)
{
    return a.score > b.score;
}
bool cmp2(node &a, node &b)
{
    return a.id < b.id;
}
int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].id >> a[i].score;
    }
    sort(a, a + n, cmp1);
    a[0].rank = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i].score == a[i - 1].score)
            a[i].rank = a[i - 1].rank;
        else
            a[i].rank = i+1;
    }
    sort(a, a + n, cmp2);
    for (int i = 0; i < n; i++)
        cout << a[i].rank << endl;
    return 0;
}