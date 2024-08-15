#include <cstdint>
#include <iostream>
#include <vector>


bool isPalindrome(int num) {
	// decimal
	int num2{num};
	int num3{0};
	for (; num2>0; num2=num2/10) {
		num3 = num3*10 + num2%10;
	}
	if (num3 != num) {
		return false;
	}

	// binary
	
	// convert to binary
	std::vector<uint8_t> binNum;
	for (; num>0; num=num/2) {
		binNum.push_back(num%2);
	}
	// check binary
	for (size_t i{0}; i<binNum.size(); i++) {
		if (binNum[i] != binNum[binNum.size()-i-1]) {
			return false;
		}
	}
	return true;
}


int main() {
	int total {0};
	for (int num{0}; num<1000000; num++) {
		if (isPalindrome(num)) {
			total+=num;
		}
	}
	std::cout << total << '\n';



	return 0;
}
