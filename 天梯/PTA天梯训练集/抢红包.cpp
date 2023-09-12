#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
struct Node
{
    int id = 0, count = 0;
    double money = 0;
};
Node people[maxn];
bool cmp(Node &a, Node &b)
{
    if (a.money == b.money)
    {
        if (a.count == b.count)
            return a.id < b.id;
        else
            return a.count > b.count;
    }
    else
        return a.money > b.money;
}
int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        people[i].id = i;
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            int n, p;
            cin >> n >> p;
            people[i].money -= p;
            people[n].money += p;
            people[n].count++;
        }
    }
    sort(people + 1, people + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        printf("%d %.2f\n", people[i].id, people[i].money/100);
    }
    return 0;
}