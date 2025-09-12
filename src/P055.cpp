#include <iostream>
#include <vector>

// adds num2 to num1 (stores least significant digit first)
void add(std::vector<int>& num1, std::vector<int>& num2) {
	int carry{0};
	for (size_t i{0}; i < num1.size(); i++) {
		int sum{num1[i] + num2[i] + carry};
		num1[i] = sum%10;
		carry = sum/10;
	}
	if (carry != 0) {
		num1.push_back(carry);
		num2.push_back(0); // ensure num1 and num2 are both same size
	}
}

// check if number is palindrome
bool isPalindrome(std::vector<int>& num) {
	for (size_t i{0}; i*2+1 < num.size(); i++) {
		if (num[i] != num[num.size()-i-1]) {
			return false;
		}
	}
	return true;
}

// store reverse of num1 as num2
void reverse(std::vector<int>& num1, std::vector<int>& num2) {
	for (size_t i{0}; i < num1.size(); i++) {
		num2[num1.size()-i-1] = num1[i];
	}
}

void printNum(std::vector<int>& num) {
	for (size_t i{0}; i < num.size(); i++) {
		std::cout << num[num.size()-i-1];
	}
	std::cout << '\n';
}

std::vector<int> num2Vec(int num) {
	std::vector<int> numVec;
	while (num > 0) {
		numVec.push_back(num%10);
		num = num/10;
	}
	return numVec;
}

int main() {
	int count{0};
	for (int num{1}; num < 10000; num++) {
		bool isLychrel{true};
		std::vector<int> num1{num2Vec(num)};
		std::vector<int> num2(num1.size());
		for (int i{0}; i < 50; i++) {
			reverse(num1, num2);
			add(num1, num2);
			//printNum(num1);
			if (isPalindrome(num1)) {
				isLychrel = false;
				break;
			}
		}
		if (isLychrel) {
			//std::cout << num << '\n';
			count++;
		}
	}

	std::cout << count << '\n';
	return 0;
}
