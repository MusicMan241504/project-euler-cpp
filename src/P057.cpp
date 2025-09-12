#include <iostream>
#include <vector>

void add(std::vector<int>& num1, std::vector<int>& num2) {
	// make vectors same size
	while (num1.size() > num2.size()) {
		num2.push_back(0);
	}

	while (num2.size() > num1.size()) {
		num1.push_back(0);
	}

	int carry{0};
	for (size_t i{0}; i < num1.size(); i++) {
		int res{num1[i] + num2[i] + carry};
		num1[i] = res%10;
		carry = res/10;
	}
	while (carry > 0) {
		num1.push_back(carry%10);
		carry = carry/10;
	}
}

void mult(std::vector<int>& num1, int num2) {
	int carry{0};
	for (size_t i{0}; i < num1.size(); i++) {
		int res{num1[i] * num2 + carry};
		num1[i] = res%10;
		carry = res/10;
	}
	while (carry > 0) {
		num1.push_back(carry%10);
		carry = carry/10;
	}
}

class Fraction {

	public:
		std::vector<int>* numer;
		std::vector<int>* denom;

		Fraction(std::vector<int>* numerP, std::vector<int>* denomP) {
			numer = numerP;
			denom = denomP;
		}

		void reciprocate() {
			auto tmp{numer};
			numer = denom;
			denom = tmp;
		}

		void addInt(int num) {
			// calculate num*denom
			std::vector<int> res{*denom};
			mult(res, num);
			add(*numer, res);
		}


		void print() {
			for (size_t i{0}; i < numer->size(); i++) {
				std::cout << (*numer)[numer->size()-i-1];
			}
			std::cout << '\n';
			for (size_t i{0}; i < numer->size(); i++) {
				std::cout << '-';
			}
			std::cout << '\n';
			for (size_t i{0}; i < denom->size(); i++) {
				std::cout << (*denom)[denom->size()-i-1];
			}
			std::cout << "\n\n";
		}
};

int main() {
	int count{0};
	std::vector<int> num1{1};
	std::vector<int> num2{2};
	Fraction frac(&num1, &num2);
	for (int i{1}; i < 1000; i++) {
		frac.addInt(2);
		frac.reciprocate();

		// temporarily add one and check digits
		std::vector<int> newNumer{*frac.numer};
		Fraction newFrac{&newNumer, frac.denom};
		newFrac.addInt(1);

		if (newFrac.numer->size() > newFrac.denom->size()) {
			count++;
		}
		//newFrac.print();
	}
	std::cout << count << '\n';

	return 0;
}
