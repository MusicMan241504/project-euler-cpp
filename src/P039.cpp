#include <vector>
#include <iostream>
int main() {
	std::vector<int> counts(1001,0);
	for (int a{1}; a <= 500; a++) {
		for (int b{a}; a+b <= 500; b++) {
			for (int c{b}; c < a+b; c++) {
				if (a*a + b*b < c*c) {
					break;
				}
				if (a*a + b*b == c*c) {
					counts[a+b+c]++;
					break;
				}
			}
		}
	}
	

	// find max value in array
	int maxVal {0};
	size_t maxIndex {0};
	for (size_t i{0}; i <= 1000; i++) {
		if (counts[i] > maxVal) {
			maxVal = counts[i];
			maxIndex = i;
		}
	}
	std::cout << maxIndex << '\n';

	return 0;
}

