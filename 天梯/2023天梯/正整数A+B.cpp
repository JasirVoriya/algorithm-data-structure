#include <bits/stdc++.h>
using namespace std;
int is_num(string &str) {
  for (auto ch : str) {
    if (!(ch >= '0' && ch <= '9')) return -1;
  }
  int n = stoi(str);
  return n >= 1 && n <= 1000 ? n : -1;
}
vector<string> split(string &str, char sep) {
  size_t start = 0, index = 0;
  vector<string> ans;
  while ((index = str.find_first_of(sep, start)) != string::npos) {
    if (index - start != 0) ans.push_back(str.substr(start, index - start));
    start = index + 1;
  }
  if (str.size() - start != 0)
    ans.push_back(str.substr(start, str.size() - start));
  return ans;
}
int main(void) {
  string str;
  getline(cin, str);
  vector<string> nums;
  int index = str.find_first_of(' ');
  nums.push_back(str.substr(0, index));
  nums.push_back(str.substr(index + 1, str.size() - (index + 1)));
  string ans[2];
  bool success = true;
  for (int i = 0; i < 2; i++) {
    if (is_num(nums[i]) == -1) {
      ans[i] = "?";
      success = false;
    } else {
      ans[i] = nums[i];
    }
  }
  if (success) {
    int a = stoi(nums[0]), b = stoi(nums[1]), sum = a + b;
    printf("%d + %d = %d\n", a, b, sum);
  } else {
    printf("%s + %s = %s\n", ans[0].c_str(), ans[1].c_str(), "?");
  }
  return 0;
}