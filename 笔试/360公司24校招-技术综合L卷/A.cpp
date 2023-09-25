/*
小X在一片大陆上探险，有一天他发现了一个洞穴，洞穴里面有n道门，
打开每道门都需要对应的钥匙，编号为i的钥匙能用于打开第道门，而
且只有在打开了第i(i>=1)道门之后，才能打开第i+1道门，一开始只能
打开第1道门。幸运的是，小X在外面探素的途中，每天都能发现一把能
打开这n道门中其中一道门的钥匙，每天找完匙后他都会去打开所有能
打开的门。现在给出他每天找到的钥匙编号，请问每道门分别在哪一天
被打开。

第一行包含一个正整数n ，表示门的数量
接下来一行包含n个正整数a1，a2，..，an，其中ai表示第i天他找到的
钥匙的编号，能够打开第ai道门，数据保证a1-an，为1-n的一个排列。

输出一行n个数s1，s2，...，sn，其中si表示第i道门在第si天被打开。
*/
#include <bits/stdc++.h>
using namespace std;
int const max_n = 1e5 + 5;
int arr[max_n];
int main(void) {
  int cur = 1;
  unordered_set<int> uset;
  int n;
  cin >> n;
  for (int i = 1, x; i <= n; i++) {
    cin >> x;
    uset.insert(x);
    while (uset.count(cur)) {
      uset.erase(cur);
      arr[cur++] = i;
    }
  }
  for (int i = 1; i <= n; i++) cout << arr[i] << " ";
  return 0;
}