#include "FileManagement.h"
#include <string>
#include <iostream>

using namespace std;

void TrieNode::insert(string word,TrieNode *current)
{
	// start from root node
	//TrieNode *current = this;
	for (int i = 0; i < word.length(); i++)
	{
		// create a new node if path doesn't exists
		if (current->characters[word[i]] == nullptr)
		{
			current->characters[word[i]] = new TrieNode();
		}

		// go to next node
		current = current->characters[word[i]];
	}

	// mark current node as leaf
	current->isEnd = true;
}
bool TrieNode::haveChildren(TrieNode const* curr)
{
	for (int i = 0; i < 128; i++)//ASCII size
		if (curr->characters[i])
			return true;    // child found

	return false;
}

bool TrieNode::deletion(string key,TrieNode*& curr)
{
	// return if Trie is empty
	if (curr == nullptr)
		return false;

	// if not at the end of string
	if (key.length())
	{
		//recursive function to find the node of the next character in the string
		//if it finds it(if it returns true) delete the crrent node if it isn't leaf

		if (curr != nullptr &&
			curr->characters[key[0]] != nullptr &&
			deletion(key.substr(1),curr->characters[key[0]]) &&
			curr->isEnd == false)
		{
			if (!haveChildren(curr))
			{
				delete curr;
				curr = nullptr;
				return true;
			}
			else {
				return false;
			}
		}
	}
	// if at the end of string
	if (key.length() == 0 && curr->isEnd)
	{
		// if current node is a leaf node and doesn't have children
		if (!haveChildren(curr))
		{
			// delete current node
			delete curr;
			curr = nullptr;

			// delete parent nodes that are not leafs
			return true;
		}

		// if current node is a leaf and has children
		else
		{
			// mark current node as non leaf
			curr->isEnd = false;

			return false;
		}
	}

}