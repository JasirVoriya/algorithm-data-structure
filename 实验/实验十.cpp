#include<stdio.h>
typedef struct student
{
    char ID[50],name[50];
    double score1,score2,score3;
    double avg;
}student;
void input(student *stu,int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%s%s%lf%lf%lf",
        stu[i].ID,stu[i].name,&stu[i].score1,&stu[i].score2,&stu[i].score3);
    }
}
void avg(student *stu,int n)
{
    double avg1=0,avg2=0,avg3=0;
    for(int i=0;i<n;i++)
    {
        avg1+=stu[i].score1;
        avg2+=stu[i].score2;
        avg3+=stu[i].score3;
    }
    printf("%.2lf %.2lf %.2lf\n",avg1/n,avg2/n,avg3/n);
}
void max(student *stu,int n)
{
    student max=stu[0];
    for(int i=1;i<n;i++)
    {
        if(max.score1+max.score2+max.score3
            <
        stu[i].score1+stu[i].score2+stu[i].score3)
            max=stu[i];
    }
    printf("%s %s %.2lf %.2lf %.2lf\n",
    max.ID,max.name,max.score1,max.score2,max.score3);
}
int main(void)
{
    student stu[50];
    int n=10;
    printf("输入%d个学生的信息：\n",n),input(stu,n);
    puts("三门课总平均分："),avg(stu,n);
    puts("最高分数"),max(stu,n);
}