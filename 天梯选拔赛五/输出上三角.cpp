#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
void print(const int graph[][maxn], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
            printf("%4d",graph[i][j]);
        cout << endl;
    }
}
void solove(int graph[][maxn], int size, int data)
{
    if (size <= 0)
        return;
    for (int i = 0; i < size; i++)
        graph[0][i] = data++;
    for (int i = 1; i < size; i++)
        graph[i][size - 1 - i] = data++;
    for (int i = size - 2; i > 0; i--)
        graph[i][0] = data++;
    // print(graph, size);
    solove((int(*)[maxn])(&graph[1][1]), size - 3, data);
}
int main(void)
{
    int n;
    while (cin >> n)
    {
        int graph[maxn][maxn] = {0};
        solove(graph, n, 1);
        print(graph, n);
    }
    return 0;
}