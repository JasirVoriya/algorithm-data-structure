#include<stdio.h>
#include<stdlib.h>
struct data{
    char Name[20],Addr[100];
    int Age;
    struct data* next;
};
typedef struct data data;
void fun1()
{
    puts("===============================");
    puts("1.��������            2.�޸�����");
    puts("3.��ѯ����            4.��ӡ����");
    puts("===============================");
    scanf("%*d"),getchar();
    puts("�Բ�����ֻ�����hello world����");
    return;
}
int input(data* ptr)
{

    printf("Name:"),scanf("%s",ptr->Name),getchar();
    if(ptr->Name[0]=='#')return 0;
    printf("Age:"),scanf("%d",&ptr->Age),getchar();
    printf("Address:"),scanf("%s",ptr->Addr),getchar();
    return 1;
}
void fun2()
{
    data *head=NULL,*ptr=NULL,*tail=NULL;
    head=ptr=tail=(data*)malloc(sizeof(data)),head->next=NULL;
    while (input(ptr))
    {
        tail=tail->next=ptr;
        ptr=(data*)malloc(sizeof(data)),ptr->next=NULL;
    }
    if(head!=ptr)tail->next=ptr;
    puts("--------------------------------------------------------------------");
    printf("%-10s%-5s%-15s\n","Name","Age","Address");
    while(head->next)
    {

        printf("%-10s%-5d%-15s\n",
                head->Name,head->Age,head->Addr);
        head=head->next;
    }
    puts("--------------------------------------------------------------------");
    return;
}
int main(void)
{
    fun1();
    fun2();
    return 0;
}