#include <iostream>
using namespace std;
const int maxn = 100000000;
int array[maxn];
int main(void)
{
    int n;
    while ((cin >> n) && n != 0)
    {
        while (cin >> array[1] && array[1] != 0)
        {
            for (int i = 2; i <= n; i++)
                cin >> array[i];
            int begin = 1, end = array[begin], sum = begin + end;
            while (begin <= end && end <= n)
            {
                while (begin <= end && begin + array[begin] == sum)
                    begin++;
                if (begin > end)
                    begin = end + 1, end = array[begin], sum = begin + end;
                else
                    break;
            }
            if (!(begin <= end && end <= n))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        cout << endl;
    }
    return 0;
}