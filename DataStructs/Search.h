#pragma once
#include <vector>
class TrieNode;
class RBTree;
class Search
{
public:
	int linearSearch(std::vector<int>&,int);
	int binarySearch(std::vector<int>&, int);
	int interpolationSearch(std::vector<int>&, int);
	void RbSearch(int,RBTree&);
	bool TrieSearch(std::string, TrieNode *&);
};