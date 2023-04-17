#include <bits/stdc++.h>
using namespace std;
class book {
 public:
  int id, h, m;
  book() : id(0), h(0), m(0) {}  //添加默认构造函数
  book(int id, int h, int m) : id(id), h(h), m(m) {}
};
int main(void) {
  int day;
  cin >> day;
  map<int, book> log;
  int rt = 0, cnt = 0;
  while (day) {
    char op;
    book bk;
    scanf("%d %c %02d:%02d", &bk.id, &op, &bk.h, &bk.m);
    getchar();
    double avg = cnt == 0 ? 0 : 1.0 * rt / cnt;
    if (bk.id == 0) {
      printf("%d %.0lf\n", cnt, avg);
      day--;
      cnt = rt = 0;
      log.clear();
      continue;
    };
    if (op == 'S') {
      // if (log.count(bk.id) != 0) {
        // continue;
      // }
      log[bk.id] = bk;
    } else if (op == 'E') {
      if (log.count(bk.id) == 0) {
        continue;
      }
      book k = log[bk.id];
      log.erase(bk.id);
      rt += (bk.h * 60 + bk.m) - (k.h * 60 + k.m);
      cnt++;
    }
  }
  return 0;
}