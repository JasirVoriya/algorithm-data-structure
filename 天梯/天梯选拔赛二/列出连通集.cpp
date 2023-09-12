#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
struct Student
{
    string id, name;
    int socre;
};
Student stu[maxn];
bool cmp1(Student &a, Student &b)
{
    return a.id < b.id;
}
bool cmp2(Student &a, Student &b)
{
    if (a.name == b.name)
        return a.id < b.id;
    return a.name < b.name;
}
bool cmp3(Student &a, Student &b)
{
    if (a.socre == b.socre)
        return a.id < b.id;
    return a.socre < b.socre;
}
int main(void)
{
    int n, c;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> stu[i].id >> stu[i].name >> stu[i].socre;
    bool (*cmp)(Student &, Student &) = NULL;
    switch (c)
    {
    case 1:
        cmp = cmp1;
        break;
    case 2:
        cmp = cmp2;
        break;
    case 3:
        cmp = cmp3;
        break;
    }
    sort(stu, stu + n, cmp);
    for (int i = 0; i < n; i++)
        cout << stu[i].id << " " << stu[i].name << " " << stu[i].socre << endl;
    return 0;
}