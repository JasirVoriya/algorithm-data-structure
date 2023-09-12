#include <iostream>
#include <stdio.h>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    double* arr = new double[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    if (!(x >= 1 && x <= n)) {  
        cout << "error";
        return 0;
    }
    if ((int)arr[x] == arr[x])
        printf("%.0lf", arr[x]);
    else
        printf("%.1lf", arr[x]);
    return 0;
}