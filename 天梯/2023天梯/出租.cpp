#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int book[256] = {0};
  string str;
  cin >> str;
  for (auto ch : str) book[ch]++;
  vector<char> arr;
  for (int i = '9'; i >= '0'; i--) {
    if (book[i]) arr.push_back(i);
  }
  vector<int> index;
  for (auto ch : str) {
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] == ch) {
        index.push_back(i);
        break;
      }
    }
  }
  cout << "int[] arr = new int[]{";
  cout << arr[0];
  for (int i = 1; i < arr.size(); i++) cout << "," << arr[i];
  cout << "};" << endl;
  cout << "int[] index = new int[]{";
  cout << index[0];
  for (int i = 1; i < index.size(); i++) cout << "," << index[i];
  cout << "};" << endl;

  return 0;
}