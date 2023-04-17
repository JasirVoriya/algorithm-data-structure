#include <bits/stdc++.h>
using namespace std;
map<char, bool> mb = {{'Y', true}, {'N', false}};
struct Team
{
    string name;
    struct Prob
    {
        bool pass = false;
        int h = 0, m = 0, count = 1;
        int time = 0;
        void load(char ch, int begin)
        {
            pass = mb[ch];
            if (pass)
                time = (h * 60 + m + (count - 1) * 20) - begin;
        }
    } prob[15];
    int ac = 0;
    int time = 0;
    int h = 0, m = 0;
    void load(int x)
    {
        for (int i = 0; i < x; i++)
        {
            ac += prob[i].pass;
            time += prob[i].time;
        }
        h = time / 60;
        m = time % 60;
    }

};
bool cmp(Team &a, Team &b)
{
    if (a.ac == b.ac)
        if (a.time == b.time)
            return false;
        else
            return a.time > b.time;
    return a.ac < b.ac;
}
int main(void)
{
    int n, x;
    int begin, bh, bm;
    while (cin >> n >> x)
    {
        Team team[1005];
        getchar();
        scanf("%d:%d", &bh, &bm), getchar();
        begin = bh * 60 + bm;
        for (int i = 0; i < n; i++)
        {
            cin >> team[i].name;
            char pass;
            for (int j = 0; j < x; j++)
            {
                scanf(" %c", &pass);
                if (mb[pass])
                {
                    scanf("(%d:%d %d)",
                          &team[i].prob[j].h, &team[i].prob[j].m, &team[i].prob[j].count);
                }
                else
                    scanf("(%d)", &team[i].prob[j].count);
                team[i].prob[j].load(pass, begin);
            }
            getchar();
            team[i].load(x);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j + 1 < n - i; j++)
            {
                if (cmp(team[j], team[j + 1]))
                    swap(team[j], team[j + 1]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << team[i].name << " " << team[i].ac << " ";
            printf("%02d:%02d\n", team[i].h, team[i].m);
        }
    }
    return 0;
}