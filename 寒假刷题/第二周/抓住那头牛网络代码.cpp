#include<cstdio>
const int sb=1e6;
bool mark[sb+1];
int que[sb+1],pre[sb+1],n,k;
int next;
void print(int x)
{
	int num=0;
	while(pre[x])
	{
		num++;
		x=pre[x];
	}
	printf("%d",num);
}
void bfs()
{
	if(n==k){printf("0");return ;}
	int head=0,tail=1;
	que[1]=n;
	mark[n]=true;
	while(head!=tail)
	{
		head++;
		for(int i=0;i<3;i++)
		{
			switch(i)
			{
				case 0: next=que[head]+1;break;
				case 1: next=que[head]-1;break;
				case 2: next=que[head]*2;break;
			}
			if(next>=0&&next<=sb&&mark[next]!=true)
			{
				tail++;
				que[tail]=next;
				mark[next]=true;
				pre[tail]=head;
				if(next==k) 
				{
					print(tail);
					head=tail;
					break;
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	bfs();
}