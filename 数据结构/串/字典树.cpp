#include <bits/stdc++.h>
using namespace std;
const int max_n = 3e6 + 10;
struct trie {
  int nex[max_n][65] = {0}, cnt[max_n] = {0}, id = 0, code_size = 65;
  bool exists[max_n] = {false};
  unordered_map<int, int> nums;
  trie() {
    int cnt = 0;
    for (int i = 'a'; i <= 'z'; i++) nums[i] = cnt++;
    for (int i = 'A'; i <= 'Z'; i++) nums[i] = cnt++;
    for (int i = '0'; i <= '9'; i++) nums[i] = cnt++;
  }
  int get(int ch) { return nums[ch]; }
  void insert(const char* str) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
      int c = get(str[i]);
      if (!nex[p][c]) nex[p][c] = ++id;
      p = nex[p][c];
      cnt[p]++;
    }
    exists[p] = true;
  }
  int find_pre(const char* str) {
    int p = 0;
    for (int i = 0; str[i]; i++) {
      int c = get(str[i]);
      if (!nex[p][c]) return 0;
      p = nex[p][c];
    }
    return p;
  }
  int pre_count(const char* str) { return cnt[find_pre(str)]; }
  bool find(const char* str) { return exists[find_pre(str)]; }
  void clear() {
    for (int i = 0; i <= id; i++) {
      cnt[i] = exists[i] = 0;
      for (int j = 0; j < 65; j++) nex[i][j] = 0;
    }
    id = 0;
  }
};
trie tr;
char str[max_n];
int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    tr.clear();
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
      scanf("%s", str);
      tr.insert(str);
    }
    for (int i = 0; i < q; i++) {
      scanf("%s", str);
      printf("%d\n", tr.pre_count(str));
    }
  }
  return 0;
}