#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e3 + 5;
struct node
{
    double num, value, price;
};
node array[maxn];
bool cmp(node &a, node &b)
{
    return a.price > b.price;
}
int main(void)
{
    int n, d;
    while (cin >> n >> d)
    {
        for (int i = 0; i < n; i++)
            cin >> array[i].num;
        for (int i = 0; i < n; i++)
        {
            cin >> array[i].value;
            array[i].price = array[i].value / array[i].num;
        }
        sort(array, array + n, cmp);
        double ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (array[i].num <= d)
            {
                ans += array[i].value;
                d -= array[i].num;
            }
            else
            {
                ans += array[i].price * d;
                d -= d;
                break;
            }
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}