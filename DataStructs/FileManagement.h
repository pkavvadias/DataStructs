#pragma once
#include <vector>

class File
{
public:
	void loadIntegers(std::string);
	void loadWords(std::string);
	std::vector<int> &getIntVector() ;
	std::vector<std::string> &getWordsVector();
private:
	std::vector<int> integers;
	std::vector<std::string> words;
};

class MergeSort
{
public:
	void sort(std::vector<int>& );
private:
	void merge(std::vector<int>&, std::vector<int>&, std::vector<int>&);
	
};

class Node
{
public:
	int key;
	Node *parent;
	std::string colour;
	Node *left;
	Node *right;
};

class RBTree
{
public:
	
	RBTree()
	{
		q = nullptr;
		root = nullptr;
	}
	
	void insert(int);
	void search(int);
private:
	Node *root;
	Node *q;
	void fix(Node*);
	void rightrotate(Node*);
	void leftrotate(Node*);
};
