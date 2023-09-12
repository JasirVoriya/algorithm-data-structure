#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
struct node
{
    int num;
    int data;
    struct node *next;
};
typedef node *link;
link creat(int n)
{
    if (n == 0)
    {
        getchar();
        return NULL;
    }
    link head = (link)malloc(sizeof(struct node));
    head->num = n;
    scanf("%c", &head->data);
    head->next = creat(n - 1);
    return head;
}
void print(link head)
{
	if(head==NULL)
	{
		putchar('\n'); 
		return;
	}
	printf("%c",head->data);
	print(head->next);
}
void linkfree(int n, ...)
{
    va_list ap;
    va_start(ap,n);
    for(int i=0;i<n;i++)
    {
        link pre=va_arg(ap,link);
        link res=pre->next;
        while(res!=NULL)
        {
            free(pre);
            pre=res;
            res=res->next;
        }
        free(pre);
    }
    va_end(ap);
}
int main(void)
{
    int t;
    scanf("%d", &t),getchar();
    while (t--)
    {
        int n;
        scanf("%d", &n),getchar();
        link link1 = creat(n), link2 = creat(n);
        //print(link1),print(link2);
        int count=0;
        link it1=link1,it2=link2;
        while(it1!=NULL)
        {
            if(it1->data==it2->data)count++;
            it1=it1->next,it2=it2->next;
        }
        printf("%d\n",count);
        linkfree(2, link1, link2);
    }
}
