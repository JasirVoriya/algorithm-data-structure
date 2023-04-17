#include <stdio.h>
void input(void *score, int students, int subjects),       //�������뺯��
     average(void *score, int students, int subjects),      //����ƽ��ֵ����
     outputFailed(void *score, int students, int subjects), //������������
     outputPassed(void *score, int students, int subjects); //������������
int main(void)
{
    //����������
    //ָ�롢��ַ
    //
    int students=5, subjects=4;
    puts("����ѧ�������Ϳγ�������"),scanf("%d%d",&students,&subjects);
    double score[students][subjects + 1];
    //-----------------------------------------------------------------------------

    puts("�������ݣ�"), input(score, students, subjects);                       //����
    puts("ƽ��ֵ��"), average(score, students, subjects);                       //����ƽ������
    puts("�������Ų������ͬѧ��"), outputFailed(score, students, subjects);    //�Ҳ���
    puts("ƽ������85~90֮���ͬѧ��"), outputPassed(score, students, subjects); //������
}
void input(void *space, int students, int subjects) //�������뺯��
{
    double(*score)[subjects+1] = (double(*)[subjects+1]) space;
    for (int i = 0; i < students; i++)
    {
        printf("�������%d��ͬѧ�ĳɼ���%d�ţ���", i + 1, subjects);
        for (int j = 0; j < subjects; j++)
            scanf("%lf", *(score + i) + j);
    }
}
void average(void *space, int students, int subjects) //����
{
    double(*score)[subjects+1] = (double(*)[subjects+1]) space;
    for (int i = 0; i < students; i++)
    {
        *(*(score + i) + subjects) = 0;
        for (int j = 0; j < subjects; j++)
            *(*(score + i) + subjects) += *(*(score + i) + j);
        *(*(score + i) + subjects) /= subjects;
        printf("��%dλͬѧ��ƽ���ɼ��ǣ�%.2lf\n", i + 1, *(*(score + i) + subjects));
    }
}
void outputFailed(void *space, int students, int subjects) //����
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
            printf("��%dλͬѧ��%d�ųɼ�������", i + 1, count);
            while (count--)
                printf(" %.2lf", *(*(score + i) + *(failed + count)));
            putchar('\n');
        }
    }
}
void outputPassed(void *space, int students, int subjects) //����
{
    double(*score)[subjects+1] = (double(*)[subjects+1]) space;
    for (int i = 0; i < students; i++)
    {
        
        if (*(*(score + i) + subjects) >= 85 && *(*(score + i) + subjects) <= 90)
            printf("��%dλͬѧƽ����:%.2lf\n", i + 1,*(*(score + i) + subjects));
    }
}