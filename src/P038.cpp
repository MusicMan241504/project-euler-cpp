#include <cstdint>
#include <unordered_set>
#include <iostream>
int multConcat(int num, int n) {
	// return answer if is pandigital
	// return 0 if num has too many digits
	// otherwise return 1




	// calculate num * (1,2,3,4,...,n) concatenated
	
	std::unordered_set<uint8_t> digitSet;
	int digitCount {0};
	int ans{0};
	for (int i{1}; i<=n; i++) {
		int tmpNum{num*i};
		for (; tmpNum > 0; tmpNum=tmpNum/10) {
			//std::cout << tmpNum%10 << '\n';
			if (tmpNum%10 != 0) {
				digitSet.insert(tmpNum%10);
			}
			digitCount++;
			ans *= 10;
			if (digitCount > 9) {
				return 0;
			}
		}
		ans = ans + num*i;
	}
	if (digitCount == 9 && digitSet.size() == 9) {
		// return answer
		return ans;


	}
	return 1;
}



int main() {
	int maxPan{0};


	for (int num{1}; num < 9999; num++) {
		for (int n{2}; n <= 9; n++) {
			int res {multConcat(num,n)};
			if (res == 0) {
				break;
			} else if (res != 1 && res > maxPan) {
				maxPan = res;
			}
		}
	}

	std::cout << maxPan << '\n';

		



	return 0;
}
