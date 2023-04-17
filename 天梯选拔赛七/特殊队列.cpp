#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int m, n;
    cin >> m >> n;
    vector<int> arr;
    char command[50];
    for (int i = 0, val; i < m; i++)
    {
        scanf("%s", command);
        if (strcmp(command, "EnQueue") == 0)
        {
            cin >> val;
            arr.push_back(val);
        }
        else if (strcmp(command, "DeQueue") == 0)
        {
            arr.erase(arr.begin());
        }
        else if (strcmp(command, "DeleteMid") == 0)
        {
            
        }
    }
    return 0;
}