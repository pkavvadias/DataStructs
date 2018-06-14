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

	// if we have not reached the end of the key
	if (key.length())
	{
		// recurse for the node corresponding to next character in the key
		// and if it returns true, delete current node (if it is non-leaf)

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
	// if we have reached the end of the key
	if (key.length() == 0 && curr->isEnd)
	{
		// if current node is a leaf node and don't have any children
		if (!haveChildren(curr))
		{
			// delete current node
			delete curr;
			curr = nullptr;

			// delete non-leaf parent nodes
			return true;
		}

		// if current node is a leaf node and have children
		else
		{
			// mark current node as non-leaf node (DON'T DELETE IT)
			curr->isEnd = false;

			// don't delete its parent nodes
			return false;
		}
	}

	return false;
}