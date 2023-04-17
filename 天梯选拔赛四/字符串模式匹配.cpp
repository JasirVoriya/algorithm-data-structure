#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7;
char str[maxn], substr[maxn];
int Next[maxn];
void InitNext()
{
    Next[0] = -1;
    int j = -1, i = 0;
    int size = strlen(substr);
    while (i < size)
    {
        if (j == -1 || substr[j] == substr[i])
            Next[++i] = ++j;
        else
            j = Next[j];
    }
}
int kmp()
{
    int j = 0, i = 0, ans = 0;
    while (str[i])
    {
        if (j == -1 || str[i] == substr[j])
        {
            i++, j++;
            if (j != -1 && substr[j] == 0)
            {
                ans++;
                j = Next[j];
            }
        }
        else
            j = Next[j];
    }
    return ans;
}
int main(void)
{
    cin >> str >> substr;
    InitNext();
    cout << kmp() << endl;
    return 0;
}