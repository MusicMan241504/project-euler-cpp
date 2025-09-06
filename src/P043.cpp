#include <iostream>
#include <vector>


bool isPanDigital(long long int num) {
	std::vector<bool> digits(10);
	// check what digits are in num
	for (int i{0}; i < 10; i++) {
		int digit{static_cast<int>(num%10)};
		num = num/10;
		digits[digit] = 1;
	}

	// check if vector is all true
	for (bool digit : digits) {
		if (!digit) {
			return 0;
		}
	}
	return 1;
}

int main() {
	long long int total{0};
	// multiples of 17
	for (int d17{17}; d17 < 1000; d17+=17) {


		// multiples of 13
		for (int d13{13}; d13 < 1000; d13+=13) {
			// if last 2 digits not same as first 2 of previous multiple continue
			if (d13%100 != d17/10) {
				continue;
			}


			// multiples of 11
			for (int d11{11}; d11 < 1000; d11+=11) {
				// if last 2 digits not same as first 2 of previous multiple continue
				if (d11%100 != d13/10) {
					continue;
				}


				// multiples of 7
				for (int d7{7}; d7 < 1000; d7+=7) {
					// if last 2 digits not same as first 2 of previous multiple continue
					if (d7%100 != d11/10) {
						continue;
					}


					// multiples of 5
					for (int d5{5}; d5 < 1000; d5+=5) {
						// if last 2 digits not same as first 2 of previous multiple continue
						if (d5%100 != d7/10) {
							continue;
						}


						// multiples of 3
						for (int d3{3}; d3 < 1000; d3+=3) {
							// if last 2 digits not same as first 2 of previous multiple continue
							if (d3%100 != d5/10) {
								continue;
							}


							// multiples of 2
							for (int d2{2}; d2 < 1000; d2+=2) {
								// if last 2 digits not same as first 2 of previous multiple continue
								if (d2%100 != d3/10) {
									continue;
								}

								// first digit
								for (long long int d1{1}; d1 < 10; d1++) {
									long long int num{
										d1*1000000000 +
											d2*1000000 +
											d3%10*100000 +
											d5%10*10000 +
											d7%10*1000 +
											d11%10*100 +
											d13%10*10 +
											d17%10};

									if (isPanDigital(num)) {
										total += num;
										//std::cout << num << '\n';
									}
									//std::cout << d1 << d2 << d3%10 << d5%10 << d7%10 << d11%10 << d13%10 << d17%10 << '\n';
								}
							}
						}
					}
				}
			}
		}
	}


	std::cout << total << '\n';


	return 0;
}

