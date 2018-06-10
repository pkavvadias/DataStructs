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


/**
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
	
	
	
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
	cout << "Total duration(in milliseconds): " << duration.count() << endl;
	auto max = *max_element(d.begin(), d.end());
	cout << "Max value(in microseconds): " << max.count() << endl;
	Calculate T;
	T.rbTreeCalc(900, tree);

	getchar();
	

	}
	*/

int main()
{
	int select;
	int helper;
	int searchValue;
	int result;
	File f;
	Search s;
	MergeSort ms;
	RBTree tree;
	Calculate calc;
	TrieNode* trie=new TrieNode();

	cout << "What do you want to do?" << endl;
	cout << "1.Load integers" << endl;
	cout << "2.Load words" << endl;
	cout << "3.Search an integer" << endl;
	cout << "4.Insert integer(at Red-Black Tree)" << endl;
	cout << "5.Calculate search times" << endl;
	cout << "6.Search a word" << endl;
	cout << "7.Add a word" << endl;
	cout << "8.Delete a word" << endl;
	cout << "9.Exit" << endl;

	cin >> select;
	while(select>9||select<1)
	{
		cout << "Try again" << endl;
		cin >> select;
	}
	while(select!=8)
	{
		switch (select)
		{
		case 1:
		{
			f.loadIntegers("integers.txt");
			ms.sort(f.getIntVector());
			for(int i:f.getIntVector())
			{
				tree.insert(i);
			}
		}
		break;
		case 2:
		{
			f.loadWords("words.txt");
				for(string w:f.getWordsVector())
				{
					trie->insert(w,trie);
				}
		}
		break;
		case 3:
			{
			cout << "Press 1 for linear,2 for binary,3 for interpolation or 4 for red-black search" << endl;
			cin >> helper;
			while (helper>4 || helper<1)
			{
				cout << "Please try again" << endl;
				cin >> helper;
			}
			cout << "Enter the integer you want to search" << endl;
			cin >> searchValue;
				switch(helper)
				{
				case 1:
					{
					result=s.linearSearch(f.getIntVector(), searchValue);
					if (result == -1)
					{
						cout << "Not found" << endl;
					}
					else
					{
						cout << "Number found at " << result << " place" << endl;
					}
					}
					break;
				case 2:
					{
					result=s.binarySearch(f.getIntVector(), searchValue);
					if (result == -1)
					{
						cout << "Not found" << endl;
					}
					else
					{
						cout << "Number found at " << result << " place" << endl;
					}
					}
					break;
				case 3:
					{
					result=s.interpolationSearch(f.getIntVector(), searchValue);
					if (result == -1)
					{
						cout << "Not found" << endl;
					}
					else
					{
						cout << "Number found at " << result << " place"<<endl;
					}
					}
					break;
				case 4:
					{
					s.RbSearch(searchValue, tree);
					}
				}
			}
			break;
		case 4:
			{
			cout << "Enter the integer you want to insert" << endl;
			cin >> helper;
			tree.insert(helper);
			}
			break;
		case 5:
			{
			cout << "DATASTRUCTS BENCHMARK" << endl << endl;
			cout << "Press 1 to measure linear,2 for binary,3 for interpolation or 4 for red-black search time " << endl;
			cin >> helper;
				while(helper<1||helper>4)
				{
					cout << "Try again" << endl;
					cin >> helper;
				}
				cout << "Insert the number of searches you want to run" << endl;
				cin >> searchValue;
				if(helper==1)
				{
					calc.linearCalc(searchValue, f.getIntVector());
				}
				if(helper==2)
				{
					calc.binaryCalc(searchValue, f.getIntVector());
				}
				if(helper==3)
				{
					calc.interpolCalc(searchValue, f.getIntVector());
				}
				if(helper==4)
				{
					calc.rbTreeCalc(searchValue, tree);
				}
			}
			break;
		case 6:
			{
			cout << "NOT READY YET" << endl;
			}
			break;
		case 7:
			{
			cout << "NOT READY YET" << endl;
			}
			break;
		case 8:
			{
			cout << "NOT READY YET" << endl;
			}
			break;
		case 9:
			{
			return 0;
			}
		}
		cout << "Anything else?" << endl;
		cin >> select;
	}
}
