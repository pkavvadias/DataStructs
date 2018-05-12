#include "FileManagement.h"
#include <iostream>
using namespace std;

Node* RBTree::getNil()
{
	return q;
}


void RBTree::insert(int x)
{
	int i = 0;
	//Node *q;
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
	Node *u;
	if (root == z)
	{
		z->colour = "black";
		return;
	}
	while (z->parent != nullptr && z->parent->colour == "red")
	{
		Node *g = z->parent->parent;
		if (g->left == z->parent)
		{
			if (g->right != nullptr)
			{
				u = g->right;
				if (u->colour == "red")
				{
					z->parent->colour = "black";
					u->colour = "black";
					g->colour = "red";
					z = g;
				}
			}
			else
			{
				if (z->parent->right == z)
				{
					z = z->parent;
					leftrotate(z);
				}
				z->parent->colour = "black";
				g->colour = "red";
				rightrotate(g);
			}
		}
		else
		{
			if (g->left != nullptr)
			{
				u = g->left;
				if (u->colour == "red")
				{
					z->parent->colour = "black";
					u->colour = "black";
					g->colour = "red";
					z = g;
				}
			}
			else
			{
				if (z->parent->left == z)
				{
					z = z->parent;
					rightrotate(z);
				}
				z->parent->colour = "black";
				g->colour = "red";
				leftrotate(g);
			}
		}
		root->colour = "black";
	}
}

void RBTree::leftrotate(Node* x)
{
	if(x->right==nullptr)
	{
           return ;
	}
     else
     {
           Node *y=x->right;
           if(y->left!=nullptr)
           {
                  x->right=y->left;
                  y->left->parent=x;
           }
           else
                  x->right=nullptr;
           if(x->parent!=nullptr)
                y->parent=x->parent;
           if(x->parent==nullptr)
                root=y;
           else
           {
               if(x==x->parent->left)
                       x->parent->left=y;
               else
                       x->parent->right=y;
           }
           y->left=x;
           x->parent=y;
     }
}

void RBTree::rightrotate(Node* x)
{
	if(x->left==nullptr)
          return ;
     else
     {
         Node *y=x->left;
         if(y->right!=nullptr)
         {
                  x->left=y->right;
                  y->right->parent=x;
         }
         else
                 x->left=nullptr;
         if(x->parent!=nullptr)
                 y->parent=x->parent;
         if(x->parent==nullptr)
               root=y;
         else
         {
             if(x==x->parent->left)
                   x->parent->left=y;
             else
                   x->parent->right=y;
         }
         y->right=x;
         x->parent=y;
     }
}

void RBTree::search(int x)
{
	if (root == nullptr)
	{
		cout << "Tree is empty"<<endl;
		return;
	}
	Node *y = root;
	int found = 0;
	while (y != nullptr && found == 0)
	{
		if (y->key == x)
			found = 1;
		if (found == 0)
		{
			if (y->key<x)
				y = y->right;
			else
				y = y->left;
		}
	}
	if (found == 0)
		cout << "Not Found"<<endl;
	else
	{
		cout << "FOUND: "<<endl;
		cout << "Key: " << y->key<<endl;
		cout << "Colour: ";
		if (y->colour == "black")
			cout << "Black"<<endl;
		else
			cout << "Red"<<endl;
		if (y->parent != nullptr)
			cout << "Parent: " << y->parent->key<<endl;
		else
			cout << "There is no parent"<<endl;
		if (y->right != nullptr)
			cout << "Right Child: " << y->right->key<<endl;
		else
			cout << "There is no right child"<<endl;
		if (y->left != nullptr)
			cout << "Left Child: " << y->left->key<<endl;
		else
			cout << "There is no left child"<<endl;

	}
}