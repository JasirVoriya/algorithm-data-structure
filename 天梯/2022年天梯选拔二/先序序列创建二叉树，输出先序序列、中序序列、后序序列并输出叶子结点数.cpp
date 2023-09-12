#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e2;
const int INF = 0x3f3f3f3f;
typedef long long ll;
struct node {
    char ch;
    node *left, *right;
    node(char ch)
        : ch(ch)
        , left(nullptr)
        , right(nullptr) {};
};
node* create(string& str)
{
    if (str.size() == 0)
        return nullptr;
    char ch = str[str.size() - 1];
    str.pop_back();
    if (ch == '#')
        return nullptr;
    node* root = new node(ch);
    root->left = create(str);
    root->right = create(str);
    return root;
}
int cnt = 0;
void A(node* root, string& str)
{
    if (root == nullptr)
        return;
    str.push_back(root->ch);
    A(root->left, str);
    A(root->right, str);
    if (root->right == nullptr && root->left == nullptr)
        cnt++;
}
void B(node* root, string& str)
{
    if (root == nullptr)
        return;
    B(root->left, str);
    str.push_back(root->ch);
    B(root->right, str);
}
void C(node* root, string& str)
{
    if (root == nullptr)
        return;
    C(root->left, str);
    C(root->right, str);
    str.push_back(root->ch);
}
void out(string& str)
{
    for (char ch : str) {
        cout << ch;
    }
    cout << endl;
}
int main(void)
{
    string str;
    cin >> str;
    reverse(str.begin(), str.end());
    node* root = create(str);
    if (root == nullptr) {
        cout << cnt << endl;
        return 0;
    }
    string str1, str2, str3;
    A(root, str1), B(root, str2), C(root, str3);
    out(str1), out(str2), out(str3);
    cout << cnt << endl;
    return 0;
}