#include <iostream>
int sumOfProperDivisors(int num) {
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
	return total;
}




int main() {
	int total {0};
	for (int num1{2}; num1<10000; num1++) {
		int num2 {sumOfProperDivisors(num1)};
		if ( num1 < num2 && num1 == sumOfProperDivisors(num2)) {
			total += (num1 + num2);
		}
	}
	std::cout << total << '\n';
	return 0;
}
