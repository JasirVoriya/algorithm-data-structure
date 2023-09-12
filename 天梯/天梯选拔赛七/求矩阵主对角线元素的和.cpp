#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    double arr[20][20];
    int n;
    cin >> n;
    double sum=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if(i==j)sum+=arr[i][j];
        }
    }
    printf("%.1lf\n",sum);
    return 0;
}