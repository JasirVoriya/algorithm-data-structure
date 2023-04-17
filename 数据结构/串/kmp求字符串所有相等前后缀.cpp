#include <cstdio>
#include <iostream>
using namespace std;
static const int maxn = 1e6 + 5;
class SubStr
{
    char str[maxn];
    int len;

public:
    int next[maxn];
    char operator[](int n)
    {
        return str[n];
    }
    SubStr()
    {
        len = 0;
    }
    int size()
    {
        return len;
    }
    bool input()
    {
        bool fail = scanf("%s", str) == EOF;
        if (fail)
            return false;
        next[0] = -1;
        int k = -1, j = 0; //k从前缀的第一个字符向后遍历
                           //j从后缀的第一个字符向后遍历
        while (str[j] != '\0')
        {
            if (k == -1 || str[k] == str[j])
                next[++j] = ++k;
            else
                k = next[k];
        }
        len = j;
        return true;
    }
};
SubStr str;
int ans[maxn];
int main(void)
{
    // freopen("input.txt", "r", stdin);
    while (str.input())
    {
        int count = 0;
        for (int i = str.next[str.size()]; i > 0; i = str.next[i])
            ans[count++] = i;
        while (--count >= 0)
            printf("%d ", ans[count]);
        printf("%d\n", str.size());
    }
    return 0;
}