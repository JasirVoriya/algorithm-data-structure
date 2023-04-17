#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    string a, b;
    cin >> a >> b;
    int count = -1;
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == '1')
            count++;
        count++;
    }
    cout << count << endl;
}