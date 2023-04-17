#include <iostream>
#include <map>
using namespace std;
struct Comb
{
    long long foods[3];
};
int main(void)
{
    map<char, Comb> combo = {{'A', {1, 1, 1}}, {'B', {2, 1, 1}}, {'C', {3, 2, 1}}};
    long long t;
    cin >> t;
    while (t--)
    {
        long long x, y, z;
        cin >> x >> y >> z;
        long long a, b, c;
        cin >> a >> b >> c;
        char k;
        cin >> k;
        long long n;
        cin >> n;
        //
        long long foods[3] = {combo[k].foods[0], combo[k].foods[1], combo[k].foods[2]};
        long long ans = 0, chicken = a / foods[0], coke = b / foods[1], chips = c / foods[2];
        a = a % foods[0], b = b % foods[1], c = c % foods[2];
        ans = min(min(chicken, coke), chips);
        a += (chicken - ans) * foods[0], b += (coke - ans) * foods[1], c += (chips - ans) * foods[2];
        while (true)
        {
            long long cost, num;
            if (a < foods[0])
            {
                num = foods[0] - a;
                cost = num * x;
                n -= cost, a += num;
            }
            if (b < foods[1])
            {
                num = foods[1] - b;
                cost = num * y;
                n -= cost, b += num;
            }
            if (c < foods[2])
            {
                num = foods[2] - c;
                cost = num * z;
                n -= cost, c += num;
            }
            if (n < 0)
                break;
            ans++;
            a -= foods[0], b -= foods[1], c -= foods[2];
            if (a == 0 && b == 0 && c == 0)
            {
                ans += n / (foods[0] * x + foods[1] * y + foods[2] * z);
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}