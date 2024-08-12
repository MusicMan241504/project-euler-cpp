#include <iostream>
#include <vector>


// Add num2 to num1
void add(std::vector<size_t>& num1, std::vector<size_t>& num2) {
	size_t carry{0};
	for (size_t i{num1.size()}; i>0; i--) {
		size_t ans {num1[i-1] + num2[i-1] + carry};
		num1[i-1] = ans % 10;
		carry = ans / 10;
	}
}

template <typename T>
void printNum(T& num) {
	for (const auto digit : num) {
		std::cout << digit;
	}
	std::cout << '\n';
}

int main() {
	std::vector<size_t> num1(1000,0);
	std::vector<size_t> num2(1000,0);


	// Set both nums to 1
	num1[num1.size()-1] = 1;
	num2[num2.size()-1] = 1;

	bool add2num1 {1};
	int count {2};
	while (num1[0] == 0 && num2[0] == 0) {
		if (add2num1) {
			add(num1,num2);
		} else {
			add(num2,num1);
		}
		add2num1 = !add2num1;
		count++;
	}


	add(num1,num2);
	std::cout << count << '\n';




	return 0;
}
