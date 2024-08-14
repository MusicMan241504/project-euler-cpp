#include <cmath>
#include <vector>
#include <iostream>


void printPrimes(std::vector<bool>& nums, int maxN) {
	for (int i{2}; i <= maxN; i++) {
		if (nums[i-2]) {
			std::cout << i << '\n';
		}
	}
}

int rotateNum(int num) {
	int noDigits{0};
	int ans{num};
	for (; num>0; num=num/10) {
		noDigits++;
	}
	ans = ans/10 + (ans%10)*std::pow(10,noDigits-1);
	return ans;
}


int main() {
	int maxN {1000000};
	std::vector<bool> nums(maxN-1,1); // if false is crossed out and cannot be prime
					  // if true may be prime
	for (int i{2}; i*i< maxN; i++) {
		if (nums[i-2]) { // if not crossed out

			// cross out multiples
			for (int j{i*i}; j <= maxN; j+=i) {
				nums[j-2] = 0;
			}
		}
	}


	int count{0};
	for (int num{2}; num <= maxN; num++) {
		bool isCircularPrime {1};
		int tmpNum {num};
		do {
			if (!nums[tmpNum-2]) { // if not prime
				isCircularPrime = 0;
				break;
			}
			tmpNum = rotateNum(tmpNum);
		} while (tmpNum != num);
		if (isCircularPrime) {
			count++;
			//std::cout << num << '\n';
		}

	}

	std::cout << count << '\n';



	return 0;
}
