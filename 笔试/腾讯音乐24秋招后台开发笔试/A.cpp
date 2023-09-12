#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    using ll = long long;
    bool check(int a, int b) {
        ll res = a * b;
        int cnt = 0;
        while (res && cnt <= 1)cnt += (res % 10) != 0, res /= 10;
        return cnt == 1;
    }
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param arr int整型vector
     * @return int整型
     */
    int perfectPair(vector<int>& arr) {
        // write code here
        int n = arr.size();
        int ans=0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ans+=check(arr[i],arr[j]);
            }
        }
        return ans;
    }
};
int main(){
	
}