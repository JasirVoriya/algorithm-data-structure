#include <iostream>
#include <stack>
using namespace std;
const int maxn = 10;
int B[maxn], A[maxn];
int main(void)
{
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
            scanf("%1d", A + i);
        for (int i = 1; i <= n; i++)
            scanf("%1d", B + i);
        stack<int> sta;
        int i, index, count = 0;
        string command[20];
        for (i = index = 1; i <= n; i++)
        {
            sta.push(A[i]), command[count++] = "in";
            while (sta.size() && sta.top() == B[index])
            {
                sta.pop();
                index++;
                command[count++] = "out";
            }
        }
        if (sta.size())
            cout << "No." << endl;
        else
        {
            cout << "Yes." << endl;
            for (int i = 0; i < count; i++)
                cout << command[i] << endl;
        }
        cout << "FINISH" << endl;
    }
    return 0;
}