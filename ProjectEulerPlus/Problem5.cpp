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

int divisibleValue(int n) {
	int total = 1;
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 2;
	}
	else {
		vector<int> primeVector = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
		map<int, int> primeCountMap;
		for (int i : primeVector) {
			primeCountMap[i] = 0;
		}
		for (int i = 2; i <= n; ++i) {
			auto primeIter = primeVector.begin();
			while (*primeIter <= i) {
				int cnt = 0, test = i;
				while (test % (*primeIter) == 0) {
					test /= (*primeIter);
					++cnt;
				}
				if (cnt && primeCountMap[*primeIter] < cnt) {
					primeCountMap[*primeIter] = cnt;
				}
				++primeIter;
			}
		}
		for (int i : primeVector) {
			int j = primeCountMap[i];
			int k = 1;
			while (j != 0) {
				k *= i;
				--j;
			}
			total *= k;
		}
		return total;
	}
}

