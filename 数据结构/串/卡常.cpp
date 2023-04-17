#include <map>
#include <cstdio>
#include <string>
using namespace std;
int main(void)
{
    char str[300];
    map<string, string> dict;
    while (gets(str))
    {
        if (str[0] == 0)
            break;
        int i = 0;
        while (str[i] != ' ')
            i++;
        str[i] = '\0';
        dict[str + i + 1] = str;
    }
    while (~scanf("%s", str))
    {
        if (dict.count(str))
            puts(dict[str].c_str());
        else
            puts("eh");
    }
    return 0;
}