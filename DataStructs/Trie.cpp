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