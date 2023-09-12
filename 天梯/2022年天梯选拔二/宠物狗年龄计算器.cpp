#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2;
const int INF = 0x3f3f3f3f;
typedef long long ll;
int main(void)
{
    double x;
    cin >> x;
    double age = log(x) * 16 + 31;
    printf("Your dog is %.2lf years old in human age.",age);
}