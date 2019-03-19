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
#include "PythagTriplet.h"
using namespace std;

long long getPythagProduct(int n, vector<PythagTriplet*> &tripVec) {
	long long highest = -1;
	for (auto triplet : tripVec) {
		if (n % triplet->getSum() == 0) {
			int multiple = n / triplet->getSum();
			if (highest < triplet->getProd() * (multiple * multiple * multiple)) {
				highest = triplet->getProd() * (multiple * multiple * multiple);
			}
		}
	}
	return highest;
}

vector<PythagTriplet*> getTripleVector(int max) {
	vector<PythagTriplet*> *tripVec = new vector<PythagTriplet*>();

	for (int m = 1; (2 * m * m) + (2 * m) <= max; ++m) {
		for (int n = 1; n < m; ++n) {
			int a = (m * m) - (n * n);
			int b = 2 * m * n;
			int c = (m * m) + (n * n);
			tripVec->push_back(new PythagTriplet(a, b, c));
		}
	}
	return *tripVec;
}