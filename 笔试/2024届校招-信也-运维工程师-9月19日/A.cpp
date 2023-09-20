#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int max_n = 1e5 + 5;
int arr[max_n];
int main() {
  for(int i=0;i<5;i++)cin>>arr[i];
  sort(arr,arr+5,[](int a,int b){return a>b;});
  for(int i=0;i<5;i++)cout<<arr[i]<<" ";
  return 0;
}
// 64 位输出请用 printf("%lld")