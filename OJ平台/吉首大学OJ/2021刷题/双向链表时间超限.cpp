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
link creat(int n) //创建双向链表环
{
	if (n <= 0)
		return NULL;
	link head, tail, ins;
	head = tail = ins = (link)malloc(sizeof(node));
	scanf("%d", &ins->data);
	while (--n)
	{
		ins = (link)malloc(sizeof(node));
		scanf("%d", &ins->data);
		ins->pre = tail;
		tail = tail->next = ins;
	}
	tail->next = head;
	head->pre = tail;
	return head;
}
void print(link head, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", head->data);
		head = head->next;
	}
    putchar('\n');
}
link index(link head, int step)
{
	while (--step)
		head = head->next;
	return head;
}
link del(link head, int pos)
{
	link DelNode = index(head, pos);
	DelNode->pre->next = DelNode->next;
	DelNode->pre->next->pre = DelNode->pre;
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
	return head;
}
int main()
{
	int m;
	scanf("%d", &m);
	link link1 = creat(m);
    print(link1,m);

	int DelIndex;
	scanf("%d", &DelIndex);
	link1 = del(link1, DelIndex);
    m--;
    print(link1,m);

	int pos, Insvalue;
	scanf("%d%d", &pos, &Insvalue);
	link1 = ins(link1, pos, Insvalue);
    m++;
    print(link1,m);

	int step;
	scanf("%d", &step);
	link1 = index(link1, step);
	print(link1, m);
	return 0;
}