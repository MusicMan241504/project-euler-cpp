#include <fstream>
#include <iostream>
#include <vector>


int main() {


	// Create input file stream
	std::ifstream input{"P067.txt"};



	std::vector<std::vector<int>> triangle;


	// Read file into array
	for (size_t i{0}; i<=99; i++) { // row
		triangle.push_back(std::vector<int>(i+1));
		for (size_t j{0}; j<=i; j++) { // column

			if (input) {
				int tmp{};
				input >> tmp;
				triangle[i][j] = tmp;

			}
		}
	}
	

	// Start at bottom row and add largest pair of values to matching value in row above
	for (size_t i{99}; i>=1; i--) { // iterate one less than all items
		for (size_t j{0}; j<=i-1; j++) { // iterate one less than all items
			if (triangle[i][j] > triangle[i][j+1]) {
				// update value above-right using index from this traingle
				//      0
				//     0 1
				//    0 1 2
				//   0 1 2 3
				triangle[i-1][j] += triangle[i][j];
			} else {
				triangle[i-1][j] += triangle[i][j+1];
			}
		}
	}

	std::cout << triangle[0][0] << '\n';






	return 0;
}
