#include <bits/stdc++.h>
using namespace std;
struct Mem
{
    int first = 0, second = 0, third = 0, s = 0;
    string name;
    int score[15];
    void input()
    {
        cin >> name;
        for (int i = 0; i < 15; i++)
            cin >> score[i];
        first = score[0] + score[1] + score[2] + score[3] + score[4] + score[5] + score[6] + score[7];
        second = score[8] + score[9] + score[10] + score[11];
        third = score[12] + score[13] + score[14];
        s = first + second + third;
    }
};
int top = 0;
struct Team
{
    string name;
    Mem mem[10];
    int first = 0, second = 0, third = 0;
    int afirst, asecond, athird, ascore;
    void input()
    {
        cin >> name;
        for (int i = 0; i < 10; i++)
        {
            mem[i].input();
            top = max(mem[i].s, top);
            first += mem[i].first;
            second += mem[i].second;
            third += mem[i].third;
        }
        afirst = first, asecond = second, athird = third;
        if (afirst < 800)
            asecond = 0;
        if (asecond < 400)
            athird = 0;
        ascore = afirst + asecond + athird;
    }
    void loadTop(vector<string> &que)
    {
        for (int i = 0; i < 10; i++)
            if (mem[i].s == top)
                que.push_back(mem[i].name);
    }
    void pirnt()
    {
        cout << name << " " << first << " " << second << " " << third << " " << ascore;
    }
} team[110];
bool cmp(Team &a, Team &b)
{
    if (a.ascore == b.ascore)
        return a.name < b.name;
    return a.ascore > b.ascore;
}
int main(void)
{
    vector<string> que;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        team[i].input();
    for (int i = 0; i < n; i++)
        team[i].loadTop(que);
    sort(team, team + n, cmp);
    sort(que.begin(), que.end());
    int rank = 1;
    team[0].pirnt(), cout << " " << rank << endl;
    for (int i = 1; i < n; i++)
    {
        if (team[i].ascore != team[i - 1].ascore)
            rank = i + 1;
        team[i].pirnt(), cout << " " << rank << endl;
    }
    cout << top;
    for (auto it = que.begin(); it != que.end(); it++)
        cout << " " << *it;
    return 0;
}