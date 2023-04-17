#include <bits/stdc++.h>
using namespace std;
template <typename ElemType>
class List
{
private:
    class Node
    {
    public:
        ElemType data;
        Node *next;

    public:
        Node(const ElemType &data)
        {
            this->data = val;
            next = NULL;
        }
    };
    typedef Node *LNode;
    LNode head, tail;
    int len;

    void delNode(LNode &__x)
    {
        if (__x != NULL)
        {
            delete __x;
            __x = NULL;
        }
    }
    LNode newNode(const ElemType &val)
    {
        LNode temp = new Node(val);
        return temp;
    }

public:
    List()
    {
        ElemType DEFAULT_ELEMDATA;
        head = tail = newNode(DEFAULT_ELEMDATA);
        len = 0;
    }
    ~List()
    {
        LNode __x = head->next;
        delNode(head);
        while (__x != NULL)
        {
            head = __x;
            __x = __x->next;
            delNode(head);
        }
    }
    ElemType front()
    {
        if (this->size() == 0)
            exit(0);
        return head->next->data;
    }
    bool is_empty()
    {
        return this->size() == 0;
    }
    void clear()
    {
        if (size() == 0)
            return;
        LNode __x = head->next;
        LNode __y = __x->next;
        delNode(__x);
        while (__y != NULL)
        {
            __x = __y;
            __y = __y->next;
            delNode(__x);
        }
        head->next = NULL;
        tail = head;
        len = 0;
    }
    void merge(List &__x)
    {
        LNode p1 = head->next, p2 = __x.head->next;
        LNode p = head;
        while (p1 && p2)
        {
            if (p1->data < p2->data)
                p = p->next = p1, p1 = p1->next;
            else
                p = p->next = p2, p2 = p2->next;
        }
        if (p1)
            p->next = p1;
        else
            p->next = p2, tail = __x.tail;
        len += __x.len;
        __x.head->next = NULL;
        __x.tail = __x.head;
        __x.len = 0;
    }
    int size()
    {
        return len;
    }
    bool insert(int pos, const ElemType &val)
    {
        LNode temp = newNode(val);
        if (pos < 0 || pos > len + 1 || temp == NULL)
            return false;
        LNode s = head;
        if (pos == len + 1)
        {
            tail = tail->next = temp;
            len++;
            return true;
        }
        for (int i = 1; i <= pos - 1; i++)
            s = s->next;
        temp->next = s->next;
        s->next = temp;
        len++;
        return true;
    }
    bool push_back(const ElemType &val)
    {
        LNode temp = newNode(val);
        if (temp == NULL)
            return false;
        tail = tail->next = temp;
        len++;
        return true;
    }
    bool push_front(const ElemType &val)
    {
        LNode temp = newNode(val);
        if (temp == NULL)
            return false;
        temp->next = head->next;
        head->next = temp;
        while (tail->next != NULL)
            tail = tail->next;
        len++;
        return true;
    }
    bool pop_back()
    {
        if (is_empty())
            return false;
        //Code
        std::cout << "pop_back: UnsupportedOperationException" << std::endl;
    }
    bool pop_front()
    {
        if (is_empty())
            return false;
        LNode temp = head->next;
        head->next = temp->next;
        delNode(temp);
        return true;
    }
    void reverse()
    {
        if (size() <= 1)
            return;
        LNode p1 = NULL, p2 = head->next, p3 = head->next;
        while (p3 != NULL)
        {
            p3 = p3->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        tail = head->next;
        head->next = p1;
    }
    int find(const ElemType &val)
    {
        int index = 1;
        auto s = this->head->next;
        while (s && s->data != val)
            s = s->next, index++;
        if (s == NULL)
            return 0;
        return index;
    }
    int count(const ElemType &val)
    {
        int cnt = 0;
        for (auto it = head->next; it != NULL; it = it->next)
            cnt += it->data == val;
        return cnt;
    }
};
template <class ElemType>
class Stack
{
private:
    List<ElemType> base;
    int len;

public:
    Stack()
    {
        len = 0;
    }
    bool push(const ElemType &val)
    {
        return base.push_front(val);
    }
    bool pop()
    {
        return base.pop_front();
    }
    int size()
    {
        return base.size();
    }
    ElemType top()
    {
        return base.front();
    }
};

typedef int data; //����������
struct value
{
    data obj;
    value *left = NULL, *right = NULL;
    value(data obj)
    {
        this->obj = obj;
        left = right = NULL;
    }
}; //�����ڵ�
typedef value *Node;
class Tree
{
private:
    int size;
    Node root;

public:
    Tree()
    {
        size = 0;
        root = NULL;
        this->root = levelCreat(); //ʹ�ò�����
    }
    Node newNode(data obj)
    {
        if (obj == 0)
            return NULL;
        Node node = new value(obj);
        return node;
    }
    Node newNode()
    {
        data obj;
        if (!(cin >> obj) == true)
            exit(0);
        if (obj == 0)
            return NULL;
        Node node = new value(obj);
        return node;
    }
    const Node getRoot(void)
    {
        return root;
    }
    int getSize()
    {
        return size;
    }
    Node levelCreat() //������
    {
        data obj;
        //�������ڵ�
        cin >> obj;
        if (obj == -1)
            return NULL;
        Node root = newNode(obj);
        if (root == NULL)
            return NULL;
        size++;
        queue<Node> que;
        que.push(root);
        while (1)
        {
            Node temp = que.front();
            que.pop();
            //
            cin >> obj;
            if (obj == -1)
                break;
            temp->left = newNode(obj);
            if (temp->left != NULL)
                que.push(temp->left), size++;
            //
            cin >> obj;
            if (obj == -1)
                break;
            temp->right = newNode(obj);
            if (temp->right != NULL)
                que.push(temp->right), size++;
        }
        return root;
    }
    Node preCreat() //������
    {
        Node node = newNode(); //�Ƚ������ڵ�
        if (node == NULL)      //Ҷ�ӽڵ㷵��
            return node;
        size++;
        node->left = preCreat();  //Ȼ����������
        node->right = preCreat(); //�����������
        return node;              //���ؽڵ�
    }
    void preTrversal(const Node node) //�������
    {
        if (node == NULL)
            return;
        cout << node->obj;
        preTrversal(node->left);
        preTrversal(node->right);
    }
    void pre_trversal() //�ǵݹ��������
    {
        Stack<Node> s;
        Node temp = root;
        while (temp || s.size())
        {
            if (temp != NULL) //�����ǰ�ڵ㲻Ϊ��
            {
                std::cout << temp->obj; //���ʸ��ڵ�
                s.push(temp);           //���ڵ���ջ
                temp = temp->left;      //����������
            }
            else
            {
                temp = s.top()->right; //������
                s.pop();
            }
        }
    }
    void inTrversal(const Node node) //�������
    {
        if (node == NULL)
            return;
        inTrversal(node->left);
        cout << node->obj;
        inTrversal(node->right);
    }
    void postTrversal(const Node node) //�������
    {
        if (node == NULL)
            return;
        postTrversal(node->left);
        postTrversal(node->right);
        cout << node->obj << ' ';
    }
    void levelTrversal() //�������
    {
        if (this->root == NULL)
            return;
        Node node = this->root;
        queue<Node> que;
        que.push(node);
        while (que.size())
        {
            node = que.front();
            que.pop();
            cout << node->obj;
            if (node->left != NULL)
                que.push(node->left);
            if (node->right != NULL)
                que.push(node->right);
        }
    }
    int height(const Node node)
    {
        if (node == NULL)
            return 0;
        return max(height(node->left), height(node->right)) + 1;
    }
}; //������
int main(void)
{
    Tree t;
    std::cout << "��������" << endl;
    t.preCreat();
    std::cout << "���������" << endl;
    t.preTrversal(t.getRoot());
    std::cout << "���������" << endl;
    t.inTrversal(t.getRoot());
    std::cout << "���������" << endl;
    t.postTrversal(t.getRoot());
    std::cout << "�ǵݹ����������" << endl;
    t.pre_trversal();
}