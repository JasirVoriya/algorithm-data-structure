#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    int data;
    struct node *next;
};
typedef struct node node;
typedef struct node *link;
link creat(int n)
{
    if (n == 0)
        return NULL;
    link head = (link)malloc(sizeof(struct node));
    head->num = n;
    scanf("%d", &head->data);
    head->next = creat(n - 1);
    return head;
}
void print(link head) //�������
{
    if (head == NULL)
        return;
    print(head->next);
    printf("%d ", head->data);
}
link sort_link(link head)
{
    if (head == NULL)
        return NULL;
    link start = (link)malloc(sizeof(node));
    start->next = head;
    link max = start, sp = head;
    while (sp->next)
    {
        if (max->next->data < sp->next->data)
            max = sp;
        sp = sp->next;
    }
    sp = max->next;
    max->next = max->next->next;
    sp->next = sort_link(start->next);
    return sp;
}
int main(void)
{
    int m;
    scanf("%d",&m);
    link head = creat(m);
    head = sort_link(head);
    print(head);
}