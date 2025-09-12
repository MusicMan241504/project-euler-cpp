#include <iostream>
#include <vector>

// multiply num1 by num2 (num1 is stored with least significant digit first)
void mult(std::vector<int>& num1, int num2) {
	int carry{0};
	for (size_t i{0}; i < num1.size(); i++) {
		int res{num1[i] * num2 + carry};
		num1[i] = res%10;
		carry = res/10;
	}
}

void num2Vec(std::vector<int>& numVec, int num) {
	for (size_t i{0}; num > 0; i++) {
		numVec[i] = num%10;
		num = num / 10;
	}
}

void pow(std::vector<int>& num, int a, int b) {
	num2Vec(num, a);
	for (int i{1}; i < b; i++) {
		mult(num, a);
	}
}

void printVec(std::vector<int>& num) {
	for (size_t i{0}; i < num.size(); i++) {
		std::cout << num[num.size()-i-1];
	}
	std::cout << '\n';
}

int digitSum(std::vector<int>& num) {
	int sum{0};
	for (auto digit : num) {
		sum += digit;
	}
	return sum;
}

int main() {
	int maxSum{0};
	for (int a{1}; a < 100; a++) {
		for (int b{1}; b < 100; b++) {
			std::vector<int> num(200,0);
			pow(num, a, b);
			int sum{digitSum(num)};
			if (sum > maxSum) {
				maxSum = sum;
			}
		}
	}
	std::cout << maxSum << '\n';

	return 0;
}
