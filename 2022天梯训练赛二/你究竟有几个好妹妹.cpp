#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5;
typedef long long ll;
typedef unsigned long long ull;
struct node {
    string name;
    char sex;
    int age;
    string date;
};
node arr[MAX_N];
void up(string& str)
{
    for (char& ch : str) {
        if (ch >= 'a' && ch <= 'z') {
            ch -= 'a' - 'A';
        }
    }
}
bool cmp(node& a, node& b)
{
    string aname = a.name, bname = b.name;
    up(aname), up(bname);
    if (aname != bname) {
        return aname < bname;
    }
    if (a.age != b.age) {
        return a.age < b.age;
    }
    return a.date < b.date;
}
int main(void)
{
    string preix;
    cin >> preix;
    up(preix);
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        node x;
        string name;
        cin >> x.name >> x.sex >> x.age >> x.date;
        if (x.sex != 'F')
            continue;
        name = x.name;
        up(name);
        int index = name.find(preix);
        if (index != string::npos) {
            x.name.replace(index, preix.size(), "");
            arr[cnt++] = x;
        }
    }
    sort(arr, arr + cnt, cmp);
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        cout << arr[i].name << " " << arr[i].age << " " << arr[i].date << endl;
    }
    return 0;
}