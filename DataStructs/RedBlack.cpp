#include "FileManagement.h"
#include <iostream>
using namespace std;


void RBTree::insert(int x)
{
	int i = 0;
	Node *z = new Node();
	z->key = x;
	z->left = nullptr;
	z->right = nullptr;
	z->colour = "red";
	Node *p = root;
	Node *q = nullptr;
	if (root == nullptr)
	{
		root = z;
		z->parent = nullptr;
	}
	else
	{
		while (p != nullptr)
		{
			q = p;
			if (p->key<z->key)
				p = p->right;
			else
				p = p->left;
		}
		z->parent = q;
		if (q->key<z->key)
			q->right = z;
		else
			q->left = z;
	}
	fix(z);
}


void RBTree::fix(Node* z)
{
	{
		while (z->parent != nullptr && z->parent->colour == "red")
		{
			if (z->parent == z->parent->parent->left)
			{
				Node* y = z->parent->parent->right;
				if (y != nullptr&&y->colour == "red")
				{
					z->parent->colour = "black";
					y->colour = "black";
					z->parent->parent->colour = "red";
					z = z->parent->parent;
				}
				else if (z == z->parent->right)
				{
					z = z->parent;
					leftrotate(z);

					z->parent->colour = "black";
					z->parent->parent->colour = "red";
					rightrotate(z->parent->parent);
				}
				else
				{
					z->parent->colour = "black";
					z->parent->parent->colour = "red";
					rightrotate(z->parent->parent);
				}
			}
			else
			{
				Node* y = z->parent->parent->left;
				if (y!=nullptr&&y->colour == "red")
				{
					z->parent->colour = "black";
					y->colour = "black";
					z->parent->parent->colour = "red";
					z = z->parent->parent;
				}
				else if (z == z->parent->left)
				{
					z = z->parent;
					rightrotate(z);
					z->parent->colour = "black";
					z->parent->parent->colour = "red";
					leftrotate(z->parent->parent);
				}
				else
				{
					z->parent->colour = "black";
					z->parent->parent->colour = "red";
					leftrotate(z->parent->parent);
				}
			}
		}
		root->colour = "black";
	}
}


void RBTree::leftrotate(Node* x)
{
	Node* y = x->right;
	x->right = y->left;

	if (y->left != q)
	{
		y->left->parent = x;
	}

	y->parent = x->parent;

	if (x->parent == q)
		root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	y->left = x;
	x->parent = y;
}

void RBTree::rightrotate(Node* y)
{
	Node* x = y->left;
	y->left = x->right;

	if (x->right != q)
	{
		x->right->parent = y;
	}

	x->parent = y->parent;

	if (y->parent == q)
		root = x;
	else if (y == y->parent->left)
		y->parent->left = x;
	else
		y->parent->right = x;

	x->right = y;
	y->parent = x;
}
