#include <iostream>
#include <vector>

int calcRecurringReciprocol(int d) {
	int remaining {10};
	std::vector<int> remainingList {10};
	for (int i{1}; ; i++) {
		//std::cout << remaining /d;
		remaining = (remaining%d)*10;
		if (remaining == 0) {
			return 0;
		} else { // Linear search to find element in remainingList
			for (size_t j{0}; j<remainingList.size(); j++) {
				if (remainingList[j] == remaining) {
					return i-j;
				}
			}
		}
		remainingList.push_back(remaining);
	}
}
	




int main() {
	int maxRecurring {0};
	int maxD {0};
	for (int d{2}; d<1000; d++) {
		auto ans {calcRecurringReciprocol(d)};
		if (ans > maxRecurring) {
			maxRecurring = ans;
			maxD = d;
		}
	}


	std::cout << maxD << '\n';




	return 0;
}
