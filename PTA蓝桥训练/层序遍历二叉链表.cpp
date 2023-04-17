#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char ch;
    Node *left = NULL, *right = NULL;
};
class Tree
{
private:
    Node *root = NULL;
    int size=0;
    Node *newNode()
    {
        char ch;
        cin >> ch;
        if (ch == '#')
            return NULL;
        Node *node = new Node;
        node->ch = ch;
        return node;
    }
    Node *preCreat()
    {
        Node *root = newNode();
        if (root != NULL)
        {
            size++;
            root->left = preCreat();
            root->right = preCreat();
        }
        return root;
    }
    void levelPrint()
    {
        queue<Node *> que;
        que.push(this->root);
        while (que.size())
        {
            Node *temp = que.front();
            que.pop();
            if (temp->left != NULL)
                que.push(temp->left);
            if (temp->right != NULL)
                que.push(temp->right);
            cout << temp->ch;
        }
    }

public:
    int getSize()
    {
        return size;
    }
    void creat()
    {
        this->root = preCreat();
    }
    void print()
    {
        levelPrint();
    }
};
int main(void)
{
    Tree tree;
    tree.creat();
    tree.print();
    // cout<<tree.getSize();
    return 0;
}