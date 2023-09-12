#include <bits/stdc++.h>
using namespace std;
int is_num(string str) {
  for (auto ch : str) {
    if (!(ch >= '0' && ch <= '9')) return -1;
  }
  int n = stoi(str);
  if (!(n >= 1 && n <= 1000)) return -1;
  return n;
}
int main(void) {
  string str;
  getline(cin, str);
  string list[2];
  int pos = str.find_first_of(' ');
  list[0] = str.substr(0, pos);
  list[1] = str.substr(pos + 1, str.size() - pos - 1);
  int a = is_num(list[0]), b = is_num(list[1]);
  if (str[str.size() - 1] == ' ') b = -1;
  if (a != -1 && b != -1) {
    printf("%d + %d = %d\n", a, b, a + b);
  } else {
    string x = a != -1 ? list[0] : "?", y = b != -1 ? list[1] : "?";
    printf("%s + %s = ?\n", x.c_str(), y.c_str());
  }
  return 0;
}