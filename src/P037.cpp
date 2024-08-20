#include <cmath>
#include <stack>
#include <iostream>

bool isPrime(int num) {
	if (num < 2) {
		return 0;
	}
	for (int i{2}; i*i<=num; i++) {
		if (num%i == 0) {
			return 0;
		}
	}
	return 1;
}

bool isLeftTruncatablePrime(int num) {

	for (int mod{10}; mod < num; mod *=10) {
		if (!isPrime(num%mod)) {
			return 0;
		}
	}
	return 1;
}


int main() {

	std::stack<int> numStack {};
	numStack.push(2);
	numStack.push(3);
	numStack.push(5);
	numStack.push(7);

	// generate right truncatable primes and check if is prime
	// For each right truncatable prime check if is left truncatable prime

	int total {-2-3-5-7};
	while (!numStack.empty()) {
		int num {numStack.top()};
		numStack.pop();

		//check if prime
		if (isPrime(num)) {
			if (isLeftTruncatablePrime(num)) {
				//std::cout << num << '\n';
				total += num;
			}

			// Add next numbers to stack as all primes > 5 end in these digits
			numStack.push(num*10+1);
			numStack.push(num*10+3);
			numStack.push(num*10+7);
			numStack.push(num*10+9);
		}
	}
	std::cout << total << '\n';

	return 0;
}
