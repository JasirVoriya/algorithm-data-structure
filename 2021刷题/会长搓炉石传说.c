#include <stdio.h>
int n, a, k;
int fun(int arry[], int kill)//*(arry+2)  arry[2]
{
    if (arry[kill] - a == 0) return 1;
    int i=0,skip = 0, num = 1;
    for (i = 0; i < n; i++)
    {
        if (!skip && i == kill){
            skip = 1;
            continue;
        }
        if (arry[i] - k > 0) break;
        if (arry[i] - k == 0){
            num++;
            break;
        }
        num++;
    }
    return num;
}
int main(void)
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &a, &k);
        int i = 0, hp[1100], killed=-1,num=0;
        while (i < n) scanf("%d", hp + i++);
        for(i=0;i<n;i++)
        {
            if(hp[i]-a<=0){//能杀绝不手软，先杀
                int num1=fun(hp,i);//计算杀掉之后能灭多少随从
                if(num1>num)num=num1;//保留最大值
            }
        }
        printf("%d\n",num);
    }
}