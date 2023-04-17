#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, string> P;
const int maxn = 1e3 + 5;
int main(void) {
  vector<string> list;
  string str;
  cin >> str;
  while (str != ".") {
    list.push_back(str);
    cin >> str;
  }
  if (list.size() < 2)
    cout << "Momo... No one is for you ..." << endl;
  else if (list.size() < 14)
    cout << list[1] << " is the only one for you..." << endl;
  else
    cout << list[1] << " and " << list[13] << " are inviting you to dinner..."
         << endl;

  return 0;
}