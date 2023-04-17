#include <stdio.h>
#include<stdlib.h>
typedef struct stu
{
    char id[20], name[20];
    double score[3];
    double avg;
} stu;
int cmp(const void* a,const void* b)
{
    return ((stu*)b)->avg-((stu*)a)->avg;
}
int main(void)
{
    freopen("stud", "r", stdin);
    freopen("stu_sort", "w", stdout);
    stu students[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%s%s%lf%lf%lf%lf",
              students[i].id, students[i].name, &students[i].score[0], &students[i].score[1], &students[i].score[2],&students[i].avg);
    }
    qsort(students,5,sizeof(stu),cmp);
    for (int i = 0; i < 5; i++)
    {
        printf("%s %s %lg %lg %lg %lg\n",
              students[i].id, students[i].name, students[i].score[0], students[i].score[1], students[i].score[2],students[i].avg);
    }
    return 0;
}