#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    deque<int> de;
    de.push_front(3);
    de.push_front(1);
    de.push_front(2);
    for (int x : de) {
        cout << x << endl;
    }
    return 0;
}