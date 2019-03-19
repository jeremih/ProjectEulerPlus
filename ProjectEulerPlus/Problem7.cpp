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

using namespace std;

vector<long>* makePrimeList(long n) {
	vector<long> *primeList = new vector<long>();
	primeList->push_back(2);
	for (long i = 3; i <= n; ++i) {
		auto iter = primeList->begin();
		bool prime = true;
		while (*iter * 3 <= i) {
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
	return primeList;
}

long getPrime(int i, vector<long> *primeList) {
	long prime = *(primeList->begin() + (i - 1));
	return prime;

}