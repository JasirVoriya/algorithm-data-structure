#include <stdio.h>
#define STUDENTS 5  //ѧ������
#define SUBJECTS 4 //�γ�����

int main(void)
{
    double score[STUDENTS][SUBJECTS+1]; //����һ���������飬+1��Ϊ�˶ඨ��һ��������������ƽ����
    //�� STUDENTS �滻�� 5
    //�� SUBJECTS �滻�� 4
    //����������
    //ָ�롢��ַ
    //
    void input(double (*score)[SUBJECTS+1]),       //�������뺯��
    //double score[][SUBJECTS+1] double (*score)[SUBJECTS+1] score[STUDENTS+1][SUBJECTS+1]
        average(double score[][SUBJECTS+1]),      //����ƽ��ֵ����
        outputFailed(double score[][SUBJECTS+1]), //������������
        outputPassed(double score[][SUBJECTS+1]); //������������

    //-----------------------------------------------------------------------------

    puts("�������ݣ�"), input(score);                       //����
    puts("ƽ��ֵ��"), average(score);                       //����ƽ������
    puts("�������Ų������ͬѧ��"), outputFailed(score);    //�Ҳ���
    puts("ƽ������85~90֮���ͬѧ��"), outputPassed(score); //������
}
void input(double score[][SUBJECTS+1]) //�������뺯��
{
    for (int i = 0; i < STUDENTS; i++)
    {
        printf("�������%d��ͬѧ�ĳɼ���%d�ţ���", i + 1, SUBJECTS);
        for (int j = 0; j < SUBJECTS; j++)
            scanf("%lf", *(score + i) + j);
    }
}
void average(double score[][SUBJECTS+1]) //����
{
    for (int i = 0; i < SUBJECTS; i++)
    {
        *(*(score + STUDENTS) + i) = 0;
        for (int j = 0; j < STUDENTS; j++)
            *(*(score + STUDENTS) + i) += *(*(score + j) + i);
        *(*(score + STUDENTS) + i) /= STUDENTS;
        printf("��%d�ſ�Ŀ��ƽ���ɼ��ǣ�%.2lf\n", i + 1, *(*(score + STUDENTS) + i));
    }
    for (int i = 0; i < STUDENTS; i++)
    {
        *(*(score + i) + SUBJECTS) = 0;
        for (int j = 0; j < SUBJECTS; j++)
            *(*(score + i) + SUBJECTS) += *(*(score + i) + j);
        *(*(score + i) + SUBJECTS) /= SUBJECTS;
    }
}
void outputFailed(double score[][SUBJECTS+1]) //����
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
            printf("��%dλͬѧ��%d�ųɼ�������", i + 1, count);
            while (count--)
                printf(" %.2lf", *(*(score + i) + *(failed + count)));
            putchar('\n');
        }
    }
}
void outputPassed(double score[][SUBJECTS+1]) //����
{
    for (int i = 0; i < STUDENTS; i++)
    {
        if (*(*(score + i) + SUBJECTS) >= 85 && *(*(score + i) + SUBJECTS) <= 90)
            printf("��%dλͬѧƽ����:%.2lf\n", i + 1, *(*(score + i) + SUBJECTS));
    }
}