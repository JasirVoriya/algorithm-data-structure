#include <bits/stdc++.h>
using namespace std;
struct method {
  string name, type;
  vector<string> args;
  string key;
};
vector<string> split(string str, char ch) {
  vector<string> ans;
  size_t index = 0, start = 0;
  while ((index = str.find_first_of(ch, start)) != string::npos) {
    if (index != start) ans.push_back(str.substr(start, index - start));
    start = index + 1;
  }
  if (start < str.size()) ans.push_back(str.substr(start, str.size() - start));
  return ans;
}
method* create_method(string str, bool istype = true) {
  auto mtd = new method();
  if (istype) {
    size_t l = str.find_first_of(' ');
    mtd->type = str.substr(0, l);
    str = str.substr(l + 1, str.size() - l - 1);
  }
  auto res1 = split(str, '(');
  mtd->name = res1[0];
  res1[1].pop_back();               //删除最后一个）
  auto args = split(res1[1], ',');  //分割出参数
  if (!istype)
    mtd->args = args;
  else {
    for (auto arg : args)
      mtd->args.push_back(arg.substr(0, arg.find_first_of(' ')));
  }
  mtd->key = mtd->name + ":";
  for (auto arg : mtd->args) {
    mtd->key += arg + ",";
  }
  return mtd;
}
int main() {
  int q;
  cin >> q;
  unordered_set<string> keys, names;
  while (q--) {
    int op;
    cin >> op;
    getchar();
    string cmd;
    getline(cin, cmd);
    if (op == 1) {
      //声明方法
      auto mtd = create_method(cmd);
      //判断是否定义
      if (keys.find(mtd->key) != keys.end()) {
        printf("method %s is already defined.\n", mtd->name.c_str());
        continue;
      }
      names.insert(mtd->name);
      keys.insert(mtd->key);
      cout << "ok." << endl;
    } else if (op == 2) {
      //调用方法
      auto mtd = create_method(cmd,false);
      if (names.find(mtd->name) != names.end()) {
        if (keys.find(mtd->key) != keys.end()) {
          cout << "ok." << endl;
        } else {
          printf("method %s cannot be applied to given types.\n",
                 mtd->name.c_str());
        }
      } else {
        printf("cannot find symbol %s.\n", mtd->name.c_str());
      }
    }
  }
  return 0;
}