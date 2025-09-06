#include <iostream>
#include <vector>


void generatePrimes(std::vector<bool>& primes) {
	for (size_t i{2}; i*i < primes.size(); i++) {
		if (primes[i]) {
			for (size_t j{i*2}; j < primes.size(); j+=i) {
				primes[j] = false;
			}
		}
	}

}

void printPrimes(std::vector<bool>& primes) {
	for (size_t i{2}; i < primes.size(); i++) {
		if (primes[i]) {
			std::cout << i << '\n';
		}
	}
}

int main() {
	// generate primes
	std::vector<bool> primes(1000*1000, true);
	generatePrimes(primes);
	//printPrimes(primes);

	// iterate through odd composite numbers
	for (size_t num{3}; num < primes.size(); num+=2) {
		if (!primes[num]) {
			//std::cout << num << '\n';

			// attempt to write as sum of prime and 2x square
			bool flag{false};
			// iterate through primes
			for (size_t i{2}; !flag && i < num; i++) {
				if (primes[i]) {
					// iterate through squares
					for (size_t j{1}; i+2*j*j <= num; j++) {
						if (i+2*j*j == num) {
							flag = true;
							break;
						}
					}
				}
			}
			if (!flag) {
				std::cout << num << '\n';
				break;
			}
		}
	}


	return 0;
}
