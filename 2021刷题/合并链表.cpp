#include"linklist.h"
struct node* fun(struct node* h1,struct node* h2)
{
	if(h1==NULL)return h2;
	if(h2==NULL)return h1;
	if(h1->data < h2->data)
	{
		h1->next=fun(h1->next,h2);
		return h1;
	}
	h2->next=fun(h2->next,h1);
	return h2;
}
int main(void)
{
	struct node *h1=creat(3),*h2=creat(5);
	h1=fun(h1,h2);
	print_data(h1);
} 
