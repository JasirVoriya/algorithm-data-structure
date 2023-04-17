#include <iostream>
#include <stack>
using namespace std;
const int maxn = 100000000;
int B[maxn];
int main(void)
{
    int n;
    while ((cin >> n) && n != 0)
    {
        while (cin >> B[1] && B[1] != 0)
        {
            for (int i = 2; i <= n; i++)
                cin >> B[i];
            stack<int> sta;
            int i, index;
            for (i = index = 1; i <= n; i++)
            {
                sta.push(i);
                while (sta.size() && sta.top() == B[index])
                    sta.pop(), index++;
            }
            if (sta.size())
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
        cout << endl;
    }
    return 0;
}