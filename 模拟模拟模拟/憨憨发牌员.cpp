#include <bits/stdc++.h>
using namespace std;

struct Pock
{
    char num, type;
};
map<char, int> t = {{'C', 1}, {'D', 2}, {'S', 3}, {'H', 4}};
map<char, int> n = {{
                        '2',1
                    },
                    {
                        '3',2
                    },
                    {
                        '4',3
                    },
                    {
                        '5',4
                    },
                    {
                        '6',5
                    },
                    {
                        '7',6
                    },
                    {
                        '8',7
                    },
                    {
                        '9',8
                    },
                    {
                        'T',9
                    },
                    {
                        'J',10
                    },
                    {
                        'Q',11
                    },
                    {
                        'K',12
                    },
                    {
                        'A',13
                    }};
struct player
{
    Pock pocks[13];
    static bool cmp(Pock &a, Pock &b)
    {
        if (t[a.type] == t[b.type])
            return n[a.num] < n[b.num];
        return t[a.type] < t[b.type];
    }
    void input(string &str, int pos)
    {
        for (int i = 0; i < 13; i++)
        {
            pocks[i].type = str[2 * pos + 8 * i];
            pocks[i].num = str[2 * pos + 8 * i + 1];
        }
    }
    void print(string title)
    {
        cout << title << ":" << endl;
        cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
        printf("|%c %c|%c %c|%c %c|%c %c|%c %c|%c %c|%c %c|%c %c|%c %c|%c %c|%c %c|%c %c|%c %c|\n",
               pocks[0].num, pocks[0].num, pocks[1].num, pocks[1].num, pocks[2].num, pocks[2].num, pocks[3].num, pocks[3].num, pocks[4].num, pocks[4].num, pocks[5].num, pocks[5].num, pocks[6].num, pocks[6].num, pocks[7].num, pocks[7].num, pocks[8].num, pocks[8].num, pocks[9].num, pocks[9].num, pocks[10].num, pocks[10].num, pocks[11].num, pocks[11].num, pocks[12].num, pocks[12].num);
        printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |\n",
               pocks[0].type, pocks[1].type, pocks[2].type, pocks[3].type, pocks[4].type, pocks[5].type, pocks[6].type, pocks[7].type, pocks[8].type, pocks[9].type, pocks[10].type, pocks[11].type, pocks[12].type);
        printf("|%c %c|%c %c|%c %c|%c %c|%c %c|%c %c|%c %c|%c %c|%c %c|%c %c|%c %c|%c %c|%c %c|\n",
               pocks[0].num, pocks[0].num, pocks[1].num, pocks[1].num, pocks[2].num, pocks[2].num, pocks[3].num, pocks[3].num, pocks[4].num, pocks[4].num, pocks[5].num, pocks[5].num, pocks[6].num, pocks[6].num, pocks[7].num, pocks[7].num, pocks[8].num, pocks[8].num, pocks[9].num, pocks[9].num, pocks[10].num, pocks[10].num, pocks[11].num, pocks[11].num, pocks[12].num, pocks[12].num);
        cout << "+---+---+---+---+---+---+---+---+---+---+---+---+---+" << endl;
    }
    void Sort()
    {
        sort(pocks, pocks + 13, cmp);
    }
};
int main(void)
{
    player p[4];
    map<string, int> s;
    string start;
    s["E"] = 1, s["S"] = 2, s["W"] = 3, s["N"] = 0;
    cin >> start;
    string str;
    cin >> str;
    for (int i = 0, j = s[start]; i < 4; i++, j++)
    {
        p[j % 4].input(str, i);
        p[j % 4].Sort();
    }
    p[1].print("South player");
    p[2].print("West player");
    p[3].print("North player");
    p[0].print("East player");
    return 0;
}