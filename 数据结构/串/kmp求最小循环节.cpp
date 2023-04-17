#include <cstdio>
class SubStr
{
    static const int maxn = 1e6 + 5;
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
        bool ok = ~scanf("%s", str);
        if (!ok)
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
int main(void)
{
    int n;
    int count = 0;
    while (str.input())
    {
        if (str[0] == '.')
            break;
        int size = str.size();
        if (size % (size - str.next[size]) == 0)
            printf("%d\n", size / (size - str.next[size]));
        else
            puts("1");
    }
    return 0;
}