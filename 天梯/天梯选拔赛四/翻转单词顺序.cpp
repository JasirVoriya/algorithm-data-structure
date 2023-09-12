#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e6;
int str[maxn];
int main(void)
{
    while (true)
    {
        int size = 0;
        while ((str[size] = getchar()) != '\n' && str[size] != EOF)
            size++;
        // cout << str << endl;
        bool inword = false;
        int begin, end;
        for (int i = 0; i < size; i++)
        {
            if (str[i] != ' ' && inword == false)
                inword = true, begin = i;
            else if (str[i] == ' ' && inword == true)
            {
                inword = false;
                end = i - 1;
                while (begin < end)
                    swap(str[begin++], str[end--]);
            }
        }
        // cout << str << endl;
        // int a = 0, b = size-1;
        // while (a < size && str[a] == ' ')
        //     a++;
        // while (b > 0 && str[b] == ' ')
        //     b--;
        // while (b >= a)
        //     cout << str[b--];
        for (int i = size - 1; i >= 0; i--)
            putchar(str[i]);
        if (str[size] == EOF)
            return 0;
        cout << endl;
    }
    return 0;
}