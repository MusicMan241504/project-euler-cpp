#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
int main() {

	std::ifstream input{"P022_names.txt"};
	std::vector<std::string> names{};
	while (input) {
		std::string line;
		std::getline(input, line, ',');
		if (line != "") {
			names.push_back(line.substr(1,line.size()-2));
		}
	}

	std::sort(names.begin(), names.end());
	
	int total {0};
	for (size_t i{0}; i < names.size(); i++) {
		int alphaVal{0};
		for (auto ch : names[i]) {
			alphaVal += (int(ch)-64); // A has ASCI 65
		}
		total += (alphaVal*(i+1));
	}

	std::cout << total << '\n';

	return 0;
}
