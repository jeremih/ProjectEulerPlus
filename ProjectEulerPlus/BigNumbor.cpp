#include "BigNumbor.h"

BigNumbor::BigNumbor(vector<int> v) {
	auto reverse_iter = v.rbegin();
	auto reverse_end = v.rend();
	while (reverse_iter != reverse_end) {
		digits.push_back(*reverse_iter++);
	}
}

BigNumbor::BigNumbor(string s) {
	auto reverse_iter = s.rbegin();
	auto reverse_end = s.rend();
	while (reverse_iter != reverse_end) {
		digits.push_back(*(reverse_iter++) - 48);
	}
}

void BigNumbor::add(BigNumbor &addend)
{
	
	bool carry = false;
	auto thisSize = this->getDigitCnt();
	auto otherSize = addend.getDigitCnt();
	
	//the following accomodates for when you add a larger number to a smaller one
	if (thisSize < otherSize) {
		for (int i = 0; i < (otherSize - thisSize); ++i) {
			digits.push_back(0);
		}
	}

	auto otherIter = addend.getIter();
	auto otherEnd = addend.getEnd();
	auto thisIter = this->getIter();
	auto thisEnd = this->getEnd();

	while (otherIter != otherEnd) {
		if (carry) {
			carry = false;
			++(*thisIter);
		}
		*thisIter += *otherIter;
		if (*thisIter >= 10) {
			*thisIter -= 10;
			carry = true;
		}
		++thisIter;
		++otherIter;
	}
	if (carry) {
		if (thisIter != thisEnd) {
			int carry_cnt = 0;
			while (thisIter + carry_cnt != thisEnd) {
				++(*(thisIter + carry_cnt));
				if (*(thisIter + carry_cnt) == 10) {
					*(thisIter + carry_cnt) -= 10;
					++carry_cnt;
				}
				else {
					return;
				}
			}
		}
		this->digits.push_back(1);
	}
}

vector<int>::iterator BigNumbor::getIter() {
	return this->digits.begin();
}

vector<int>::iterator BigNumbor::getEnd() {
	return this->digits.end();
}

int BigNumbor::getDigitCnt() {
	return this->digits.size();
}

string BigNumbor::toString() {
	string result = "";
	auto reverse_iter = this->digits.rbegin();
	auto reverse_end = this->digits.rend();

	while (reverse_iter != reverse_end) {
		result += std::to_string(*reverse_iter);
		++reverse_iter;
	}

	return result;
}