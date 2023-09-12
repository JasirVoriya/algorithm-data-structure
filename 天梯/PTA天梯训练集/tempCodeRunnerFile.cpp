#include <algorithm>
#include <iostream>
using namespace std;
struct Node {
    int a = 0, b = 0;
};
bool cmp(Node x, Node y) { return x.b == y.b && x.a < y.a || x.b < y.b; }
Node arr[1000 + 5];
int main(void) {
    int n;
    while (cin >> n, n > 0) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i].a;
            arr[i].b = 0;
            for (int x = arr[i].a; x; x /= 10) arr[i].b += x % 10;
        }
        sort(arr, arr + n, cmp);
        for (int i = 0; i < n; i++) cout << arr[i].a << " ";
        cout << endl;
    }
}