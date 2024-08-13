#include <cmath>
#include <iostream>
bool isSum5(int num) {
	int tmpNum {num};
	int total {0};
	while (tmpNum != 0){
		total += std::pow(tmpNum%10,5);
		tmpNum = tmpNum/10;
	}
	if (total == num) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	int total {0};
	// Highest 6 digit num is 999999 which would be 6*9^5 = 354294 so all numbers must be less than this
	for (int i{10}; i < 999999; i++) {
		if (isSum5(i)) {
			total +=i;
			//std::cout << i << '\n';
		}
	}
	std::cout << total << '\n';

	return 0;
}

