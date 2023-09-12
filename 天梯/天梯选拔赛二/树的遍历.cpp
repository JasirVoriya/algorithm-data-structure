#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left, *right;
};

node *fun(int *a, int *b, int size)  //后序 中序 大小
{
    if (size <= 0) return NULL;
    int data = a[size - 1];
    node *root = new node;
    root->data = data;
    int index = 0;
    while (data != b[index]) index++;
    root->left = fun(a, b, index);
    root->right = fun(a + index, b + index + 1, size - index - 1);
    return root;
}
int main(void) {
    int n;
    int str1[50] = {0}, str2[50] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) cin >> str1[i];
    for (int i = 0; i < n; i++) cin >> str2[i];
    node *root = fun(str1, str2, n);
    queue<node *> que;
    que.push(root);
    node *temp = que.front();
    que.pop();
    cout << temp->data;
    if (temp->left != NULL) que.push(temp->left);
    if (temp->right != NULL) que.push(temp->right);
    while (que.size()) {
        node *temp = que.front();
        que.pop();
        cout << " " << temp->data;
        if (temp->left != NULL) que.push(temp->left);
        if (temp->right != NULL) que.push(temp->right);
    }
    return 0;
}