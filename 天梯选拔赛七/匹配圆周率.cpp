#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
char str[maxn],substr[maxn];
int main(void)
{
    cin>>str>>substr;
    int ans=strstr(str,substr)-str;
    if(ans<0)ans=-1;
    cout<<ans<<endl;
    return 0;
}