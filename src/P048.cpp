#include <iostream>
#include <vector>

// all numbers stored in vectors with most significant digit first

void printVector(std::vector<int>& num) {
	for (int digit : num) {
		std::cout << digit;
	}
	std::cout << '\n';
}


// adds num2 to num1
void add(std::vector<int>& num1, std::vector<int>& num2) {
	int carry{0};
	for (size_t i{0}; i < 10; i++) {
		int sum{num1[9-i] + num2[9-i] + carry};
		num1[9-i] = sum%10;
		carry = sum/10;
	}
}

// multiplies num1 by num2
void mult(std::vector<int>& num1, int num2) {
	int carry{0};
	for (size_t i{0}; i < 10; i++) {
		int res{num1[9-i]*num2+carry};
		num1[9-i] = res%10;
		carry = res/10;
	}
}


// calculates the last 10 digits of n^n
void power(std::vector<int>& num, int n) {
	// initialize vector with value 1
	num[9] = 1;

	// calculate power
	for (int i{0}; i < n; i++) {
		mult(num, n);
	}
}

int main() {
	std::vector<int> total(10,0);
	for (int i{1}; i <=1000; i++) {
		std::vector<int> num(10,0);
		power(num,i);
		add(total,num);
	}
	printVector(total);

	return 0;
}



