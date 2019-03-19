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

long long sumSquareSubtract(int n) {
	unsigned long long total1 = 0, total2 = 0;
	for (int i = 1; i <= n; ++i) {
		total1 += i;
	}
	total1 *= total1;
	for (int i = 1; i <= n; ++i) {
		total2 += (i * i);
	}
	return total1 - total2;
}