
// int main(void) {
//     ll a, b;
//     scanf("%lld%lld", &a, &b);
//     ll ans = 1;
//     while (b--) {
//         ans = ans * a;
//     }
//     printf("%lld\n", ans);
//     return 0;
// }
// 快速幂

// 十进制数：3
// 二进制数：11
// 位权：
// 十进制：120：0*10^0 + 2*10^1 + 1*10^3 = 120
// 二进制：2^0*0 + 2^1*0 + 2^2*0 + 2^3*1 +2^4*1 + 2^5*1 + 2^6* 1
// 1111000 = 8+16+32+64
// a ^ 120 % p = a^8 * a^16 * a^32 * a^64
// a%p= n*p + b
// base=a
// 每一次循环：base= base * base
// 十进制数：12345 -> 1234:12345/10=1234
// 10000000000^10000000000
#include <stdio.h>
typedef unsigned long long ll;
int main(void) {
    ll a, b, p;
    scanf("%llu%llu%llu", &a, &b, &p);
    ll base = a % p;
    ll ans = 1;
    while (b) {
        // 当前二进制位为一
        if (b % 2 == 1) ans = (ans * base) % p;
        base = (base * base) % p;
        // 右移一位，舍弃低位
        b = b / 2;
    }
    printf("%llu\n", ans % p);
    return 0;
}