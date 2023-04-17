#include <bits/stdc++.h>
using namespace std;
void print(vector<int>& res)
{
    for (auto it = res.begin(); it != res.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
// 求阶乘进制
vector<int> factorial_base(int n)
{
    vector<int> ans;
    for (int i = 1; n; i++) {
        ans.push_back(n % i);
        n /= i;
    }
    return ans;
}
// 序数法求全排列
vector<int> permutation(int n)
{
    vector<int> base = factorial_base(n);
    vector<int> ans;
    for (int i = 0; i < base.size(); i++) {
        ans.insert(ans.begin() + base[i], i + 1);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(void)
{
    int n;
    cin >> n;
    vector<int> res = permutation(n);
    print(res);
    return 0;
}