#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int t;
    cin >> t;
    getchar();
    map<char, char> ans{{'R', 'P'}, {'P', 'S'}, {'S', 'R'}};
    while (t--)
    {
        map<char, int> book;
        char ch;
        int size = 0;
        while ((ch = getchar()) != '\n' && ch != EOF)
            book[ch]++, size++;
        ch = 'R';
        if (book[ch] < book['P'])
            ch = 'P';
        if (book[ch] < book['S'])
            ch = 'S';
        ch = ans[ch];
        for (int i = 0; i < size; i++)
            cout << ch;
        cout << endl;
    }
    return 0;
}