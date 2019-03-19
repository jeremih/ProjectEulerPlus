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

using std::vector;

long getMaxProduct(vector<vector<int>> grid) {
	long max = 0;
	bool room_to_the_right= false;
	auto rowIter = grid.begin();
	while (rowIter != grid.end()) {
		auto colIter = rowIter->begin();
		while (colIter != rowIter->end()) {
			room_to_the_right = false;
			// Scan down
			if (rowIter <= grid.end() - 4) {
				long newProd = 1;
				int position = (colIter - rowIter->begin());
				for (int i = 0; i < 4; ++i) {
					newProd *= *((rowIter + i)->begin() + (position));
				}
				if (max < newProd) {
					max = newProd;
				}
				// Scan in diag down left direction
				if (colIter >= rowIter->begin() + 3) {
					newProd = 1;
					int position = (colIter - rowIter->begin());
					for (int i = 0; i < 4; ++i) {
						newProd *= *((rowIter + i)->begin() + (position - i));
					}
					if (max < newProd) {
						max = newProd;
					}
				}
				//Scan in diag down right direction
				if (colIter <= rowIter->end() - 4) {
					room_to_the_right = true;
					newProd = 1;
					int position = (colIter - rowIter->begin());
					for (int i = 0; i < 4; ++i) {
						newProd *= *((rowIter + i)->begin() + (position + i));
					}
					if (max < newProd) {
						max = newProd;
					}
				}
			}
			//Scan right
			if (room_to_the_right || colIter <= rowIter->end() - 4) {
				long newProd = 1;
				for (int i = 0; i < 4; ++i) {
					newProd *= *(colIter + i);
				}
				if (max < newProd) {
					max = newProd;
				}
			}
			++colIter;
		}
		++rowIter;
	}
	return max;
}