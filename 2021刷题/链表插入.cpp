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
link creat(int n) //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ì¬ï¿½ï¿½ï¿½ï¿½
{
	if (n == 0)
		return NULL;
	link head = (link)malloc(sizeof(struct node));
	head->num = n;
	scanf("%d", &head->data);
	head->next = creat(n - 1);
	return head;
}
void print(link head) //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?
{
	if (head == NULL)
	{
		putchar('\n');
		return;
	}
	printf("%d ", head->data);
	print(head->next);
}
link  insert_list(link  head,link  p1)
{
	struct node *start=(link )malloc(sizeof(struct node));
	start->next=head;
	head=start->next;
	while(start->next!=NULL)
	{
		if(start->next->data > p1->data)
		{
			p1->next=start->next;
			start->next=p1;
			return head;
		}
		start=start->next;
	}
	p1->next=start->next;
	start->next=p1;
	return head;
} 
int main(void)
{
    int n;
    scanf("%d",&n);
	link head=creat(n);
	link p1=head;
    head=head->next;
	head=insert_list(head,p1);
	print(head);
}
