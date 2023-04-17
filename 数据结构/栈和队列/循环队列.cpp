//ѭ������
#include<bits/stdc++.h>
using namespace std;
template<typename ElemType>
class Queue
{
    private:
    static const int MAXSIZE=4;
    ElemType base[MAXSIZE];
    int front,rear,len;
    public:
    Queue(int n=0)
    {
        len=front=rear=0;
        ElemType val;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            this->push(val);
        }
    }
    bool push(const ElemType& val)
    {
        if(len==MAXSIZE)return false;
        base[rear]=val;
        rear=(rear+1)%MAXSIZE;
        len++;
        return true;
    }
    bool pop()
    {
        if(len==0)return false;
        front=(front+1)%MAXSIZE;
        len--;
        return true;
    }

};

