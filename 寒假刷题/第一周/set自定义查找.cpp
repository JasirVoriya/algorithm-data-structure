#include<bits/stdc++.h>
using namespace std;
struct ans
{
    int i;
    double v;
    double ansr;
    bool operator<(const ans& a)const
    {
        if(this->i==a.i&&this->v==a.v)return false;
        else return true;
    }
};
set<ans> mem;
int main(void)
{
    ans a={1,2,3};
    ans t={2,2,3};
    mem.insert(t);
    cout<<mem.count(a);
    return 0;
}