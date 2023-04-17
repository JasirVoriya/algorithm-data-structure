//拍气球
/*描述
小瑜3岁了，很喜欢玩皮球，看来今后喜欢打篮球的 ^ _ ^。最近她发现球从手中落下时，
每次落地后反跳回原高度的一半，再落下，每次球落地时数球跳了几次，数到n次时爸爸在
边上喊停，问小瑜现在球到底总共走了多少距离，小瑜故作沉思状，爸爸又问接下来小球能
跳多高啊，小瑜摇摇头，心想还没跳我怎么知道啊，难道爸爸是神啊！这时的你在边上出主
意想给小瑜写个程序计算一下，因此任务就交给你啦！假设球的初始高度为h，计算第n次落
地时球经过的距离，以及落地后反弹能有多高。
    格式
        输入格式
            输入数据有多组，第一行为数据的组数t，下面t行为t组数据，每行有两个数h和n,
    分别用空格分隔。
    输出格式
        输出第n次反弹时球经过的距离和球最后的高度，保留小数点后2位。*/
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int t,i,j,*count=NULL;
    float *height = NULL,*sum=NULL;
    scanf("%d", &t);
    height = (float *)malloc(sizeof(float) * t);
    sum = (float *)malloc(sizeof(float) * t);
    count = (int *)malloc(sizeof(int) * t);
    for(i=0;i<t;i++) scanf("%f%d",height+i,count+i);

    for(i=0;i<t;i++)
    {
        sum[i] = height[i];
        height[i] /= 2;
        for(j=1;j<count[i];j++)
        {
            sum[i]+=height[i]*2;
            height[i]/=2;
        }
    }
    for(i=0;i<t;i++)
        printf("%.2f %.2f\n", sum[i] ,height[i]);
    return 0;
}