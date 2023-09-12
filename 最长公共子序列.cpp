#include <bits/stdc++.h>
using namespace std;
//最长公共子序列
class Solution {
  public:
    string ans, cnt;
    string str1, str2;
	int x=0;
    bool vis[110][110][110] = {false};
    void solve(int i, int j) {
        if (i < 0 || j < 0 || vis[i][j][cnt.size()]) return;
        vis[i][j][cnt.size()] = true;
        x++;
        if (str1[i] == str2[j]) {
            cnt.push_back(str1[i]);
            if (cnt.size() > ans.size()) ans = cnt;
            solve(i - 1, j - 1);
            cnt.pop_back();
            return;
        }
        solve(i - 1, j);
        solve( i,  j - 1);
    }
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 给定两个字符串str1和str2，输出两个字符串的最长公共子序列。如果最长公共子序列为空，则返回"-1"。目前给出的数据，仅仅会存在一个最长的公共子序列
     * @param str1 string字符串 字符串1
     * @param str2 string字符串 字符串2
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        // write code here
        this->str1 = str1, this->str2 = str2;
        solve(str1.size() - 1, str2.size() - 1);
        reverse(ans.begin(), ans.end());
        return ans.size() > 0 ? ans : "-1";
    }
};
int main() {
  Solution s;
  string a, b;
  cin >> a >> b;
  cout << s.LCS(a, b) << endl;
  cout << s.x << endl;
  return 0;
}