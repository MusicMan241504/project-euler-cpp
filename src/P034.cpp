#include <iostream>
#include <vector>
int factorial(int n) {
	int ans {1};
	for (int i{1}; i <=n; i++) {
		ans *=i;
	}
	return ans;
}

int main() {
	int total {0};
	// calculate factorials before
	std::vector<int> factorials(10);
	for (size_t i{0}; i < 10; i++) {
		factorials[i] = factorial(i);
	}

	for (int i{10}; i<=9999999; i++) {
		int sum{0};
		int tmp{i};
		for (; tmp > 0; tmp=tmp/10) {
			sum += factorials[tmp%10];
		}
		if (sum == i) {
			//std::cout << i << '\n';
			total += i;
		}
	}
	std::cout << total << '\n';

	return 0;
}
