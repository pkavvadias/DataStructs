#pragma once
#include <vector>
class RBTree;

class Calculate
{
public:
	void linearCalc(int,std::vector<int>&);
	void binaryCalc(int, std::vector<int>&);
	void interpolCalc(int, std::vector<int>&);
	void rbTreeCalc(int, RBTree&);

};

