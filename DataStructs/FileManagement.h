#pragma once
#include <vector>
using namespace std;
class File
{
public:
	void loadIntegers(string);
	void loadWords(string);
	vector<int> &getIntVector() ;
	vector<string> &getWordsVector();
private:
	vector<int> integers;
	vector<string> words;
};

class MergeSort
{
public:
	void splitSort(vector<int>& );
private:
	void mSort(vector<int>&, vector<int>&, vector<int>&);
	
};