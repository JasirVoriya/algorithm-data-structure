#include <bits/stdc++.h>
#define PI acos(-1)
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MAX_N = 1e3 + 5;
using namespace std;
struct node {
    int const val;
    node *left, *right;
    node(int val)
        : val(val)
        , left(nullptr)
        , right(nullptr) {};
};
queue<int> que;
// 退化成线了
node* create()
{
    if (que.empty())
        return nullptr;
    node* root = new node(que.front());
    que.pop();
    root->left = create();
    root->right = create();
    return root;
}
bool check1(node* root)
{
    if (root->left && root->right) {
        bool b1 = root->left->val < root->val;
        bool b2 = root->val <= root->right->val;
        return b1 && b2 && check1(root->left) && check1(root->right);
    }
    return true;
}
bool check2(node* root)
{
    if (root->left && root->right) {
        bool b1 = root->left->val >= root->val;
        bool b2 = root->val > root->right->val;
        return b1 && b2 && check2(root->left) && check2(root->right);
    }
    return true;
}
int arr[MAX_N];
int cnt = 0;
void back(node* root)
{
    if (root == nullptr)
        return;
    back(root->left);
    back(root->right);
    arr[cnt++] = root->val;
    // cout << root->val << endl;
}
void pre(node* root)
{
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    pre(root->left);
    pre(root->right);
}
int main(void)
{
    int n;
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        que.push(x);
    }
    node* root = create();
    // cout<<root->left->val<<endl;
    if (check1(root) || check2(root)) {
        cout << "YES" << endl;
        back(root);
        cout << arr[0];
        for (int i = 1; i < n; i++) {
            cout << " " << arr[i];
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
        // }
        return 0;
    }
}