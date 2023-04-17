/*
问题 E: 求二维数组中的鞍点【数组】
描述
如果矩阵A中存在这样的一个元素A[i,j]满足条件:A[i,j]是第i行中值最小的元素,且又是第j列中值最小的元素，则称之为该矩阵的一个马鞍点。请编程计算出m*n的矩阵A的所有马鞍点。

格式
输入格式
输入m,n

然后输入数组中的每个元素，输入的元素为正整数，小于1000

输出格式
输出m*n的矩阵A的所有马鞍点，输出的马鞍点按从小到大排序输出

样例
样例输入 Copy
3 3
1 7 3
5 4 6
7 8 9
样例输出 Copy
1 4	
*/
#include<stdio.h>
#include<stdlib.h>
int fun(int* a,int n,int i,int j)
{
    return a[i*n+j];
}
int minR(int *a,int n,int i)
{
    int t,min;
    for(min=0,t=1;t<n;t++)if(fun(a,n,i,min)>fun(a,n,i,t))min=t;
    return min;
}
int minC(int *a,int n,int i)
{
    int t,min;
    for(min=0,t=1;t<n;t++)if(fun(a,n,min,i)>fun(a,n,t,i))min=t;
    return min;
}
void insert(int* a,int n,int num)
{
    if(n==0){
        a[0]=num;
        return;
    }
    int i;
    for(i=n-1;i>=0&&a[i]>num;i++)a[i+1]=a[i];
    a[i+1]=num;
}
int main(void)
{
    int *a,*b,m,n,i,j,k,R,C;
    scanf("%d%d",&m,&n);
    if(m<=0||n<=0)return 0;
    a=(int*)malloc(sizeof(int)*m*n);
    for(i=0;i<m*n;i++)scanf("%d",a+i);
    b=(int*)malloc(sizeof(int)*m);
    for(k=i=0;i<m;i++)
    {
        R=minR(a,n,i);//第i行里面最小值的下标
        C=minC(a,n,R);//第R列里面最小值的下标
        if(C==i)
        {
            insert(b, k, fun(a, n, R, C)); //找到存下来
            k++;
        }
    }
    for(i=0;i<k;i++)printf("%d ",b[i]);
    free(b);
    free(a);
}