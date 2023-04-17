#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2;
const int INF = 0x3f3f3f3f;
typedef long long ll;
void create(char str1[], char str2[], int size)
{
    if (size == 0)
        return;
    char ch = str1[0];
    int i = 0;
    while (str2[i] != ch)
        i++;
    create(str1 + 1, str2, i);
    create(str1 + 1 + i, str2 + 1 + i, size - i - 1);
    cout << ch;
}
int main(void)
{
    int n;
    cin >> n;
    char str1[MAX_N], str2[MAX_N], str3[MAX_N];
    cin >> str1 >> str2;
    create(str1, str2, n);
    return 0;
}