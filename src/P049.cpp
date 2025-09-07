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


void generatePrimePerms(std::vector<bool>& primes, std::unordered_set<int>& res, std::vector<int>& numArr, size_t idx) {
	// base case
	if (idx == 3) {
		int num{numArr[0]*1000 + numArr[1]*100 + numArr[2]*10 + numArr[3]};
		if (primes[num]) {
			res.insert(num);
		}
		return;
	}


	auto fixedDigit{numArr[idx]};
	for (size_t i{idx}; i < numArr.size(); i++) {
		// swap
		numArr[idx] = numArr[i];
		numArr[i] = fixedDigit;


		generatePrimePerms(primes, res, numArr, idx+1);

		// swap back
		numArr[i] = numArr[idx];
		numArr[idx] = fixedDigit;
	}
}

int main() {
	// generate primes
	std::vector<bool> primes(10000, true);
	generatePrimes(primes);
	//printPrimes(primes);

	// iterate through primes
	for (size_t num{2}; num < primes.size(); num++) {
		if (primes[num]) {

			std::vector<int> numArr(4);
			numArr[0] = num/1000;
			numArr[1] = (num/100)%10;
			numArr[2] = (num/10)%10;
			numArr[3] = num%10;

			std::unordered_set<int> res;
			generatePrimePerms(primes, res, numArr, 0);

			// find sequence
			for (int diff{1}; diff < 10000; diff++) {
				if (res.find(num+diff) != res.end() && res.find(num+2*diff) != res.end()) {
					std::cout << num << num+diff << num+2*diff << '\n';
				}
			}
		}
	}


	return 0;
}
