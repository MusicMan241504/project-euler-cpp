#include <set>
#include <vector>
#include <iostream>


void nextPermutation(std::vector<size_t>& digits) {
	// start at right and find first digit less than previous
	size_t digit {0};
	size_t i{digits.size()};
	// priority queue with smallest item popped first
	std::set<size_t> removedDigits{};
	// use index i-1 so i>0 can be achieved
	while (i > 0 && digits[i-1] >= digit) {
		digit = digits[i-1];
		removedDigits.insert(digits[i-1]);
		i--;
	}
	if (i == 0) { // no more permutations
		return;
	}

	// Set digit at i-1 to next highest digit
	// And add value at i-1 to set
	removedDigits.insert(digits[i-1]);
	auto nextHighestIt = removedDigits.upper_bound(digits[i-1]);
	digits[i-1] = *nextHighestIt;
	removedDigits.erase(nextHighestIt);
	

	// add digits in order of priority queue
	// Use i not i-1
	for (auto digit : removedDigits) {
		digits[i] = digit;
		i++;
	}
}

template <typename T>
void printDigits (const T& digits) {
	for (const auto& digit : digits) {
		std::cout << digit;
	}
	std::cout << '\n';
}

int main() {

	std::vector<size_t> digits{0,1,2,3,4,5,6,7,8,9};

	for (size_t i{1}; i <1000000; i++) {
		nextPermutation(digits);
	}
	printDigits(digits);


	return 0;
}
