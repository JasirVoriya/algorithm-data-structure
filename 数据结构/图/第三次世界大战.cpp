#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxe = 100100, maxv = 1100;
const ll INF = unsigned(-1) >> 1;
const ll maxn = 1e1 + 10;
class Heap
{
private:
    ll *heap;
    ll size;
    ll getLeft(ll parent) //获取左节点
    {
        return 2 * parent + 1;
    }
    ll getRight(ll parent) //获取右节点
    {
        return 2 * parent + 2;
    }
    ll getParent(ll son) //获取父节点
    {
        if (son <= 0)
            return -1;
        return (son - 1) / 2;
    }
    void initHeap(ll n) //n是堆的大小，初始化堆元素
    {
        ll index = n;
        while (index--) //获取最后一个非叶子节点
            if (getLeft(index) < n)
                break;
        while (index >= 0)
        {
            ll parent = index, temp = heap[parent];
            while (true)
            {
                ll left = getLeft(parent), right = getRight(parent);
                if (left >= n) //没有左节点
                    break;
                ll minSon = right >= n ? left : heap[left] < heap[right] ? left
                                                                         : right;
                if (temp <= heap[minSon]) //父节点小于等于最小子节点
                    break;
                heap[parent] = heap[minSon];
                parent = minSon;
            }
            heap[parent] = temp;
            index--;
        }
    }
    void creatHeap(ll n = 0) //创建堆
    {
        for (ll i = 0; i < n; i++)
            cin >> heap[i];
        size = n;
        initHeap(size);
    }

public:
    Heap(ll n = 0)
    {
        size = 0;
        heap = new ll[maxn];
        creatHeap(n);
    }
    ~Heap()
    {
        delete[] heap;
    }
    ll getSize()
    {
        return this->size;
    }
    ll top()
    {
        if (this->size <= 0)
            return 0;
        return heap[0];
    }
    void push(ll value) //添加元素
    {
        ll son = size;
        heap[size++] = value; //先将插入的数据放在最后
        while (true)
        {
            ll parent = getParent(son); //得到它的父节点
            if (parent < 0)             //son已经是根节点了，结束
                break;
            if (heap[parent] <= value) //父节点小于等于插入的值，结束
                break;
            heap[son] = heap[parent];
            //然后让父节点变成下一轮的子节点，向上继续比较
            son = parent;
        }
        heap[son] = value;
    }
    void pop() //删除元素
    {
        if (size <= 0)
            return;
        heap[0] = heap[--size];
        ll parent = 0, temp = heap[parent];
        while (true)
        {
            ll left = getLeft(parent), right = getRight(parent);
            if (left >= size) //parent没有子节点了
                break;
            ll minSon = right >= size ? left : heap[left] < heap[right] ? left
                                                                        : right;
            if (temp <= heap[minSon]) //父节点小于等于最小子节点
                break;
            heap[parent] = heap[minSon];
            parent = minSon;
        }
        heap[parent] = temp;
    }
    void prllHeap() //打印堆
    {
        for (ll i = 0; i < size; i++)
            cout << heap[i] << ' ';
        cout << endl;
    }
    void heapSort() //堆排序
    {
        if (size <= 0)
            return;
        ll n = size;
        while (n--)
        {
            swap(heap[0], heap[n]);
            // prllHeap();
            initHeap(n);
        }
    }
};
int main(void)
{
    Heap prique[10010];
    ll n, k;
    cin >> n >> k;
    for (ll i = 0; i < n; i++)
    {
        ll c, value;
        scanf("%lld", &c);
        for (ll j = 0; j < c; j++)
        {
            scanf("%lld", &value);
            prique[i].push(value);
        }
    }
    ll ans = 0;
    for (ll i = 0; i < k - 1; i++)
    {
        for (ll j = 0; j < n; j++)
            prique[j].pop();
    }
    for (ll i = 0; i < n; i++)
    {
        ans += prique[i].top();
    }
    cout << ans << endl;
}