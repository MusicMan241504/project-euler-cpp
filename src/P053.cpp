#include <iostream>
long long int comb(int n, int r) {
	long long int numerator{1};
	long long int denominator{1};
	for (int i{0}; i < r; i++) {
		numerator = numerator * (n-i);
		denominator = denominator * (r-i);
	}

	return numerator/denominator;
}

int main() {
	int count{0};
	for (int n{1}; n <= 100; n++) {
		for (int r{0}; r*2 <= n; r++) {
			long long int res{comb(n,r)};
			if (res > 1000000) {
				if (r*2 == n) {
					count++;
				} else { // after first value > 1000000 all values of r closer to n/2 will also be > 1000000 and as symmetrical *2
					if (n%2 == 0) { // if n is even
						count += ((n/2 - r)*2 +1);
					} else {
						count += ((n/2 - r +1)*2);
					}
				}
				break;
			}
		}
	}

	std::cout << count << '\n';

	return 0;
}

