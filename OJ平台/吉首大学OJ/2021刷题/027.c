/*
问题 E: 谁拿了最多奖学金(JSU-ZJJ)
描述
某校的惯例是在每学期的期末考试之后发放奖学金。发放的奖学金共有五种，获取的条件各自不同：

　　1)  院士奖学金，每人8000元，期末平均成绩高于80分（>80），并且在本学期内发表1篇或1篇以上论文的学生均可获得；    期末>80&&论文>0  8000

　　2)  五四奖学金，每人4000元，期末平均成绩高于85分（>85），并且班级评议成绩高于80分（>80）的学生均可获得；       期末>85&&班级>80  4000

　　3)  成绩优秀奖，每人2000元，期末平均成绩高于90分（>90）的学生均可获得；                                        期末>90    2000

　　4)  西部奖学金，每人1000元，期末平均成绩高于85分（>85）的西部省份学生均可获得；                                期末>85&&西部  1000

　　5)  班级贡献奖，每人850元，班级评议成绩高于80分（>80）的学生干部均可获得；                                     班级>80&&学生会   850

　　只要符合条件就可以得奖，每项奖学金的获奖人数没有限制，每名学生也可以同时获得多项奖学金。例如姚林的
    期末平均成绩是87分，班级评议成绩82分，同时他还是一位学生干部，那么他可以同时获得五四奖学金和班级贡献奖，奖金总数是4850元。

　　现在给出若干学生的相关数据，请计算哪些同学获得的奖金总数最高（假设总有同学能满足获得奖学金的条件）。

格式
输入格式
每组测试数据的输入的第一行是一个整数N（1 <= N <= 100），表示学生的总数。接下来的N行每行是一位学生的数据，
从左向右依次是姓名，期末平均成绩，班级评议成绩，是否是学生干部，是否是西部省份学生，以及发表的论文数。姓
名是由大小写英文字母组成的长度不超过20的字符串（不含空格）；期末平均成绩和班级评议成绩都是0到100之间的整
数（包括0和100）；是否是学生干部和是否是西部省份学生分别用一个字符表示，Y表示是，N表示不是；发表的论文数
是0到10的整数（包括0和10）。每两个相邻数据项之间用一个空格分隔。

输出格式
输出包括三行，第一行是获得最多奖金的学生的姓名，第二行是这名学生获得的奖金总数。如果有两位或两位以上的学
生获得的奖金最多，输出他们之中在输入文件中出现最早的学生的姓名。第三行是这N个学生获得的奖学金的总数。

样例
样例输入 Copy
4
YaoLin 87 82 Y N 0
ChenRuiyi 88 78 N Y 1
LiXin 92 88 N N 0
ZhangQin 83 87 Y N 1
样例输出 Copy
ChenRuiyi
9000
28700
*/
#include <stdio.h>
#include <stdlib.h>
struct stu
{
    char Name[21], West, StuUnion;
    int Exam, Class, Paper, Money;
};
typedef struct stu stu;
void input(stu *ptr)
{
    scanf("%s %d %d %c %c %d",
          ptr->Name, &ptr->Exam, &ptr->Class, &ptr->StuUnion, &ptr->West, &ptr->Paper);
}
int money(stu *ptr)
{
    ptr->Money = 0;
    //期末>80&&论文>0  8000
    if (ptr->Exam > 80 && ptr->Paper > 0)
        ptr->Money += 8000;
    //期末>85&&班级>80  4000
    if (ptr->Exam > 85 && ptr->Class > 80)
        ptr->Money += 4000;
    //期末>90    2000
    if (ptr->Exam > 90)
        ptr->Money += 2000;
    //期末>85&&西部  1000
    if (ptr->Exam > 85 && ptr->West == 'Y')
        ptr->Money += 1000;
    //班级>80&&学生会   850
    if (ptr->Class > 80 && ptr->StuUnion == 'Y')
        ptr->Money += 850;
    return ptr->Money;
}
int main(void)
{
    int n, max, i, sum;
    while (~scanf("%d", &n))
    {
        stu *ptr = (stu *)malloc(sizeof(stu) * n);
        input(ptr), sum = money(ptr);
        for (max = 0, i = 1; i < n; i++)
        {
            input(ptr + i);
            sum += money(ptr + i);
            if (ptr[max].Money < ptr[i].Money)
                max = i;
        }
        printf("%s\n%d\n%d\n", ptr[max].Name, ptr[max].Money, sum);
        free(ptr);
    }
    return 0;
}