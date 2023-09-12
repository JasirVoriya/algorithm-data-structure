#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    string str;
    cin >> str;
    char signs[] = {"+-*/"};
    for (int i = 0; i < 4; i++)
    {
        int x = str.find(signs[i]);
        if (x != str.npos)
        {
            char sign = str[x];
            char a[100] = {0}, b[100] = {0};
            for (int i = 0; i < x; i++)
                a[i] = str[i];
            for (int i = x + 1; i < str.size(); i++)
                b[i - x - 1] = str[i];
            double x = atof(a), y = atof(b);
            switch (sign)
            {
            case '+':
                printf("%.2lf\n", x + y);
                break;
            case '-':
                printf("%.2lf\n", x - y);
                break;
            case '*':
                printf("%.2lf\n", x * y);
                break;
            case '/':
                if (y == 0)
                    cout << "The divisor is 0." << endl;
                else
                    printf("%.2lf\n", x / y);
                break;
            default:
                break;
            }
        }
    }
    return 0;
}