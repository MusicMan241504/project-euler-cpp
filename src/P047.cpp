#include <iostream>
#include <vector>


void generatePrimes(std::vector<int>& primes) {
	for (size_t i{2}; i*i < primes.size(); i++) {
		if (primes[i] == 0) {
			for (size_t j{i*2}; j < primes.size(); j+=i) {
				primes[j]++;
			}
		}
	}

}

void printPrimes(std::vector<int>& primes) {
	for (size_t i{2}; i < primes.size(); i++) {
		if (primes[i] == 0) {
			std::cout << i << '\n';
		}
	}
}

int main() {
	// generate primes
	std::vector<int> primes(1000000, 0);
	generatePrimes(primes);
	//printPrimes(primes);
	
	// get numbers with 4 prime factors
	int numCount{0};
	for (size_t i{2}; i < primes.size(); i++) {
		if (primes[i] == 4) {
			numCount++;
			//std::cout << i << '\n';
		} else {
			numCount = 0;
		}
		if (numCount == 4) {
			std::cout << i-3 << '\n';
			break;
		}
	}


	return 0;
}
