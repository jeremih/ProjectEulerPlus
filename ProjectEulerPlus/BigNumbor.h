#pragma once
#include <vector>
#include <string>

using std::vector;
using std::string;

class BigNumbor {
private:
	vector<int> digits;

public:
	BigNumbor(vector<int> v);
	BigNumbor(string s);

	void add(BigNumbor &);

	vector<int>::iterator getIter();
	vector<int>::iterator getEnd();
	int getDigitCnt();

	string toString();
};