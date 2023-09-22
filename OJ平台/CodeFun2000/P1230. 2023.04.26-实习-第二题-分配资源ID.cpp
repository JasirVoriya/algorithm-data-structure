#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n = 1e3 + 5;
const int inf = 0x3f3f3f3f;
int arr[max_n][max_n];
int l, r;
list<int> ls;
map<int, list<int>::iterator> hashed;
//动态分配
void front() {
  if (hashed.empty()) return;
  list<int>::iterator it = ls.begin();
  int id = *it;
  ls.erase(it);
  hashed.erase(id);
}
//指定分配
void get(int id) {
  if (!(id >= l && id <= r)) return;
  // id不存在，说明被占用
  if (hashed.find(id) == hashed.end()) return;
  list<int>::iterator it = hashed[id];
  ls.erase(it);
  hashed.erase(id);
}
//释放id
void release(int id) {
  if (!(id >= l && id <= r)) return;
  // id存在，说明没有被占用
  if (hashed.find(id) != hashed.end()) return;
  ls.push_back(id);
  list<int>::iterator x = ls.end();
  x--;
  hashed[id] = x;
}
//插入id
void insert(int id) {
  ls.push_back(id);
  hashed[id] = ls.begin();
}

int main(void) {
  cin >> l >> r;
  for (int i = 0; l + i <= r; i++) insert(l + i);
  int t;
  cin >> t;
  while (t--) {
    int o, num;
    cin >> o >> num;
    if (o == 1) {
      while (num--) front();
    } else if (o == 2) {
      get(num);
    } else {
      release(num);
    }
  }
  cout << *ls.begin() << endl;
  
  return 0;
}