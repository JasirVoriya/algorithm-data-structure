#include <bits/stdc++.h>
using namespace std;
class BigNum
{
private:
    static const int maxn = 10000;
    char data[maxn];
    int len = 0;
    bool push_back(int ch)
    {
        if (len == maxn)
            return false;
        data[len++] = ch;
        return true;
    }

public:
    BigNum(const char *str)
    {
        int i = strlen(str) - 1, j = 0;
        len = i + 1;
        while (i >= 0)
            this->data[j++] = str[i--] - '0';
    }
    BigNum operator+(BigNum &_x)
    {
        BigNum res("");
        int len1 = this->size(), len2 = _x.size();
        int i = 0, j = 0, base = 0;
        while (i < len1 && j < len2)
        {
            res.push_back((this->data[i] + base + _x.data[j]) % 10);
            base = (this->data[i] + base + _x.data[j]) / 10;
            i++, j++;
        }
        while (i < len1)
        {
            res.push_back((this->data[i] + base) % 10);
            base = (this->data[i] + base) / 10;
            i++;
        }
        while (j < len2)
        {
            res.push_back((_x.data[j] + base) % 10);
            base = (_x.data[j] + base) / 10;
            j++;
        }
        if (base)
            res.push_back(base);
        return res;
    }
    void print()
    {
        for (int i = this->size() - 1; i >= 0; i--)
            printf("%d", data[i]);
        putchar('\n');
    }
    int size()
    {
        return len;
    }
};
int main(void)
{
    BigNum f1("1"), f2("1"), f3("2");
    int n;
    cin >> n;
    if (n <= 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 2; i <= n; i++)
    {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    f3.print();
}