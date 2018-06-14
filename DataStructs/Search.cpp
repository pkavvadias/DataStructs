#include "Search.h"
#include <iostream>
#include "FileManagement.h"

using namespace std;

int Search::linearSearch(std::vector<int>& v,int s)
{
	for(int index=0;index<v.size();index++)
	{
		
		if(v[index]==s)
		{
			return index;
			
		}
	}
	return -1;
	
}

int Search::binarySearch(std::vector<int>& v,int s)
{
	int mid = -1;
	int left=0;
	int right = v.size()-1;
	while(left<=right){		
		mid = (left + right) / 2;  //Find middle
		if(s==v[mid]) //If equal
		{
			return mid;
		}
		if (s > v[mid])
		{
			left = mid+1;  // Search on right
		}
		else if(s < v[mid])
		{
			right = mid - 1; // Search on left
		}
	}
	return mid;
}

int Search::interpolationSearch(std::vector<int>& v, int s)
{
	
	int low = 0;
	int high = v.size() - 1;
	int mid=-1;
	if (s > v[high]) { return mid; }//Else crash
	while(low<=high)
	{		
			 mid = low + (((high - low) / (v[high] - v[low])) * (s - v[low]));
		if (s == v[mid]) //If equal
		{
			return mid;
		}
		
		if (s > v[mid])
		{
			low = mid+1;  
		}
		
		 if (s < v[mid])
		{
			
			high = mid - 1;
		}		 
	}
	return (v[low] == s) ? low : -1;//Simplified if
	
}

void Search::RbSearch(int x,RBTree &t)
{
	if (t.root == nullptr)
	{
		cout << "Tree is empty" << endl;
		return;
	}
	Node *y = t.root;
	int found = 0;
	while (y != nullptr && found == 0)
	{
		if (y->key == x)
		{
			found = 1;
			break;
		}
		if (found == 0)
		{
			if (y->key<x)
				y = y->right;
			else
				y = y->left;
		}
	}
	if (found == 0)
		cout << "Not Found" << endl;
	else
	{
		cout << "FOUND: " << endl;
		cout << "Key: " << y->key << endl;
		cout << "Colour: ";
		if (y->colour == "black")
			cout << "Black" << endl;
		else
			cout << "Red" << endl;
		if (y->parent != nullptr)
			cout << "Parent: " << y->parent->key << endl;
		else
			cout << "There is no parent" << endl;
		if (y->right != nullptr)
			cout << "Right Child: " << y->right->key << endl;
		else
			cout << "There is no right child" << endl;
		if (y->left != nullptr)
			cout << "Left Child: " << y->left->key << endl;
		else
			cout << "There is no left child" << endl;

	}
}
bool Search::TrieSearch(string word, TrieNode*& trie)
{
	// return false if Trie is empty
	if (trie == nullptr)
		return false;

	TrieNode* current = trie;
	for (int i = 0; i < word.length(); i++)
	{
		// go to next node
		current = current->characters[word[i]];

		// if string doesnt exist
		if (current == nullptr)
			return false;
	}

	// if current node is leaf and we are at the end of the string return true
	return current->isEnd;
}



