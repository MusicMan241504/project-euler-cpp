#include <iostream>
int getDigitN(int n) {
	// 1-9 = 1 digit = 9 nums = total 9 digits
	// 10-99 = 2 digit = 90 nums = total 180 digits
	// 100-999 = 3 digit = 900 nums = total 2700 digits
	

	int numDigits{1};
	int numNums{9}; // numbers already passed
	int numTotalDigits{numDigits*numNums}; // digits already passed
	int startingNum{0};
	while (n > numTotalDigits) {
		startingNum += numNums;

		n -= numTotalDigits;


		numNums = numNums*10;
		numDigits++;
		numTotalDigits = numDigits*numNums;




	}
	//std::cout << numDigits << ' ' << startingNum << ' ' << n << '\n';

	// find nth digit in numbers with numDigits number of digits
	
	// find num that this digit will be in
	int num {n/numDigits + startingNum};
	if (n%numDigits != 0) {
		num++;
	}
	while (n%numDigits != 0) {
		n++;
		num /=10;
	}
	return num%10;
}


	int main() {


		int ans{1};
		for (int n{1}; n<=1000000; n*=10) {
			ans *= getDigitN(n);
		}

		std::cout << ans << '\n';


		return 0;
	}
