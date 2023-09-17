class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param source string字符串
     * @param pattern string字符串
     * @return int整型
     */
    int ans = 0;
    string s, p;
    void solove(int i, int j) {
        if (j == p.size()) {
            ans++;
            return;
        }
        if (i == s.size())return;
        for (int x = i; x < s.size(); x++) {
            if (s[x] == p[j]) solove(x + 1, j + 1);
        }

        // else solove(i + 1, j);
    }
    int subsequence(string source, string pattern) {
        // write code here
        this->s = source;
        this->p = pattern;
        solove(0, 0);
        return ans;
    }
};