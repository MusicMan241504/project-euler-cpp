#include <iostream>
#include <vector>


void generatePrimes(std::vector<bool>& primes) {
	for (size_t i{2}; i*i < primes.size(); i++) {
		if (primes[i]) {
			for (size_t j{i*i}; j < primes.size(); j+=i) {
				primes[j] = false;
			}
		}
	}
}

int main() {
	std::vector<bool> primes(1000000000,true);
	generatePrimes(primes);

	long int cornerCount{1};
	long int primeCount{0};

	size_t num{1};
	for (size_t i{2}; ; i+=2) { // side length = i+1
		for (int j{0}; j < 4; j++) {
			num += i;
			//std::cout << num << '\n';

			cornerCount++;
			if (primes[num]) {
				primeCount++;
			}
		}
		//std::cout << primeCount << ' ' << cornerCount << ' ' << i+1 << '\n';

		if (primeCount * 10 < cornerCount ) {
			std::cout << i+1 << '\n';
			break;
		}
	}

	return 0;
}
