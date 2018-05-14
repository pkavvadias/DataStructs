#include "FileManagement.h"
#include "Search.h"
#include "TimeCalc.h"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <algorithm>
using namespace std;

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

void MergeSort::sort(vector<int>&v)
{
	if (v.size() <= 1) {
		return;
	}
	int mid = v.size() / 2;
	vector<int> left;
	vector<int> right;
	copy(begin(v), begin(v) + mid, back_inserter(left));
	copy(begin(v)+mid, end(v), back_inserter(right));

	sort(left);
	sort(right);
	merge(left, right, v);
	
}


void MergeSort::merge(vector<int> &left, vector<int> &right, vector<int>&v)
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
	M.sort(f->getIntVector());
	//f.sort(f.integers);
	cout << "sorting...\n";
	cout << f->getIntVector()[0]<<endl;
	//cout << f.getIntVector()[2] << endl;
	Search s;
	int result=s.linearSearch(f->getIntVector(),10);
	if (result==-1)
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << "Number found at " << result << endl;
	}
	
	result = s.binarySearch(f->getIntVector(), 235910);
	if (result == -1)
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << "Number found at " << result << endl;
	}

	result = s.interpolationSearch(f->getIntVector(), 423586);
	if (result == -1)
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << "Number found at " << result << endl;
	}
	RBTree tree;
	
	for(int w=0;w<f->getIntVector().size();w++)
	{
		
		tree.insert(f->getIntVector()[w]);

	}
	
	/**
	tree.insert(5);
	tree.insert(6);
	tree.insert(7);
	tree.insert(2);
	tree.search(6);
	*/
	vector<chrono::microseconds> d;
	auto start = chrono::high_resolution_clock::now();
	int i = 0;
	for(i;i<100;i++)
	{
		auto separate = chrono::high_resolution_clock::now();
		s.RbSearch(i,tree);
		//tree.search(i);
		auto sto = chrono::high_resolution_clock::now();
		auto dur= chrono::duration_cast<chrono::microseconds>(sto - separate);
		//cout << "Dur " << dur.count() << endl;
		d.push_back(dur);
	}
	//tree.search(172982);
	
	/**
	for(int i=0;i==100000;i++)
	{
		tree.search(i);
		cout << i << endl;
	}
	*/
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
	cout << "Total duration(in milliseconds): " << duration.count() << endl;
	auto max = *max_element(d.begin(), d.end());
	cout << "Max value(in microseconds): " << max.count() << endl;
	Calculate T;
	T.rbTreeCalc(900, tree);

	getchar();
	}
