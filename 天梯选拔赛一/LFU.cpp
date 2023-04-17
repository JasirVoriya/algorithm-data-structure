#include <bits/stdc++.h>
using namespace std;
const int INF = (unsigned)(-1) >> 1;
class node
{
public:
    string value;
    int count = 0;
    int time = INF;
    bool operator<(node &a)
    {
        if (this->count == a.count)
            return this->time > a.time;
        return this->count > a.count;
    }
};
int main(void)
{
    map<string, node> m;
    string op, key, value;
    int n;
    cin >> n;
    int i = 0;
    while (cin >> op)
    {
        if (op == "get")
        {
            cin >> key;
            auto it = m.find(key);
            if (it == m.end())
                cout << "Not Found" << endl;
            else
            {
                it->second.count++;
                it->second.time = i;
                cout << it->second.value << endl;
            }
        }
        else
        {
            if(m.size()==n)
            cin >> key >> value;
            m[key].value = value;
            m[key].count++;
            m[key].time = i;
        }
        i++;
    }
    return 0;
}