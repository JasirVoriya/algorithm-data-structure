#include <stdio.h>
#include <stdlib.h>

struct list
{
    int num;
    struct list *next;
};

int main()
{
    int N, n, data;
    struct list *temp, *p, *head = NULL, *t, *HEAD;
    scanf("%d", &N);
    for (n = 1; n <= N; n++)
    {
        p = (struct list *)malloc(sizeof(struct list));
        scanf("%d", &p->num);
        if (n == 1)
        {
            head = p;
        }
        else
        {
            temp->next = p;
        }
        temp = p;
        p->next = NULL;
    }
    t = head;
    data = t->num;
    HEAD = t->next;
    while (t != NULL)
    {
        if (t->next == NULL)
        {
            t->next = head;
            head->next = NULL;
            break;
        }
        if (t->next->num >= data)
        {
            head->next = t->next;
            t->next = head;
            break;
        }
        t = t->next;
    }
    for (; HEAD != NULL; HEAD = HEAD->next)
    {
        printf("%d ", HEAD->num);
    }
    return 0;
}
