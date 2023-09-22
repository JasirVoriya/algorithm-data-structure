#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<string> uset;
    string str;
    int n;
    cin>>n;
    while(n--){
        cin>>str;
        sort(str.begin(),str.end());
        uset.insert(str);
    } 
    cout<<uset.size()<<endl;
}
// 64 位输出请用 printf("%lld")