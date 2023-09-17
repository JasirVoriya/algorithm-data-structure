/*
链接：https://ac.nowcoder.com/acm/problem/21682
来源：牛客网

星灵(Protoss)有一个非常重要的建筑是水晶塔(Pylon)。

能量场(Energy Field)，是一个以水晶塔为圆心，半径为R的圆，R为正整数。所有的能量场的半径都是相同的。

星灵的绝大部分建筑都需要放置在能量场中。在星际争霸2(StarCraftⅡ)中，用折跃门(Warp Gate)折跃单位也需要放置在能量场中。如果水晶塔被破坏，那么能量场将消失，一些不在能量场范围内的建筑就会停止工作。所以水晶塔对于星灵来说，是一个十分重要的建筑。

tokitsukaze建造了n个水晶塔。她能够设定能量场的半径R。她想把每一个能量场都连接起来，使得单位(看成二维平面上的一个点)能从任意一个水晶塔出发，能到达所有的水晶塔，而且始终在能量场的范围内。她把这种状态，称为星灵的Link状态。

能量场连接的定义是：两个能量场相交或者相切。

tokitsukaze想知道，能量场的半径R至少为多少，能使星灵达到Link状态。

再次提醒：R为正整数。

输入描述:
第一行包含一个正整数T(T≤20)，表示T组数据。

对于每一组数据：
第一行包含一个正整数n(2≤n≤500)，表示有n个水晶塔。
接下来n行，每行两个整数x,y(-10^9≤x,y≤10^9)，表示这个水晶塔的坐标为(x,y)。数据保证没有两个水晶塔在同一个坐标。
输出描述:
对于每组数据，输出一个正整数，表示最小的R，能使星灵达到Link状态。
示例1
输入
复制
2
3
-3 0
1 0
3 2
3
-4 2
-4 -3
1 0
输出
复制
2
3
*/
#include<bits/stdc++.h>
using namespace std;
using PII=pair<int,int>;
using ll=long long;
using PLL=pair<ll,ll>;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int max_n=5e2+5;
PLL arr[max_n];
int root[max_n];
int n;
void init(){
    for(int i=0;i<n;i++)root[i]=i;
}
int get(int x){
    if(root[x]==x)return x;
    return root[x]=get(root[x]);
}
void unionx(int x,int y){
    root[get(root[x])]=get(root[y]);
}
bool isone(){
    for(int i=1;i<n;i++){
        if(get(root[i-1])!=get(root[i]))return false;
    }
    return true;
}
bool check_one(PLL& a,PLL& b,ll r){
    //判断两个圆是否相交
    ll x=a.first-b.first,y=a.second-b.second;
    double dis=sqrt(x*x+y*y);
    return dis-2*r<=0.0000001;
}
bool check(ll r){
    init();

    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(get(i)==get(j))continue;
            if(check_one(arr[i],arr[j],r)){
                unionx(i, j);
            }
        }
    }
    return isone();
}
int main(void){
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++)scanf("%lld%lld",&arr[i].first,&arr[i].second);
        ll l=1,r=linf,ans=linf;
        while(l<=r){
            ll mid=(l+r)>>1;
            if(check(mid)){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}