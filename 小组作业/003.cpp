#include <stdio.h>
void input(void *score, int students, int subjects),       //声明输入函数
     average(void *score, int students, int subjects),      //声明平均值函数
     outputFailed(void *score, int students, int subjects), //声明差生函数
     outputPassed(void *score, int students, int subjects); //声明优生函数
int main(void)
{
    //变量、常量
    //指针、地址
    //
    int students=5, subjects=4;
    puts("输入学生数量和课程数量："),scanf("%d%d",&students,&subjects);
    double score[students][subjects + 1];
    //-----------------------------------------------------------------------------

    puts("输入数据："), input(score, students, subjects);                       //输入
    puts("平均值："), average(score, students, subjects);                       //计算平均分数
    puts("至少两门不及格的同学："), outputFailed(score, students, subjects);    //找差生
    puts("平均分在85~90之间的同学："), outputPassed(score, students, subjects); //找优生
}
void input(void *space, int students, int subjects) //定义输入函数
{
    double(*score)[subjects+1] = (double(*)[subjects+1]) space;
    for (int i = 0; i < students; i++)
    {
        printf("请输入第%d个同学的成绩（%d门）：", i + 1, subjects);
        for (int j = 0; j < subjects; j++)
            scanf("%lf", *(score + i) + j);
    }
}
void average(void *space, int students, int subjects) //定义
{
    double(*score)[subjects+1] = (double(*)[subjects+1]) space;
    for (int i = 0; i < students; i++)
    {
        *(*(score + i) + subjects) = 0;
        for (int j = 0; j < subjects; j++)
            *(*(score + i) + subjects) += *(*(score + i) + j);
        *(*(score + i) + subjects) /= subjects;
        printf("第%d位同学的平均成绩是：%.2lf\n", i + 1, *(*(score + i) + subjects));
    }
}
void outputFailed(void *space, int students, int subjects) //定义
{
    double(*score)[subjects+1] = (double(*)[subjects+1]) space;
    for (int i = 0; i < students; i++)
    {
        int failed[subjects] = {0}, count = 0;
        for (int j = 0; j < subjects; j++)
        {
            if (*(*(score + i) + j) < 60)
                failed[count++] = j;
        }
        if (count >= 2)
        {
            printf("第%d位同学有%d门成绩不及格：", i + 1, count);
            while (count--)
                printf(" %.2lf", *(*(score + i) + *(failed + count)));
            putchar('\n');
        }
    }
}
void outputPassed(void *space, int students, int subjects) //定义
{
    double(*score)[subjects+1] = (double(*)[subjects+1]) space;
    for (int i = 0; i < students; i++)
    {
        
        if (*(*(score + i) + subjects) >= 85 && *(*(score + i) + subjects) <= 90)
            printf("第%d位同学平均分:%.2lf\n", i + 1,*(*(score + i) + subjects));
    }
}