#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    int m,n;
    cin>>m>>n;
    int ans=1;
    while(n--)
        ans=(ans*m)%1000;
    printf("%03d",ans);
    return 0;
}