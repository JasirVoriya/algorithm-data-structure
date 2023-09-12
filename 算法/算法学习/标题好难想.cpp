/*
问题 A: 标题好难想
描述
DpprZ又双叒叕开始跑步减肥了，跑道分为了n块，每一块涂一个颜色，共3个颜色供选择。但是DpprZ很懒，当有连续三块不同颜色，DpprZ就会觉得眼花，不想跑步了，只有任意连续三块不是都不同的颜色，DpprZ才会继续跑。现在请你算出n块跑道有多少种涂色方案（顺序不同也是不同种），能让他继续跑步

格式
输入格式
第一行输入一个T(1<=T<=1000)
第2至T+1行每行一个n(1<=n<=40)



输出格式
对应每个n输出一个答案（种类数）

样例
样例输入 Copy
2
1
2
样例输出 Copy
3
*/
#include <stdio.h>
const int size = 40;
typedef unsigned long long ull;
ull ans[size + 1] = {0, 3, 9};
void init(void) {
  for (int i = 3; i <= size; i++) ans[i] = 2 * ans[i - 1] + ans[i - 2];
  //               a(n-2)、a(n-1)、a(n)
  //对于a(n-1)来说：
  //  ① 如果 第n-1个 与 第n-2个 相同，则相同的数量 -> a(n-2)
  //  ② 所以 不同的 -> 总量 - 相同的：a(n-1)-a(n-2)
  //  所以 a(n-1)= ① + ② = a(n-1)
  //
  //对于a(n)来说：
  //  ① 如果 第n-1个 和 第n-2个 相同 ，则 第n个 可以放 3种颜色 -> 3a(n-2)
  //  ② 如果 第n-1个 和 第n-2个 不同， 则 第n个 可以放 2种颜色 ->
  //  2(a(n-1)-a(n-2)) 所以 a(n)= ① + ② = 2a(n-1)+a(n-2)
}
int main(void) {
  init();
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    printf("%llu\n", ans[n]);
  }
  return 0;
}