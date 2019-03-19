#include <map>
#include <iostream>
#include <algorithm>
#include "TriangleNumber.h"

int factorCount(long triang_num) {
	int cnt = 0;
	long divisor = 1;

	//until divisor reaches the square root of triang_num, check if it's a factor
	while (divisor * divisor <= triang_num) {
		if (triang_num % divisor == 0) {
			cnt += 1;
		}
		divisor += 1;
	}

	//multiply cnt by 2 to account for the other factors
	cnt *= 2;

	//if the number is a square, add 1 to the count to account for the one extra factor
	divisor -= 1;
	if (divisor * divisor == triang_num) {
		--cnt;
	}
	return cnt;
}

long getTriangNumWithNDivisors(int n) {
	++n;
	static std::map<int, TriangleNumber> triang_map;
	static TriangleNumber triang_num;
	while (triang_map.find(n) == triang_map.end()) {
		//about to add next number to the factor count, this will be the vector's current size + 1
		int currIncrement = triang_num.getIncrement();
		//get the count for the next triangle number
		int curr_cnt = factorCount(triang_num.getCurrVal());
		//add this count to as many vector positions as necessary
		/*while (curr_cnt >= currIncrement++) {
			triang_map
		}*/
		triang_num.increment();
	}
	//return triang_num_vec[n - 1];
	return -2;
}
