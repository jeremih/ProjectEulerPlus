#include <string>
#include <iostream>
#include <vector>

std::string addABunchONums() {
	int n;
	std::string curr_input;
	std::vector<short> total;

	for (int i = 0; i < 50; ++i) {
		total.push_back(0);
	}

	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> curr_input;
		auto total_iter = total.rbegin();
		for (auto iter = curr_input.rbegin(); iter != curr_input.rend(); ++iter) {
			*total_iter += (*iter - 48);
			auto overflow_iter = total_iter;
			while (*overflow_iter > 9) {
				if (overflow_iter != total.rend() - 1) {
					*overflow_iter++ -= 10;
					++(*overflow_iter);
				}
				else {
					*overflow_iter -= 10;
					total.insert(total.begin(), 1);
				}
			}
			++total_iter;
		}
	}

	std::string result = "";
	for (auto conversion_iter = total.begin(); conversion_iter != total.end(); ++conversion_iter) {
		result.append(1, toascii(*conversion_iter));
	}
	return result;
}

std::string addABunchONums2() {

	std::string result = "";

	return result;
}