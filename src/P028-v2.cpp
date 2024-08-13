#include <iostream>

int main() {
	int total{1};
	for (int i{3}; i<1002; i=i+2) {
		total += (4*i*i - 6*i + 6);
	}
	std::cout << total << '\n';
	return 0;
}
