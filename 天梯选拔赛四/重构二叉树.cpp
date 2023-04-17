#include <bits/stdc++.h>
using namespace std;
void fun(const char *a, const char *b, int size) //先序、中序、长度
{
    if (size <= 0)
        return;
    int index = 0;
    while (a[0] != b[index])
        index++;
    fun(a + 1, b, index);
    fun(a + index + 1, b + index + 1, size - index - 1);
    cout << a[0];
}
using namespace std;
int main(void)
{
    string a, b;
    while (cin >> a >> b)
    {
        fun(a.c_str(), b.c_str(), a.size());
        cout << endl;
    }

    return 0;
}