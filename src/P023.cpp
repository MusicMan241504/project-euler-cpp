#include <algorithm>
#include <iostream>
#include <vector>

bool isAbundantNum(int num) {
        int total {1}; // include 1
        for (int i{2}; i*i <= num; i++) { // start at 2 to avoid including num itself
                if (num % i == 0) { // if factor
                        if (i == num/i) { // if both factors same
                                total += i;
                        } else {
                                total += (i + num/i);
                        }
                }
        }
        return total>num;
}

int main() {
	std::vector<int> abundantNums{};
	// Fill array with abundant numbers
	for (int i{2}; i<28123; i++) {
		if (isAbundantNum(i)) {
			abundantNums.push_back(i);
		}
	}

	// Iterate through every number to check if it can be written as sum of 2 abundant numbers
	int total {0};
	for (int num{1}; num<=28123; num++) {
		bool isSumCorrect {0};
		for (size_t i{0}; abundantNums[i] < num; i++) {
			int needed {num-abundantNums[i]};
			// if needed is abundant num
			if (std::binary_search(abundantNums.begin(), abundantNums.end(), needed)) {	
				isSumCorrect = 1;
				break; // Exit inner for loop
			}
		}
		// Update total
		if (!isSumCorrect) {
			total += num;
		}
	}

	std::cout << total << '\n';


	return 0;
}

