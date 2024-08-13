#include <iostream>
#include <vector>
bool isPrime (int num) {
	if (num < 0) {
		return 0;
	}
	for (int i{2}; i*i <= num; i++) {
		if (num % i == 0) { // if divides
			return 0;
		}
	}
	return 1;
}





int main() {
	
	int maxLen{0};
	int maxAB{0}; // Max product of a*b
	for (int a{-999}; a<1000; a++) {
		for (int b{-999}; b<1000; b++) {
			int n{0};
			for (; isPrime(n*n + a*n + b); n++);
			if (n > maxLen) {
				maxLen = n;
				maxAB = a*b;
			}
		}
	}

	std::cout << maxAB << '\n';

	return 0;
}
