#include "Search.h"

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
	int right = v.size()-1;
	while(left<=right){		
		mid = (left + right) / 2;  //Find middle
		if(s==v[mid]) //If equal
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

int Search::interpolationSearch(std::vector<int>& v, int s)
{
	
	int low = 0;
	int high = v.size() - 1;
	int mid=-1;

	while(low<=high)
	{
		//low+[(high-low)/(v[high]-v[low]]*(s-v[low]
		mid = low + (((high - low) / (v[high] - v[low])) * (s - v[low]));
		
		if (s == v[mid]) //If equal
		{
			return mid;
		}
		
		if (s > v[mid])
		{
			low = mid+1;  
		}
		
		 if (s < v[mid])
		{
			
			high = mid - 1;
		}		 
	}
	return (v[low] == s) ? low : -1;//Simplified if
	
}


