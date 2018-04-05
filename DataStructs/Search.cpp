#include "Search.h"
#include <iostream>

using namespace std;

int Search::linearSearch(std::vector<int>& v,int s)
{
	for(int index=0;index<v.size();index++)
	{
		
		if(v[index]==s)
		{
			return index;
			
		}
	}
	return -1;
	
}

int Search::binarySearch(std::vector<int>& v,int s)
{
	int mid = -1;
	int left=0;
	int right = v.size();
	while(left<=right){		
		mid = (left + right) / 2;  //Find middle
		if(s==v[mid])
		{
			return mid;
		}
		if (s > v[mid])
		{
			left = mid+1;  // Search on right
		}
		else if(s < v[mid])
		{
			right = mid - 1; // Search on left
		}
	}
	return mid;
}


