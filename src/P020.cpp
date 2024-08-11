#include <iostream>
#include <vector>

void mult(std::vector<int>& num, int num2) {
	int carry {0};
	for (size_t i {num.size()}; i>0; i--) {
		// Use index i-1
		int ans {num[i-1]*num2 + carry};
		num[i-1] = ans % 10;
		carry = ans / 10;
	}
}

void print(std::vector<int>& num) {
	for (const auto digit : num) {
		std::cout << digit;
	}
	std::cout << '\n';
}

int sumDigits(std::vector<int>& num) {
	int total {0};
	for (const auto digit : num) {
		total += digit;
	}
	return total;
}

int main() {
	std::vector<int> num (200,0);

	num[num.size()-1] = 1;

	for (size_t i{2}; i<=100; i++) {
		mult(num, i);
	}

	//print(num);

	std::cout << sumDigits(num) << '\n';
	

	return 0;
}
