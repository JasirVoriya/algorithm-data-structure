#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left = NULL, *right = NULL;
};
typedef Node *Tree;
int main(void)
{
    int top = 0;
    Tree tree[20];
    for (int i = 0; i < 20; i++)
    {
        tree[i] = new Node;
        tree[i]->data = i;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char left, right;
        cin >> left >> right;
        // cout << left << right << endl;
        if (left != '-')
        {
            // cout << "left" << endl;
            left -= '0';
            tree[i]->left = tree[left];
            if (left == top)
                top = i;
        }
        if (right != '-')
        {
            // cout << "right" << endl;
            right -= '0';
            tree[i]->right = tree[right];
            if (right == top)
                top = i;
        }
    }
    Tree root = tree[top];
    queue<Tree> que;
    que.push(root);
    int ans[10], count = 0;
    while (que.size())
    {
        Tree temp = que.front();
        que.pop();
        if (temp->left == NULL && temp->right == NULL)
            ans[count++] = temp->data;
        if (temp->left != NULL)
            que.push(temp->left);
        if (temp->right != NULL)
            que.push(temp->right);
    }
    cout << ans[0];
    for (int i = 1; i < count; i++)
        cout << " " << ans[i];
    cout << endl;
}