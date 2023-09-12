#include <bits/stdc++.h>
using namespace std;
struct node {
    string id, in_time, out_time;
    node(string id = "", string in_time = "zzz", string out_time = "")
        : id(id)
        , in_time(in_time)
        , out_time(out_time)
    {
    }
};
int main(void)
{
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        string id, in_time, out_time;
        node min_node, max_node;
        while (m--) {
            cin >> id >> in_time >> out_time;
            node temp(id, in_time, out_time);
            if (temp.in_time < min_node.in_time)
                min_node = temp;
            if (temp.out_time > max_node.out_time)
                max_node = temp;
        }
        cout << min_node.id << " " << max_node.id << endl;
    }
    return 0;
}