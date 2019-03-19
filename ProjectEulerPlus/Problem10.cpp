#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#include <memory>
#include "ProjEuler.h"
using namespace std;

long long getPrimeSum(long n, vector<long>* primeList) {
	long long sum = 0;
	for (auto iter = primeList->begin(); iter != primeList->end() && *iter <= n; ++iter) {
		sum += *iter;
	}
	return sum;
}

vector<long>* modifyPrimeList(vector<long>* primeList, long n) {
	if (!primeList || primeList->size() == 0) {
		return primeList;
	}
	long greatestInList = *(primeList->end() - 1);
	if (n <= greatestInList) {
		return primeList;
	}
	else {
		for (long i = greatestInList + 2; i <= n; i += 2) {
			auto iter = primeList->begin();
			bool prime = true;
			while (*iter * 2 <= i) {
				if (i % *iter == 0) {
					prime = false;
					break;
				}
				++iter;
			}
			if (prime) {
				primeList->push_back(i);
			}
		}
	}
	return primeList;
}

shared_ptr<vector<long>> sieveOfEratosthenes(long n) {
	auto primeList = make_shared<vector<long>>();
	for (long i = 0; i != n; ++i) {
		primeList->push_back(i);
	}
	auto iter = primeList->begin() + 2;
	*(iter - 1)= 0; // Removes 1 from the primeList
	int currPrime = *iter;
	while (currPrime * 2 <= n) {
		for (long j = currPrime; j * currPrime < n; ++j) {
			*(primeList->begin() + (currPrime * j)) = 0;
		}
		++iter;
		while (*iter == 0) {
			++iter;
		}
		currPrime = *iter;
	}
	return primeList;
}