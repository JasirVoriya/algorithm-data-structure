#include <bits/stdc++.h>
using namespace std;
const int max_n = 3e8 + 5;
class Solution {
 public:
  using ll = long long;
  //求出cur为根节点的字典树的节点个数
  int step(ll cur, ll n) {
    ll s = 0, l = cur, r = cur;
    //层序遍历，l为层的左边界，r为层的右边界（右边界不能超过n）
    while (l <= n) {
      s += min(r, n) - l + 1;  //计算出这一层的节点数量
      l = l * 10;              //计算出下一层的左边界
      r = r * 10 + 9;          //计算出下一层的右边界
    }
    return s;
  }
  int findKthNumber(int n, int k) {
    int cur = 1;
    k--;
    while (k > 0) {
      int cnt = step(cur, n);
      if (cnt <= k) {  //目标在不在cur的子节点里
        k -= cnt;      //跳过所有cur子节点
        cur++;         //向字典树右边走一步
      } else {         //目标在cur的子节点下面
        cur *= 10;  //向字典树下方走一步，进入cur的第一个子节点
        k--;        //离目标又近一步
      }
    }
    return cur;
  }
};
int main(void) {
  Solution s;
  int n, k;
  cin >> n >> k;
  cout << s.findKthNumber(n, k) << endl;
  return 0;
}