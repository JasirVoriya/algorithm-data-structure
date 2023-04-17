//实验5
#include<stdio.h>
#include<math.h>
void fun1()
{
    double sum1=0,sum2=1;
    int i=1;
    while(i<=100)
    {
        if(i%2)sum1+=i;
        else sum2*=i;
        i++;
    }
    printf("%.0lf\n%.0lf\n",sum1,sum2);
}
void fun2()
{
    int i,j;
    for(i=1;i<=9;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d*%d=%d ",i,j,i*j);
        }
        putchar('\n');
    }
}
void fun3()
{
    int sum,i,n,t,m;
    for(sum=0,i=4;i<=1000;i++)
    {
        m=1;
        n=i;
        for(t=2;t*t<=n;t++)
        {
            if(n%t==0)m+=t+n/t;
        }
        if(i==m)sum+=m;
    }
    printf("%d\n",sum);
}
void fun4()
{
    int a,b,t;
    scanf("%d",&a);
    t=a,b=0;
    while(t)
    {
        b=b*10+t%10;
        t/=10;
    }
    if(a==b)puts("yes");
    else puts("no");
}
void fun5()
{
    int i,n,sum;
    scanf("%d",&n);
    for(i=1,sum=0;i<=n;i++)
    {
        sum+=(i+1)*i/2;
    }
    printf("%d\n",sum);
}
void fun6()
{
    int x,y,z;
    for(x=0;x<=14;x+=4)
    {
        y=25-x*7/4;
        z=75+x*3/4;
        printf("%d %d %d\n",x,y,z);
        printf("%d %d\n\n",x+y+z,15*x+9*y+z);
    }
}
void fun7()
{
    int i,j,x;
    for(i=1;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(i==j)continue;
            x=sqrt(i*1000+i*100+j*10+j);
            if(x*x==i*1000+i*100+j*10+j)printf("%d\n",i*1000+i*100+j*10+j);
        }
    }
}
int main(void)
{
    // printf("fun1:\n"),fun1(),putchar('\n');
    // printf("fun2:\n"),fun2(),putchar('\n');
     printf("fun3:\n"),fun3(),putchar('\n');
    // printf("fun4:\n"),fun4(),putchar('\n');
    // printf("fun5:\n"),fun5(),putchar('\n');
    // printf("fun6:\n"),fun6(),putchar('\n');
    // printf("fun7:\n"),fun7(),putchar('\n');
}