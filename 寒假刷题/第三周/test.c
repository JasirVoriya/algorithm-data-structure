#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *l, *r;
};
typedef struct node node;
node *fun()
{
    int head = 0, tail = 0, a[1010], index = 0, n = 0, x;
    node *que[1010];               //队列
    while (scanf("%d", &x) != EOF) //输入
    {
        if (x == -1)
            break;
        a[n++] = x;
    }
    // for (int i = 0; i < n; i++)
    //     printf("%d ", a[i]);
    // putchar('\n');
    node *root = (node *)malloc(sizeof(node)); //开辟根节点
    root->l = root->r = NULL;
    root->data = a[index++];
    que[tail++] = root; //根节点入队
    while (head != tail && index < n)
    {
        node *temp = que[head++];                   //获取队首节点，并且pop
        node *first = (node *)malloc(sizeof(node)); //开辟节点
        first->l = first->r = NULL;
        first->data = a[index++];
        //printf("%d ", first->data);
        if (first->data != 0) //
        {
            temp->l = first;     //连接左节点
            que[tail++] = first; //左节点入队
        }

        node *second = (node *)malloc(sizeof(node)); //开辟节点
        second->l = second->r = NULL;
        second->data = a[index++];
        //printf("%d ", second->data);
        if (second->data != 0) //
        {
            temp->r = second;     //连接右节点
            que[tail++] = second; //右节点入队
        }
    }
    return root;
}
void postTrversal(node *temp) //后序遍历
{
    if (temp == NULL)
        return;
    postTrversal(temp->l);
    postTrversal(temp->r);
    printf("%d ", temp->data);
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int height(node *temp)
{
    if (temp == NULL)
        return 0;
    return max(height(temp->l), height(temp->r)) + 1;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        node *tree = fun();
        printf("%d ",height(tree));
        postTrversal(tree);
        putchar('\n');
    }
    return 0;
}