#include <bits/stdc++.h>
using namespace std;
bool isOne(int x)
{
    if (x / 10 == 0)
        return x == 1;
    return x % 10 == 1 && isOne(x / 10);
}
char ans[10000] = {0};
int main(void)
{
    int x;
    while (cin >> x)
    {
        int count = 0;
        int all = x, add = 0;
        int size = 0;
        while (true)
        {
            for (int i = 0; i <= 9; i++)
            {
                if ((all * i + add) % 10 == 1)
                {
                    ans[size++] = '0' + i;
                    count++;
                    if (isOne(all * i + add))
                    {
                        int temp = (all * i + add) / 10;
                        while (temp)
                            count++, temp /= 10;
                        goto end;
                    }
                    else
                    {
                        add = (all * i + add) / 10;
                        break;
                    }
                }
            }
        }
    end:;
        for (int i = size - 1; i >= 0; i--)
            cout << ans[i];
        cout << " " << count << endl;
    }
}