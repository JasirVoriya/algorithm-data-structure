#include<bits/stdc++.h>
using namespace std;
double ans[1002];
void init()
{
    double flag=1;
    for(int i=1;i<=1000;i++)
    {
        ans[i]=ans[i-1]+(flag/i);
        flag*=-1;
    }
}
int main(void)
{
    init();
    int m,n;
    cin>>m;
    while(m--)
    {
        cin>>n;
        printf("%.2lf\n",ans[n]);
    }
    return 0;
}