#include <iostream>
#include <string>
#include <unordered_set>
#include <fstream>
bool isTriangleWord(std::string word, std::unordered_set<int>& triangleNums) {
	int total {0};
	for (const char& c : word) {
		total += int(c)-64; // A has ASCII 65
	}
	// check if total is triangle number
	if (triangleNums.find(total) != triangleNums.end()) { // if is triangle num
		return 1;
	} else {
		return 0;
	}
	
}


int main() {
	// generate 32 triangle numbers as no words longer than 20 letters and 26 * 20 = 520 < 528 = 33rd triangle number
	
	// use hash table as has constant time lookup
	std::unordered_set<int> triangleNums;
	for (size_t n{1}; n < 33; n++) {
		triangleNums.insert((n*(n+1))/2);
	}

	int count {0};

	std::ifstream input{"P042_words.txt"};
	while (input) {
		std::string word;
		std::getline(input, word, ',');
		if (word != "") { // if not empty
			// remove double quotes
			if (isTriangleWord(word.substr(1,word.size()-2), triangleNums)) {
				count++;
				//std::cout << word << '\n';
			}
		}
	}

	std::cout << count << '\n';



	return 0;
}
