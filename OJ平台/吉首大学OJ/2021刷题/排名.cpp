#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct stu
{
    char id[30];
    int soloved;
    int sumScore;
} stu;
int cmp(const void *a, const void *b)
{
    if (((stu *)a)->sumScore != ((stu *)b)->sumScore)
        return ((stu *)b)->sumScore - ((stu *)a)->sumScore;
    else
        return strcmp(((stu *)a)->id, ((stu *)b)->id);
}
int main(void)
{
    stu students[1010];
    int N, M, G;
    while (~scanf("%d", &N) && N > 0)
    {
        int score[10];
        scanf("%d%d", &M, &G);
        for (int i = 0; i < M; i++)
            scanf("%d", score + i);
        for (int i = 0; i < N; i++)
        {
            scanf("%s%d", students[i].id, &students[i].soloved);
            students[i].sumScore = 0;
            for (int j = 0; j < students[i].soloved; j++)
            {
                int index;
                scanf("%d", &index);
                students[i].sumScore += score[index - 1];
            }
        }
        qsort(students, N, sizeof(stu), cmp);
        int count = 0;
        while (count < N && students[count].sumScore >= G)
            count++;
        printf("%d\n", count);
        for (int i = 0; i < count; i++)
        {
            printf("%s %d\n", students[i].id, students[i].sumScore);
        }
    }
}