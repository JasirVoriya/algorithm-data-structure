class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @param k int整型
     * @return int整型
     */
    int maximumScore(vector<int>& nums, int k) {
        // write code here
        sort(nums.begin(), nums.end());
        int ans = 1;
        int l = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[l] + k >= nums[i] - k)ans = max(ans, i - l + 1);
            else l++;
        }
        return ans;
    }
};