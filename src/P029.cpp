#include <cmath>
#include <vector>
#include <iostream>

// NOTE
// This solution does not work as it would be overly complicated to fix
// The problem is if in the most simplified form b > 100 but there is another form where a is not the smallest possible value and b <= 100
// e.g. 2^102 = 4^51 = 8^34
//
// Please see P029-v2.cpp for a working solution

bool isSimplify(int a, int b, std::vector<std::vector<int>>& powers) {
	// simplify a in a^b
	for (size_t i{0}; i<3; i++) {
		for (size_t j{0}; j<9; j++) {
			if (a == powers[i][j]) {
				// check if b still in range
				if (b * (0.5*i*i + 0.5*i + 2) <= 100) {
					std::cout << a << ' ' << b << '\n';
					return 1;
				}
			}
		}
	}
	return 0;
}



int main() {
	// 2d array to store square, cube, and 5th power
	// 7th power not needed as 2^7 > 100
	// 10^2 is largest needed so 9 long
	std::vector<std::vector<int>> powers(3,std::vector<int> (9,0));
	for (size_t i{0}; i<3; i++) {
		for (size_t j{0}; j<9; j++) {
			powers[i][j] = std::pow(j+2, 0.5*i*i + 0.5*i + 2);
		}
	}

	int count{99*99};
	for (int a{2}; a<=100; a++) {
		for (int b{2}; b<=100; b++) {
			if (isSimplify(a,b,powers)) {
				count--;
			}
		}
	}

	std::cout << count << '\n';


	return 0;
}
