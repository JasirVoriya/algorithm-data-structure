#include <bits/stdc++.h>
using namespace std;
class SubStr
{
    static const int maxn=1e4+5;
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
    void input()
    {
        scanf("%s", str);
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
    }
};
char str1[1000000 + 5];
SubStr str2;
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        str2.input();
        scanf("%s", str1);
        int i = 0, j = 0;
        int count = 0;
        while (str1[j] != '\0')
        {
            if (i == -1 || str2[i] == str1[j])
                i++, j++;
            else
                i = str2.next[i];
            if (i == str2.size())
                count++, i = str2.next[i];
        }
        printf("%d\n", count);
    }
    return 0;
}