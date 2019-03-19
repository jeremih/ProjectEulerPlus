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

long digiProd(int n, int k, string integer) {
	vector<int> *digits = new vector<int>();
	int n2 = n;
	auto iter = integer.begin();
	while (n2 != 0) {
		digits->push_back((*iter) - 48);
		++iter;
		--n2;
	}
	auto iter2 = digits->begin();
	long total = 0;
	for (int i = 0; i <= n - k; ++i) {
		long newTotal = 1;
		for (int j = 0; j < k; ++j) {
			newTotal *= *(iter2 + j);
		}
		if (total < newTotal) {
			total = newTotal;
		}
		++iter2;
	}
	return total;
}