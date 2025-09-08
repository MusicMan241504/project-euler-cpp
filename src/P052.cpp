#include <iostream>
#include <vector>


bool isPermutation(size_t num1, size_t num2) {
	std::vector<int> digitCount1(10,0);
	std::vector<int> digitCount2(10,0);

	while (num1 > 0) {
		size_t digit{num1%10};
		digitCount1[digit]++;
		num1 /= 10;
	}
	while (num2 > 0) {
		size_t digit{num2%10};
		digitCount2[digit]++;
		num2 /= 10;
	}

	for (size_t i{0}; i < 10; i++) {
		if (digitCount1[i] != digitCount2[i]) {
			return false;
		}
	}
	return true;

}

int main() {
	for (size_t num1{1}; ; num1++) {
		bool isPerm{true};
		for (size_t num2{num1*2}; num2 <= num1*6; num2+=num1) {
			if (!isPermutation(num1, num2)) {
				isPerm = false;
				break;
			}
		}
		if (isPerm) {
			std::cout << num1 << '\n';
			break;
		}
	}


	return 0;
}
