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
