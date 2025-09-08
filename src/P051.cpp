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

// converts number to a vector 
void num2Vector(std::vector<size_t>& numVec, size_t num) {
	while (num > 0) {
		numVec.insert(numVec.begin(), num%10);
		num = num/10;
	}
}

size_t vec2Num(std::vector<size_t>& numVec) {
	size_t num{0};
	for (const auto d : numVec) {
		num *= 10;
		num += d;
	}
	return num;
}

void printBoolVec(std::vector<bool>& vec) {
	for (const auto e : vec) {
		std::cout << e;
	}
	std::cout << '\n';
}

void printVec(std::vector<size_t>& vec) {
	for (const auto e : vec) {
		std::cout << e;
	}
	std::cout << '\n';
}

bool nextReplacementIndex(std::vector<bool>& replaceIndexes) {
	bool carry{true};
	for (size_t i{0}; i < replaceIndexes.size(); i++) {
		if (carry) {
			if (!replaceIndexes[i]) {
				replaceIndexes[i] = true;
				carry = false;
			} else {
				replaceIndexes[i] = false;
			}
		}
	}
	return carry;
}

int generateReplacements(std::vector<bool>& primes, std::vector<size_t> numVec, std::vector<bool>& replaceIndexes) {
	size_t originalNum{vec2Num(numVec)};
	bool isFoundLowest{false};
	int familyCount{0};
	// for digits 0 to 9
	for (size_t i{0}; i < 10; i++) {
		// replace for each replacing digit
		for (size_t j{0}; j < replaceIndexes.size(); j++) {
			if (replaceIndexes[j]) {
				numVec[j] = i;
			}
		}
		
		// not valid if starting with 0
		if (numVec[0] == 0) {
			continue;
		}

		
		size_t num{vec2Num(numVec)};


		// check if prime
		if (primes[num]) {
			if (!isFoundLowest && num > originalNum) {
				break;
			}
			isFoundLowest = true;
			familyCount++;
		}

	}
	return familyCount;
}

int generateReplacementIndexes(std::vector<bool>& primes, std::vector<size_t>& num, std::vector<bool>& replaceIndexes) {
	int maxCount{0};
	bool carry{false};
	while (!carry) {
		int count{generateReplacements(primes, num, replaceIndexes)};
		if (count > maxCount) {
			maxCount = count;
		}
		carry = nextReplacementIndex(replaceIndexes);
	}
	return maxCount;
}


int main() {
	// generate primes
	std::vector<bool> primes(1000000, true);
	generatePrimes(primes);
	//printPrimes(primes);

	// iterate through primes
	for (size_t num{2}; num < primes.size(); num++) {
		if (primes[num]) {
			int countPrimes{1};

			// generate replacements
			std::vector<size_t> numVec;
			num2Vector(numVec, num);
			std::vector<bool> replaceIndexes(numVec.size(),0);
			replaceIndexes[0] = true;
			countPrimes = generateReplacementIndexes(primes, numVec, replaceIndexes);
			if (countPrimes >= 8) {
				std::cout << num << '\n';
				break;
			}
		}
	}


	return 0;
}
