#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int add, data, next;
};
const int maxn = 1e5 + 5;
Node arr[maxn];
bool cmp(Node &a, Node &b)
{
    return a.data < b.data;
}
int main(void)
{
    int n, head;
    cin >> n >> head;
    set<int> next;
    for (int i = 0; i < n; i++)
    {
        Node &x = arr[i];
        cin >> x.add >> x.data >> x.next;
        next.insert(x.next);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i].add == head)
            continue;
        if (next.count(arr[i].add) == 0)
            arr[i].data = -10;
    }
    sort(arr, arr + n, cmp);
    int i = 0;
    while (arr[i].data < 0)
        i++;
    while (i < n - 1)
    {
        arr[i].next = arr[i + 1].add;
        printf("%05d %d %05d->", arr[i].add, arr[i].data, arr[i].next);
        i++;
    }
    arr[n - 1].next = -1;
    printf("%05d %d %d", arr[n - 1].add, arr[n - 1].data, arr[n - 1].next);

    return 0;
}