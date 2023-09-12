#include<stdio.h>
#include<math.h>
int gcd(int a,int b)
{
    int r=a%b;
    while(r!=0)
    {
        a=b,b=r;
        r=a%b;
    }
    return b;
}
int main()
{
    int x1,y1,x2,y2;
    while(~scanf("%d%d%d%d",&x1,&y1,&x2,&y2))
    {
        x1=abs(x1-x2);
        y1=abs(y1-y2);
        if(x1==0||y1==0)
        {
            if(x1+y1>1)printf("%d\n",x1+y1-1);
            else printf("0\n");
        }
        else 
        {
            int n=gcd(x1,y1);
            if(n>1)printf("%d\n",n-1);
            else printf("0\n");
        }
    }
}