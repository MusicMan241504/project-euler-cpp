#include <iostream>

bool isCurious(int num, int den) {
	if ((num%10) == (den/10)) {
		if ((num/10) * den == num * (den%10)) {
			return 1;
		}
	}
	return 0;
}

int main() {
	int numProduct {1};
	int denProduct {1};
	
	for (int a{10}; a<100; a++) {
		for (int b{a+1}; b<100; b++) {
			if (isCurious(a,b)) {
				numProduct *= a;
				denProduct *= b;
				std::cout << a << ' ' << b << '\n';
			}
		}
	}

	double ans {static_cast<double>(numProduct)/denProduct};
	std::cout << ans << " = 1/" << 1.0/ans << '\n';

	return 0;
}
