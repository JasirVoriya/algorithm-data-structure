#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef unordered_set<int> USI;
#define US unordered_set
#define UM unordered_map
const int maxn = 1e4 + 5;
const int inf = 0x3f3f3f3f;
bool dp[maxn][maxn];
string str;
int main(void) {
  getline(cin, str);
  for (int i = 0; i < str.size(); i++) dp[i][i] = true;
  int ans = 1;
  for (int r = 1; r < str.size(); r++) {
    for (int l = 0; l < r; l++) {
      dp[l][r] = str[l] == str[r] && (l + 1 == r || dp[l + 1][r - 1]);
      if (dp[l][r]) ans = max(ans, r - l + 1);
    }
  }
  cout << ans << endl;
  return 0;
}