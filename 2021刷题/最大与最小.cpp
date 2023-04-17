#include <stdio.h>
int main(void)
{

    int n;
    while (~scanf("%d", &n))
    {
        double value,min,max;
        scanf("%lf",&value),n--;
        max=min=value;
        while (n--)
        {
            scanf("%lf",&value);
            if(value<min)min=value;
            else if(value>max)max=value;
        }
        printf("%.2lf %.2lf\n",max,min);
    }
}