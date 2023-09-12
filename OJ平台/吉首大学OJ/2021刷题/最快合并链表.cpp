#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *pre;
};
typedef struct node node;
typedef struct node *link;
link creat(int n) //创建带头结点的双向链表环
{
    link head, tail, ins;
    head = (link)malloc(sizeof(node));
    head->data = ~(((unsigned)-1) >> 1); //最高位为1，其他为0
    head->next = head->pre = head;
    if (n <= 0)
        return head;
    tail = ins = (link)malloc(sizeof(node));
    scanf("%d", &ins->data);
    tail->pre = head;
    head->next = tail;
    head->data++; //长度+1
    while (--n)
    {
        ins = (link)malloc(sizeof(node));
        scanf("%d", &ins->data);
        ins->pre = tail;
        tail = tail->next = ins;
        head->data++; //长度+1
    }
    tail->next = head;
    head->pre = tail;
    return head;
}
int isHead(link head)
{
    return head->data & ~(((unsigned)-1) >> 1);
}
int linkSize(link head)
{
    if (!isHead(head))
        return -1;
    return head->data & (((unsigned)-1) >> 1);
}
int isEmpty(link head)
{
    if (!isHead(head))
        return -1;
    return !linkSize(head);
}
link index(link head, int step)
{
    int size = linkSize(head);
    if (isEmpty(head))
        return head;
    if (size == -1)
        return head;
    step -= step / size * size;
    if (step == 0)
        step = size;
    head = head->next;
    if (size != 0)
        while (--step)
            head = head->next;
    return head;
}
void print(link head, int step)
{
    int size = linkSize(head);
    if (size == -1)
        return;
    head = index(head, step);
    //printf("link: ");
    while (size)
    {
        if (isHead(head))
        {
            head = head->next;
            continue;
        }
        printf("%d ", head->data);
        head = head->next;
        size--;
    }
    putchar('\n');
}
link del(link head, int pos)
{
    if (isEmpty(head))
        return head;
    link DelNode = index(head, pos);
    //printf("D:%d\n", DelNode->data);
    DelNode->pre->next = DelNode->next;
    DelNode->pre->next->pre = DelNode->pre;
    head->data--;
    return head;
}
link ins(link head, int pos, int value)
{
    link InsNode = (link)malloc(sizeof(node));
    InsNode->data = value;
    link InsPos = index(head, pos);
    InsPos->pre->next = InsNode;
    InsNode->next = InsPos;
    InsNode->pre = InsPos->pre;
    InsPos->pre = InsNode;
    head->data++;
    return head;
}
int main()
{
    int m;
    scanf("m=%d", &m), getchar();
    link link1 = creat(m);
    getchar(),getchar();
    int n;
    scanf("n=%d", &n), getchar();
    link link2 = creat(n);
    getchar();
    link1->data+=linkSize(link2);
    link1->pre->next = link2->next;
    link2->next->pre = link1->pre;
    link2->pre->next = link1;
    link1->pre = link2->pre;
    print(link1, 1);
    return 0;
}