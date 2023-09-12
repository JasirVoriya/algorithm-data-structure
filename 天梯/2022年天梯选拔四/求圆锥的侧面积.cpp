#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;

int main(void)
{
    double r, h, l;
    cin >> r >> h;
    l = sqrt(r * r + h * h);
    printf("%.2lf", PI * r * l);
    return 0;
}