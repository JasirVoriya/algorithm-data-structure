#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 10;
int a[maxn];
int height[maxn];
void fun(int *array, int size, int i)
{
    if (size <= 0)
        return;
    int index = 0;
    for (int i = 1; i < size; i++)
        index = array[index] > array[i] ? index : i;
    height[array - a + index] = i;
    fun(array, index, i + 1);
    fun(array + index + 1, size - index - 1, i + 1);
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        fun(a, n, 0);
        for (int i = 0; i < n; i++)
            cout << height[i] << " ";
        cout << endl;
    }
    return 0;
}