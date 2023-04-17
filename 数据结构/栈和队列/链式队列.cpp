#include <iostream>
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
        Node(const ElemType &val)
        {
            data = val;
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
template <typename ElemType>
class Queue
{
private:
    List<ElemType> base;

public:
    Queue(void)
    {
    }
    bool push(const ElemType &val)
    {
        return base.push_back(val);
    }
    bool pop()
    {
        return base.pop_front();
    }
};
