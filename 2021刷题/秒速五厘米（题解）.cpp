#include<bits/stdc++.h>
using namespace std;
inline int read() {int x=0,f=1;char c=getchar();while(c!='-'&&(c<'0'||c>'9'))c=getchar();if(c=='-')f=-1,c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
typedef long long ll;
const int maxn = 1e7+10;
int a[maxn];    
int n,m;
int judge(int x){
    ll t=0;
    for(int i=1;i<=n;i++){
        t+=(a[i]+x-1)/x;//向上取整的意思
    }
    if(t>m)
        return 0;
    else
        return 1; 
}
int main()
{
    cin>>n>>m;
    int l=1e7,r=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int ans;
    while(l>=r){
        int mid=(l+r)/2;
        if(judge(mid)){
            ans=mid;
            l=mid-1;
        }
        else{
            r=mid+1;
        }
    }
    printf("%d",ans);
    return 0;
} 