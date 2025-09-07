#include <iostream>
#include <unordered_set>
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
	std::vector<bool> primes(1000000, true);
	generatePrimes(primes);
	//printPrimes(primes);

	size_t maxLen{0};
	size_t maxSumPrime{0};
	// iterate through primes to start sequence from
	for (size_t start{2}; start < primes.size(); start++) {
		if (primes[start]) {
			
			size_t sum{start};
			size_t length{1};
			// add consecutive primes to sum
			for (size_t nextPrime{start+1}; sum+nextPrime < primes.size(); nextPrime++) {
				if (primes[nextPrime]) {
					sum += nextPrime;
					length++;

					// check if sum is prime
					if (primes[sum]) {
						if (length > maxLen) {
							maxLen = length;
							maxSumPrime = sum;
						}
					}
				}
			}
		}
	}

	std::cout << maxSumPrime << '\n';

	return 0;
}
