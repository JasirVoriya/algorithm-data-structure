#include <stdio.h>
#include <stdlib.h>
struct node
{
	char ch;
	int num;
	int data;
	struct node *next;
};
typedef struct node node;
typedef struct node *link;
link creat(int n) //������̬����
{
	if (n <= 0)
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
	{
		putchar('\n');
		return;
	}
	printf("%d ", head->data);
	print(head->next);
}
link min(link head)
{
	if(head==NULL||head->next==NULL)return head;
	link p1=head,p2=head->next;
	while(p2)
	{
		if(p2->data < head->data)head=p2;
		p1=p1->next;
		p2=p2->next;
	}
	return head;
}
link del(link head,int n)
{
	if(head==NULL)return NULL;
	if(head->data==n)return del(head->next,n);
	head->next=del(head->next,n);
	return head;
}
int main(void)
{
    int n;
    scanf("%d",&n);
	link head=creat(n);
    link MinNode=min(head);
    head=del(head,MinNode->data);
    MinNode->next=head;
    head=MinNode;
    print(head);
	
}