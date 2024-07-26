#include <array>
#include <iostream>
int main() {
	const int maxI {1000000};
	bool isPrime {false};
	std::array<int,maxI> primes;
	int num = 2;
	primes[0] = num;
	int i {0};
	while (i < maxI ){
		isPrime = true;
		for (int j=0; primes[j]*primes[j]<=num; j++) {
			if(num%primes[j] == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime){
			primes[i] = num;
			i++;
		}
		num++;
	}
	std::cout << primes[i-1] << '\n';
}
