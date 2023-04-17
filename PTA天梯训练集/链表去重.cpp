#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    map<string, pair<int, string>> List;
    string begin, tail, end;
    map<string, pair<int, string>> DList;
    string Dbegin, Dtail, Dend;
    int Dsize = 0;
    int n;
    cin >> begin >> n;
    for (int i = 0; i < n; i++)
    {
        string addr;
        cin >> addr;
        cin >> List[addr].first >> List[addr].second;
    }
    tail = begin, end = List[tail].second;
    for (string it = List[begin].second; it != "-1"; it = List[it].second)
    {
        string j;
        for (j = begin; j != end; j = List[j].second)
        {
            if (abs(List[j].first) == abs(List[it].first))
            {
                //删除
                if (Dsize == 0)
                {
                    Dbegin = Dtail = it;
                    DList[Dbegin] = List[it];
                    DList[Dbegin].second = "-1";
                    // Dend = "-1";
                }
                else
                {
                    Dtail = DList[Dtail].second = it;
                    DList[Dtail] = List[it];
                    DList[Dtail].second = "-1";
                }
                Dsize++;
                break;
            }
        }
        if (j == end)
        {
            tail = List[tail].second = it;
            end = List[tail].second;
        }
    }
    List[tail].second = "-1";
    for (string it = begin; it != "-1"; it = List[it].second)
        cout << it << " " << List[it].first << " " << List[it].second << endl;
    for (string it = Dbegin; it != "-1"; it = DList[it].second)
        cout << it << " " << DList[it].first << " " << DList[it].second << endl;

    return 0;
}