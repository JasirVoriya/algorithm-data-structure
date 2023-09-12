#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 60 * 60 * 24;
bool vis[maxn];
struct my_time {
  int h, m, s;
  int mill() const { return this->h * 60 * 60 + this->m * 60 + this->s; }
  bool operator<(const my_time& m) { return this->mill() < m.mill(); }
  bool operator==(const my_time& m) { return this->mill() == m.mill(); }
  bool operator>(const my_time& m) { return this->mill() > m.mill(); }
};
struct node {
  my_time s, e;
  bool operator<(const node& n) { return this->s < n.s; }
};
vector<node> arr;
int main(void) {
  int n;
  scanf("%d", &n);
  getchar();
  for (int i = 0; i < n; i++) {
    my_time s, e;
    scanf("%02d:%02d:%02d - %02d:%02d:%02d", &s.h, &s.m, &s.s, &e.h, &e.m,
          &e.s);
    getchar();
    node no;
    no.s = s, no.e = e;
    arr.push_back(no);
  }
  sort(arr.begin(), arr.end());
  int s = 0;
  for (int i = 0; i < arr.size() + 1; i++) {
    int e = i < arr.size() ? arr[i].s.mill() : maxn - 1;
    if (s < e) {
      int sh, sm, ss, eh, em, es;
      ss = s % 60, s /= 60;
      sm = s % 60, s /= 60;
      sh = s % 24;
      es = e % 60, e /= 60;
      em = e % 60, e /= 60;
      eh = e % 24;
      printf("%02d:%02d:%02d - %02d:%02d:%02d\n", sh, sm, ss, eh, em, es);
    }
    if (i < arr.size()) s = arr[i].e.mill();
  }
  return 0;
}