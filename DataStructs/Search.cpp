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

