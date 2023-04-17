#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    string str1, str2;
    cin >> str1 >> str2;
    int i;
    for (i = 1; i < str1.size(); i++)
        if (str1[i] >= str2[0])
            break;
    for (int j = 0; j < i; j++)
        cout << str1[j];
    cout << str2[0];
    return 0;
}