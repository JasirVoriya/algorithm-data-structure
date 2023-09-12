#include <bits/stdc++.h>
using namespace std;
const int maxn = 40;
int a[maxn], b[maxn];
int n;
struct Node
{
    int data;
    Node *left = NULL;
    Node *right = NULL;
};
Node *creat(int *a, int *b, int size) //中序、前序、长度
{
    if (size <= 0)
        return NULL;
    Node *root = new Node;
    root->data = b[0];
    int index = 0;
    while (a[index] != b[0])
        index++;
    root->right = creat(a, b + 1, index);
    root->left = creat(a + index + 1, b + index + 1, size - index - 1);
    return root;
}
int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    Node *root = creat(a, b, n);
    queue<Node *> que;
    que.push(root);
    Node *temp = que.front();
    que.pop();
    cout << temp->data;
    if (temp->left != NULL)
        que.push(temp->left);
    if (temp->right != NULL)
        que.push(temp->right);
    while (que.size())
    {
        Node *temp = que.front();
        que.pop();
        cout << " " << temp->data;
        if (temp->left != NULL)
            que.push(temp->left);
        if (temp->right != NULL)
            que.push(temp->right);
    }
    return 0;
}