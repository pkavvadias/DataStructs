#include "TimeCalc.h"
#include "Search.h"
#include <chrono>
#include <vector>
#include <random>
#include <iostream>

using namespace std;

void Calculate::linearCalc(int numberOfSearches, std::vector<int> &vec)
{
	vector<chrono::microseconds> durations;
	int totalTime=0;
	Search s;
	default_random_engine randomGen;
	std::uniform_int_distribution<int> range(0, 900000);
	for(int i=0;i<numberOfSearches;i++)
	{
		auto start = chrono::high_resolution_clock::now();
		s.linearSearch(vec, range(randomGen));
		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		durations.push_back(duration);
	}
	auto worstCase = *max_element(durations.begin(), durations.end());
	for(auto i:durations)
	{
		totalTime += i.count();
	}
	cout << "Worst case time is " << worstCase.count()<<" microseconds"<<endl;
	cout << "Average time " << totalTime/numberOfSearches << " microseconds" << endl;
}

void Calculate::binaryCalc(int numberOfSearches, std::vector<int> &vec)
{
	vector<chrono::microseconds> durations;
	int totalTime = 0;
	Search s;
	default_random_engine randomGen;
	std::uniform_int_distribution<int> range(0, 900000);
	for (int i = 0; i<numberOfSearches; i++)
	{
		auto start = chrono::high_resolution_clock::now();
		s.binarySearch(vec, range(randomGen));
		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		durations.push_back(duration);
	}
	auto worstCase = *max_element(durations.begin(), durations.end());
	for (auto i : durations)
	{
		totalTime += i.count();
	}
	cout << "Worst case time is " << worstCase.count() << " microseconds" << endl;
	cout << "Average time " << totalTime / numberOfSearches << " microseconds" << endl;
}

void Calculate::interpolCalc(int numberOfSearches, std::vector<int> &vec)
{
	vector<chrono::microseconds> durations;
	int totalTime = 0;
	Search s;
	default_random_engine randomGen;
	//std::uniform_int_distribution<int> range(0, *max_element(vec.begin(), vec.end()));//Required for interpolation
	std::uniform_int_distribution<int> range(0, 900000);
	for (int i = 0; i<numberOfSearches; i++)
	{
		auto start = chrono::high_resolution_clock::now();
		s.interpolationSearch(vec, range(randomGen));
		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		durations.push_back(duration);
	}
	auto worstCase = *max_element(durations.begin(), durations.end());
	for (auto i : durations)
	{
		totalTime += i.count();
	}
	cout << "Worst case time is " << worstCase.count() << " microseconds" << endl;
	cout << "Average time " << totalTime / numberOfSearches << " microseconds" << endl;
}

void Calculate::rbTreeCalc(int numberOfSearches, RBTree &t)
{
	vector<chrono::microseconds> durations;
	int totalTime = 0;
	Search s;
	default_random_engine randomGen;
	std::uniform_int_distribution<int> range(0, 900000);
	for (int i = 0; i<numberOfSearches; i++)
	{
		auto start = chrono::high_resolution_clock::now();
		s.RbSearch(numberOfSearches, t);
		auto stop = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
		durations.push_back(duration);
	}
	auto worstCase = *max_element(durations.begin(), durations.end());
	for (auto i : durations)
	{
		totalTime += i.count();
	}
	cout << "Worst case time is " << worstCase.count() << " microseconds" << endl;
	cout << "Average time " << totalTime / numberOfSearches << " microseconds" << endl;
}


