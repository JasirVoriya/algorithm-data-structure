//将最大值放到矩阵中心，4个次大值分别放到矩形的四个角
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
void print(void *a, int row, int col)
{
    int(*array)[col] = (int(*)[col])a;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%-3d", array[i][j]);
        putchar('\n');
    }
}
int cmp(const void *a, const void *b)
{
    return **(int **)b - **(int **)a;
}
void swap(int* a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void fun(void *a, int row, int col)
{
    int *array = (int *)a;
    int *begin = array, *end = array + row * col;
    //
    int *leftTop = array, *rightTop = array + col - 1, *center = array + (row * col) / 2,
        *leftBotton = array + (row - 1) * col, *rightBotton = array + row * col - 1;
    int **ptr = (int **)malloc(sizeof(int *) * row * col);
    ptr[0] = array;
    for (int i = 1; i < row * col; i++)
        ptr[i] = ptr[i - 1] + 1;
    int **pbegin = ptr, **pend = ptr + row * col;
    qsort(ptr, row * col, sizeof(int *), cmp);
    //
    swap(ptr[0],center);
        if(ptr[1]==center)ptr[1]=ptr[0];
    swap(ptr[1],leftTop);
        if(ptr[2]==leftTop)ptr[2]=ptr[1];
    swap(ptr[2],rightTop);
        if(ptr[3]==rightTop)ptr[3]=ptr[2];
    swap(ptr[3],leftBotton);
        if(ptr[4]==leftBotton)ptr[4]=ptr[3];
    swap(ptr[4],rightBotton);
    //
    free(ptr);
    return;
}
int main(void)
{
    int a[SIZE][SIZE];
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    puts("调换前：");
    print(a, SIZE, SIZE);
    //
    fun(a, SIZE, SIZE);
    //
    puts("调换后：");
    print(a, SIZE, SIZE);
    return 0;
}