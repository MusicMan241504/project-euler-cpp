#include <iostream>
#include <vector>


void printPrimes(std::vector<bool>& nums) {
        for (size_t i{2}; i < nums.size(); i++) {
                if (nums[i]) {
                        std::cout << i << '\n';
                }
        }
}

bool isPandigital(int num) {
	std::vector<int> digitsArr(10,0);

	size_t digitCount {0};
	// enumerate array
	for (; num>0; num/=10) {
		digitCount++;
		if (num%10 == 0) {
			return 0;
		} else {
			digitsArr[num%10]++;
		}
	}
	for (size_t i{1}; i <= digitCount; i++) {
		if (digitsArr[i] != 1) {
			return 0;
		}
	}
	return 1;
}


int main() {
	// can be max 7 digits long as sum of all 9 digits is 45 so multiple of 3 and sum of digits 1-8 is 36 so multiple of 3
	std::vector<bool> isPrimeArr(7654321+1,1);
	for (size_t i{2}; i*i <= isPrimeArr.size(); i++) {
		if (isPrimeArr[i]) { // if not crossed out
			for (size_t j{i*i}; j <= isPrimeArr.size(); j+=i) {
				isPrimeArr[j] = 0;
			}
		}
	}

	//printPrimes(isPrimeArr);
	
	for (size_t i{isPrimeArr.size()}; i >= 2; i--) {
		if (isPrimeArr[i] && isPandigital(i)) {
			std::cout << i << '\n';
			break;
		}
	}


	return 0;
}
