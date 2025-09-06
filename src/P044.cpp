#include <iostream>
#include <unordered_set>
long long int penNum(long int n) {
	long long int result {n*(3*n-1)/2};
	return result;
}

int main() {
	std::unordered_set<long long int> penNums;
	for (long int i{1}; i < 10000; i++) {
		penNums.insert(penNum(i));
	}
	//std::cout << "filled set" << '\n';

	// find pairs
	for (long int j{1}; j < 5000; j++) {
		long long int penJ{penNum(j)};
		for (long int k{j}; k < 5000; k++) {
			long long int penK{penNum(k)};

			// sum
			long long int sum{penJ + penK};
			long long int sub{penK - penJ};
			if (penNums.find(sum) != penNums.end() && penNums.find(sub) != penNums.end()) {
				//std::cout << j << ' ' << k << ' ' << sum << ' ' << sub << '\n';
				std::cout << sub << '\n';

			}
		}

	}
	return 0;
}
