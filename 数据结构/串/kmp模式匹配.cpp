#include <bits/stdc++.h>
using namespace std;
class SubStr {
    string str;

public:
    int* next;
    char operator[](int n)
    {
        return str[n];
    }
    SubStr()
    {
        next = NULL;
    }
    int size()
    {
        return str.size();
    }
    void printNext()
    {
        cout << next[1];
        for (int i = 2; i <= str.size(); i++)
            cout << " " << next[i];
        cout << endl;
    }
    void input()
    {
        cin >> str;
        next = new int[str.size() + 1] { -1, 0 };
        int k = 0, j = 1; // str[k] 为前缀的最后一个字符
                          // str[j] 为后缀的最后一个字符
                          // 所以k+1也表示长度为j+1字符串的最长相等前后缀的长度
        while (j < str.size()) {
            if (k == -1 || str[k] == str[j])
                next[++j] = ++k;
            else
                k = next[k];
        }
    }
    ~SubStr()
    {
        if (next != NULL)
            delete[] next;
    }
};
inline int kmp(char* str1, int size, SubStr& str2)
{
    // cout << str1 << "->" << size;
    // getchar();
    int i = 0, j = 0;
    while (i <= size) {
        if (j == str2.size())
            return i - j;
        if (j == -1 || str1[i] == str2[j])
            i++, j++;
        else
            j = str2.next[j];
    }
    return -1;
}
int main(void)
{
    char str1[1000000 + 5];
    SubStr str2;
    cin >> str1;
    str2.input();
    int size = strlen(str1);
    for (int pos = kmp(str1, size, str2) + 1, ans = pos; pos != 0; ans += pos) {
        printf("%d\n", ans);
        pos = kmp(str1 + ans, size - ans, str2) + 1;
        // cout << "pos:" << pos << endl;
    }
    str2.printNext();
    return 0;
}