#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
typedef struct node *tree;

struct node
{
	char date;
	node *left, *right;
} * p;

tree set(tree &p)
{
	char ch;
	cin >> ch;
	if (ch == '#')
	{
		p = NULL;
	}
	else
	{
		p = new node;
		p->date = ch;
		p->left = NULL;
		p->right = NULL;
		set(p->left);
		set(p->right);
	}
	return p;
}

void in(tree node)
{
	if (node == NULL)
	{
		return;
	}
	in(node->left);
	cout << node->date;
	in(node->right);
}

void post(tree node)
{
	if (node == NULL)
	{
		return;
	}
	post(node->left);
	post(node->right);
	cout << node->date;
}

int main(int argc, char *argv[])
{
	while (1)
	{
		queue<tree> q;
		set(p);
		in(p);
		cout << " ";
		post(p);
		cout << " ";
		q.push(p);
		while (!q.empty())
		{
			tree t = q.front();
			q.pop();
			cout << t->date;
			if (t->left != NULL)
			{
				q.push(t->left);
			}
			if (t->right != NULL)
			{
				q.push(t->right);
			}
		}
		cout << endl;
	}
	return 0;
}
