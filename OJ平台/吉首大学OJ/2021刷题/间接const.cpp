#include <iostream>
using namespace std;
int main(void)
{
    const int **pp1;
    int *p1;
    const int n = 13;
    pp1 = &p1;
    *pp1 = &n;
    *p1 = 9;
    //**pp2=10; 不能对 **pp2 赋值，const 限定符，它只限定最后一维，
    //高维不会限定，所以pp2,*pp2都能被赋值，而**pp2不能。
    //将 非const地址&p1 赋值给 const指针pp2,然后通过 *pp2 将 const地址&n 赋值给 非const指针*pp2（p1），
    //然后就能通过 非const指针p1 间接修改 const值n；
    //因此，仅当只有一层间接关系时（如指针指向基本数据类型），才可以将非const地址赋值给const指针。
    cout << n << endl;
    const int x = 13;
    int *p2;
    int **const pp2 = &p2; //此时pp3只限定最高维,*pp3,**pp3均可被赋值
    *pp2 = &x;             //不允许这样赋值，不能将 const地址（&x） 赋值给 非const指针（*pp2）
    **pp2 = 1314;
    cout << x << endl;
    *p2 = 520;
    cout << x << endl;
}