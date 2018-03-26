#include "FileManagement.h"
#include <iostream>
#include <fstream>
#include <string>

void File::loadIntegers(string filename)
{
	ifstream readInts;
	readInts.open(filename);
	if (readInts)
	{
		int v;
		while(readInts>>v)
		{
			integers.push_back(v);
		}
	}
}

void File::loadWords(string filename)
{
	ifstream readWords;
	readWords.open(filename);
	if(readWords)
	{
		string line;
		while (getline(readWords, line))
		{
			words.push_back(line);
		}
	}
}

vector<int> &File::getIntVector() 
{
	return integers;
}
vector<string> &File::getWordsVector()
{
	return words;
}

void MergeSort::splitSort(vector<int>&v)
{
	if (v.size() <= 1) {
		return;
	}
	int mid = v.size() / 2;
	vector<int> left;
	vector<int> right;
	copy(begin(v), begin(v) + mid, back_inserter(left));
	copy(begin(v)+mid, end(v), back_inserter(right));

	splitSort(left);
	splitSort(right);
	mSort(left, right, v);
	
}


void MergeSort::mSort(vector<int> &left, vector<int> &right, vector<int>&v)
{
	int lcomp = left.size();
	int rcomp = right.size();
	int leftLoop = 0;
	int rightLoop = 0;
	int finalLoop = 0;


	while (leftLoop < lcomp && rightLoop< rcomp)
	{
		if (left[leftLoop] <= right[rightLoop]) {
			v[finalLoop] = left[leftLoop];
			leftLoop++;
		}
		else {
			v[finalLoop] = right[rightLoop];
			rightLoop++;
		}
		finalLoop++;
	}
	while (leftLoop < lcomp) {
		v[finalLoop] = left[leftLoop];
		leftLoop++; finalLoop++;
	}
	while (rightLoop < rcomp) {
		v[finalLoop] = right[rightLoop];
		rightLoop++; finalLoop++;
	}
}



int main(){
	File* f=new File;
	//File f;
	f->loadIntegers("integers.txt");
	cout << "doing 1\n";
	//MergeSort* M=new MergeSort;
	MergeSort M;
	cout << "created\n";
	M.splitSort(f->getIntVector());
	//f.splitSort(f.integers);
	cout << "sorting...\n";
	cout << f->getIntVector()[0]<<endl;
	//cout << f.getIntVector()[2] << endl;
	cout << "finished\n";
	getchar();
	}
