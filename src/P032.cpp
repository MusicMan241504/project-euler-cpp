#include <cstdint>
#include <numeric>
#include <unordered_set>
#include <iostream>
int main() {
	std::unordered_set<int> products;
	// 2 digit * 3 digit = 4 digit
	// 1 digit * 4 digit = 4 digit
	for (int a{2}; a <= 99; a++) { // 1 or 2 digit
		for (int b{2}; a*b <= 9999; b++) { // max 4 digit total
			std::unordered_set<int> digits;
			int countDigits {0};
			int sumDigits {0};
			// add digits to set
			for (size_t i{0}; i<3; i++) {
				int tmp{0};
				switch (i) {
					case 0:
						tmp = a;
						break;
					case 1:
						tmp = b;
						break;
					case 2:
						tmp = a*b;
						break;
				}

				for (; tmp > 0; tmp=tmp/10) {
					digits.insert(tmp%10);
					sumDigits += tmp%10;
					countDigits++;
				}
			}
			if (countDigits == 9 && sumDigits == 45 && digits.size() == 9) {
				//std::cout << a << ' ' << b << ' ' << a*b <<  '\n';
				products.insert(a*b);
			}
		}
	}


	std::cout << std::accumulate(products.begin(),products.end(),0) << '\n';

	return 0;
}

