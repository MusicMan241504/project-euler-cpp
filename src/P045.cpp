#include <iostream>
#include <unordered_set>

long long int triNum(long int n) {
	return n*(n+1)/2;
}

long long int pentNum(long int n) {
	return n*(3*n-1)/2;
}

long long int hexNum(long int n) {
	return n*(2*n-1);
}

int main() {
	std::unordered_set<long long int> tris;
	std::unordered_set<long long int> pents;
	std::unordered_set<long long int> hexs;

	// generate numbers
	for (int i{1}; i < 100000; i++) {
		tris.insert(triNum(i));
		pents.insert(pentNum(i));
		hexs.insert(hexNum(i));
	}


	// check for matches
	for (long long int num : tris) {
		if (pents.find(num) != pents.end() && hexs.find(num) != hexs.end()) {
			std::cout << num << '\n';
		}
	}


	return 0;
}
