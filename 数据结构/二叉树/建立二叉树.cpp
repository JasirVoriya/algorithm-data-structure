#include <bits/stdc++.h>
using namespace std;
struct phone
{
    string name = "none";
    double value = 0;
};
typedef phone data; //构建数据区
struct Node
{
    data obj;
    Node *left = NULL, *right = NULL;
};                                 //构建节点
bool cmp(data &father, data &node) //自定义规则
{
    if (father.value == node.value)
        return node.name < father.name;
    return node.value < father.value;
}
class Tree
{
private:
    int size=0;
    Node *root = NULL;

public:
    const Node *getroot(void)
    {
        return root;
    }
    int size()
    {
        return size;
    }
    void insert(data obj, bool (*cmp)(data &father, data &node) = cmp) //插入数据。（增）
    {
        auto node = new Node;   //新建一个节点
        node->obj = obj;        //将数据放入节点
        if (this->root == NULL) //如果是空树，直接让新节点作为根节点
        {
            root = node;
            return;
        }
        auto father = this->root;
        while (father != NULL)
        {
            if (cmp(father->obj, node->obj)) //按照自定义规则插入节点
            {
                if (father->left == NULL)
                {
                    father->left = node;
                    return;
                }
                else
                    father = father->left;
            }
            else
            {
                if (father->right == NULL)
                {
                    father->right = node;
                    return;
                }
                else
                    father = father->right;
            }
        }
        size++;
    }
    void pirnt(void) //打印二叉树，使用中序遍历法
    {
        if (root == NULL)
            return;
        stack<Node *> st;
        Node *temp;
        st.push(root);
        bool flag = true;
        while (st.size()) //空栈结束
        {
            while (flag && st.top()->left != NULL) //如果top之前没有向左入栈,我们就从左方向把节点入栈
                st.push(st.top()->left);
            temp = st.top(); //取出栈顶的节点，并弹出
            st.pop();
            //输出取出的节点
            cout << "name:" << temp->obj.name << " ";
            cout << "value:" << temp->obj.value << endl;
            //如果取出的节点有右支，则将右节点入栈
            if (temp->right != NULL)
            {
                st.push(temp->right);
                flag = true;//此时top节点已经更新，并且没有向左入栈，我们把标记设为true
            }
            else
                flag = false;//不然的话，栈里面所有的节点都已经向左入过栈了，
                             //就把标记设置为false，否则会重复入栈，导致死循环。
        }
    }
};                             //构建树
int main(void)
{
    Tree tree; //创建一个二叉树
    data temp;
    for (int i = 0; i < 5; i++)//输入5个数据
    {
        cin >> temp.name >> temp.value;
        tree.insert(temp);
    }
    tree.pirnt();
    return 0;
}