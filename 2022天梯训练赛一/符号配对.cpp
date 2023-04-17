#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000000;
int main(void)
{
    bool new_line = true;
    char str[MAX_N];
    int ch, cnt = 0;
    while ((ch = getchar()) != EOF) {
        if (new_line) {
            if (ch == '\n' || ch == '.')
                break;
            new_line = false;
        } else {
            if (ch == '\n')
                new_line = true;
        }
        str[cnt++]=ch;
    }
    
    return 0;
}