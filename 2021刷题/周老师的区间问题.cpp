#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    long long left,right;
};
bool fun(const node &a,const node &b)
{
    return a.left<a.right;
}
int main(void)
{
#ifdef ONLINE_JUDGE
    ifstream fin("input.txt");
    cin.rdbuf(fin.rdbuf());
#endif


    int n;
    cin>>n;
    vector<node> arry(n);
    for(int i=0;i<n;i++)
    {
        node a;
        cin>>a.left>>a.right;
        arry.push_back(a);
    }
    sort(arry.begin(),arry.end(),fun);
    for(auto it=arry.begin();it<arry.end();it++)
        cout<<it->left<<endl;

#ifdef ONLINE_JUDGE
    fin.close();
#endif
    return 0;
}