#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    ifstream in;
    ofstream out;
    in.open("in");
    out.open("out");
    while (in >> n)
    {
        for (int i = 1, begin = 1; i <= n; begin += i, i++)
        {
            for (int j = 0, sum = begin; j <= n - i; j++, sum += i + j)
                out << sum << " ";
        }
        out << endl;
    }
}
