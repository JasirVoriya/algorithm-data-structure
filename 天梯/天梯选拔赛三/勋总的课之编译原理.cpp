#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    freopen("input.cpp", "r", stdin);
    int ch;
    int line = 1;
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n')
        {
            line++;
            continue;
        }
        if (ch == '/')
        {
            if ((ch = getchar()) != EOF)
            {
                if (ch == '\n')
                {
                    line++;
                }
                else if (ch == '/')
                    cout << line << endl;
                else if (ch == '*')
                {
                    cout << line << " ";
                    while ((ch = getchar()) != EOF)
                    {
                        if (ch == '\n')
                        {
                            line++;
                            continue;
                        }
                        if (ch == '*')
                        {
                            if ((ch = getchar()) != EOF)
                            {
                                if (ch == '\n')
                                {
                                    line++;
                                }
                                else if (ch == '/')
                                {
                                    cout << line << endl;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}