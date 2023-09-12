#include <bits/stdc++.h>
using namespace std;
void print(vector<int>& res)
{
    for (auto it = res.begin(); it != res.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
// 字典序求下一个排列
void nextPermutation(vector<int>& nums)
{
    int i = nums.size() - 1;
    while (i && nums[i - 1] >= nums[i])
        i--;
    if (i) {
        int j = i - 1;
        int n = nums.size() - 1;
        while (i <= n && nums[j] >= nums[n])
            n--;
        swap(nums[j], nums[n]);
    }
    reverse(nums.begin() + i, nums.end());
}
int main(void)
{
    int n;
    cin >> n;
    vector<int> vec;
    for (int x, i = 0; i < n; i++) {
        cin >> x;
        vec.push_back(x);
    }
    nextPermutation(vec);
    print(vec);
    return 0;
}