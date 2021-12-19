#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct Node
{
	int val;
	Node *left, *right, *parent;
};

Node *parseNode()
{
	string tk;
	cin >> tk;
	if (tk == "[")
	{
		Node *left = parseNode();
		string cm;
		cin >> cm;
		assert(cm == ",");
		Node *right = parseNode();
		string cl;
		cin >> cl;
		assert(cl == "]");
		Node *parent = new Node;
		parent->left = left;
		parent->right = right;
		left->parent = parent;
		right->parent = parent;
		parent->val = -1;
		return parent;
	}
	int val = 0;
	for (const char c : tk)
	{
		assert(c >= '0' && c <= '9');
		val = 10 * val + c - '0';
	}
	Node *nw = new Node;
	nw->left = nw->right = nw->parent = NULL;
	nw->val = val;
	return nw;
	/*
	Node *root = new Node;
	root->parent = NULL;
	Node *cur;
	cur = root;
	bool nowRight = false;
	string tk;
	cin >> tk;
	assert(tk == "[");
	cur = new Node;
	cur.parent

	const auto acceptOpen = [&]() -> void
	{
		Node *nw = new Node;
		nw.parent = cur;
		if 
	};
	while (1)
	{

	}
	*/
}

bool fixExplode(Node *const from, const int depth)
{
	if (from->val != -1)
		return false;
	if (from->left->val != -1 && from->right->val != -1)
	{
		if (depth >= 4)
		{
			{
				Node *upl = from;
				while (1)
				{
					Node *last = upl;
					upl = upl->parent;
					if (upl == NULL)
						break;
					if (upl->right == last)
						break;
				}
				if (upl != NULL)
				{
					upl = upl->left;
					while (upl->val == -1)
						upl = upl->right;
					upl->val += from->left->val;
				}
			}
			{
				Node *upr = from;
				while (1)
				{
					Node *last = upr;
					upr = upr->parent;
					if (upr == NULL)
						break;
					if (upr->left == last)
						break;
				}
				if (upr != NULL)
				{
					upr = upr->right;
					while (upr->val == -1)
						upr = upr->left;
					upr->val += from->right->val;
				}
			}
			Node *nw = new Node;
			nw->parent = from->parent;
			nw->val = 0;
			nw->left = nw->right = NULL;
			if (from->parent->left == from)
				from->parent->left = nw;
			else
				from->parent->right = nw;
			delete from->left;
			delete from->right;
			delete from;
			return true;
		}
	}
	const bool rl = fixExplode(from->left, depth + 1);
	const bool rr = fixExplode(from->right, depth + 1);
	return rl || rr;
}

bool fixSplit(Node *const root)
{
	if (root->val == -1)
	{
		if (fixSplit(root->left))
			return true;
		return fixSplit(root->right);
	}
	if (root->val >= 10)
	{
		Node *nwl = new Node, *nwr = new Node;
		nwl->parent = nwr -> parent = root;
		nwl->left = nwl->right = nwr->left = nwr->right = NULL;
		nwl->val = root->val / 2;
		nwr->val = (root->val + 1) / 2;
		root->left = nwl;
		root->right = nwr;
		root->val = -1;
		return true;
	}
	return false;
}

void norm(Node *const root)
{
	bool change;
	do
	{
		change = false;
		fixExplode(root, 0);
		change = fixSplit(root);
	} while (change);
}

ll eval(Node *const root)
{
	if (root->val == -1)
		return 3 * eval(root->left) + 2 * eval(root->right);
	return root->val;
}

Node *cpy(Node *const root)
{
	if (root->val != -1)
	{
		Node *nw = new Node;
		nw->val = root->val;
		nw->parent = nw->left = nw->right = NULL;
		return nw;
	}
	Node *const lcpy = cpy(root->left);
	Node *const rcpy = cpy(root->right);
	Node *const nw = new Node;
	nw->left = lcpy;
	nw->right = rcpy;
	nw->val = -1;
	nw->parent = NULL;
	lcpy->parent = rcpy->parent = nw;
	return nw;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	/*
	vector<Node*> nums(n);
	for (int i = 0; i < n; i++)
		nums[i] = parseNode();
	ll mx = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			Node *p = new Node;
			Node *n0 = cpy(nums[i]);
			Node *n1 = cpy(nums[j]);
			p->left = n0;
			p->right = n1;
			p->parent = NULL;
			p->val = -1;
			n0->parent = n1->parent = p;
			norm(p);
			mx = max(mx, eval(p));
		}
	cout << mx << endl;
	*/
	Node *cur = parseNode();
	for (int i = 1; i < n; i++)
	{
		Node *par = parseNode();
		Node *nw = new Node;
		cur->parent = par->parent = nw;
		nw->left = cur;
		nw->right = par;
		nw->parent = NULL;
		nw->val = -1;
		cur = nw;
		norm(cur);
	}
	cout << eval(cur) << endl;

	return EXIT_SUCCESS;
}
