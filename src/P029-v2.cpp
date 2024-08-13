#include <cstdint>
#include <unordered_set>
#include <set>
#include <vector>
#include <iostream>


std::vector<uint8_t> pow(int a, int b) {
	std::vector<uint8_t> ans(201,0);
	ans[ans.size()-1] = 1;
	// multiple ans by a b times
	for (int i{0}; i<b; i++) {
		int carry{0};
		// for each digit in ans start at ans.size() to 1 and use j-1 in place of j
		for (size_t j{ans.size()}; j>0; j--) {
			int tmp {ans[j-1]*a+carry};
			carry = tmp/10;
			ans[j-1] = tmp%10;
		}
	}
	return ans;
}


void printNum(std::vector<uint8_t>& num) {
	for (const auto& digit : num) {
		std::cout << +digit;
	}
	std::cout << '\n';
}


int main() {


	std::set<std::vector<uint8_t>> distinctPowers;
	for (int a{2}; a<101; a++) {
		for (int b{2}; b<101; b++) {
			std::vector<uint8_t> num {pow(a,b)};
			distinctPowers.insert(num);
		}
	}

	std::cout << distinctPowers.size() << '\n';

	return 0;
}
