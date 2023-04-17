#include <stdio.h>
#define STUDENTS 5  //学生数量
#define SUBJECTS 4 //课程数量

int main(void)
{
    double score[STUDENTS][SUBJECTS+1]; //定义一个分数数组，+1是为了多定义一个变量，用来存平均分
    //将 STUDENTS 替换成 5
    //将 SUBJECTS 替换成 4
    //变量、常量
    //指针、地址
    //
    void input(double (*score)[SUBJECTS+1]),       //声明输入函数
    //double score[][SUBJECTS+1] double (*score)[SUBJECTS+1] score[STUDENTS+1][SUBJECTS+1]
        average(double score[][SUBJECTS+1]),      //声明平均值函数
        outputFailed(double score[][SUBJECTS+1]), //声明差生函数
        outputPassed(double score[][SUBJECTS+1]); //声明优生函数

    //-----------------------------------------------------------------------------

    puts("输入数据："), input(score);                       //输入
    puts("平均值："), average(score);                       //计算平均分数
    puts("至少两门不及格的同学："), outputFailed(score);    //找差生
    puts("平均分在85~90之间的同学："), outputPassed(score); //找优生
}
void input(double score[][SUBJECTS+1]) //定义输入函数
{
    for (int i = 0; i < STUDENTS; i++)
    {
        printf("请输入第%d个同学的成绩（%d门）：", i + 1, SUBJECTS);
        for (int j = 0; j < SUBJECTS; j++)
            scanf("%lf", *(score + i) + j);
    }
}
void average(double score[][SUBJECTS+1]) //定义
{
    for (int i = 0; i < SUBJECTS; i++)
    {
        *(*(score + STUDENTS) + i) = 0;
        for (int j = 0; j < STUDENTS; j++)
            *(*(score + STUDENTS) + i) += *(*(score + j) + i);
        *(*(score + STUDENTS) + i) /= STUDENTS;
        printf("第%d门科目的平均成绩是：%.2lf\n", i + 1, *(*(score + STUDENTS) + i));
    }
    for (int i = 0; i < STUDENTS; i++)
    {
        *(*(score + i) + SUBJECTS) = 0;
        for (int j = 0; j < SUBJECTS; j++)
            *(*(score + i) + SUBJECTS) += *(*(score + i) + j);
        *(*(score + i) + SUBJECTS) /= SUBJECTS;
    }
}
void outputFailed(double score[][SUBJECTS+1]) //定义
{
    for (int i = 0; i < STUDENTS; i++)
    {
        int failed[SUBJECTS] = {0}, count = 0;
        for (int j = 0; j < SUBJECTS; j++)
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
void outputPassed(double score[][SUBJECTS+1]) //定义
{
    for (int i = 0; i < STUDENTS; i++)
    {
        if (*(*(score + i) + SUBJECTS) >= 85 && *(*(score + i) + SUBJECTS) <= 90)
            printf("第%d位同学平均分:%.2lf\n", i + 1, *(*(score + i) + SUBJECTS));
    }
}