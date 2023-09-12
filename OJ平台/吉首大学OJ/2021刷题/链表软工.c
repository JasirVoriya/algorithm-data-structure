#include <stdio.h>
#include <stdlib.h>
struct node
{
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
    scanf("%d", &head->data);
    head->next = creat(n - 1);
    return head;
}
void print(link head)
{
    if (head == NULL)
    {
        putchar('\n');
        return;
    }
    printf("%d ", head->data);
    print(head->next);
}
link bubble_sort_link(link head)
{
    link start = (link)malloc(sizeof(struct node)), end = NULL;
    link p1, p2, p3;
    start->next = head;
    while (start->next->next != end)
    {
        p1 = start, p2 = p1->next, p3 = p2->next;
        while (p3 != end)
        {
            if (p2->data > p3->data)
            {
                p2->next = p3->next;
                p1->next = p3;
                p3->next = p2;
                p2 = p3;
                p3 = p3->next;
            }
            p1 = p1->next, p2 = p2->next, p3 = p3->next;
        }
        end = p2;
    }
    return start->next;
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
link del(link head, int n)
{
    if (head == NULL)
        return NULL;
    if (head->data == n)
        return del(head->next, n);
    head->next = del(head->next, n);
    return head;
}
int main(void)
{
    int m, n;
    while (~scanf("%d%d", &m, &n))
    {
        link link1 = creat(m), link2 = creat(n);
        link it1 = link1, it2 = link2;
        while (it1 != NULL)
        {
            it2 = link2;
            while (it2 != NULL)
            {
                if (it1->data == it2->data)
                {
                    int delva = it1->data;
                    it1 = link1 = del(link1, delva);
                    link2 = del(link2, delva);
                    goto end;
                }
                it2 = it2->next;
            }
            it1 = it1->next;
        end:;
        }
        link1 = bubble_sort_link(link1);
        link2 = sort_link(link2);
        print(link1);
        print(link2);
    }
}