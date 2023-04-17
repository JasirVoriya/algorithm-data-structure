#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string type;
        cin >> n >> type;
        string means;
        int data;
        if (type == "FIFO")
        {
            queue<int> que;
            for (int i = 0; i < n; i++)
            {
                cin >> means;
                if (means == "IN")
                {
                    cin >> data;
                    que.push(data);
                }
                else if (means == "OUT")
                {
                    if (que.size())
                    {
                        cout << que.front() << endl;
                        que.pop();
                    }
                    else
                        cout << "None" << endl;
                }
            }
        }
        else if (type == "FILO")
        {
            stack<int> que;
            for (int i = 0; i < n; i++)
            {
                cin >> means;
                if (means == "IN")
                {
                    cin >> data;
                    que.push(data);
                }
                else if (means == "OUT")
                {
                    if (que.size())
                    {
                        cout << que.top() << endl;
                        que.pop();
                    }
                    else
                        cout << "None" << endl;
                }
            }
        }
    }
    return 0;
}