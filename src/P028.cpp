#include <iostream>
#include <vector>

template <typename T>
void printGrid(T& grid) {
	for (const auto& row : grid) {
		for (const auto& e : row) {
			std::cout << e << ' ';
		}
		std::cout << '\n';
	}
}




int main() {

	std::vector<std::vector<int>> grid(1001, std::vector<int> (1001, 0));
	// grid[row][column] starting in top left

	std::vector<int> coord {500,500}; // row,col
	std::vector<int> direction {1,0}; // {x,y} as a vector



	int counter{1};
	// Mark first coord
	grid[coord[0]][coord[1]] = counter;
	counter++;

	for (int moveDistance{1}; moveDistance < 1002; moveDistance++) {
		// if last iteration must only perform 1 not to sides and one less distance
		int lastTime{0};
		if (moveDistance == 1001) {
			lastTime = 1;
		}
		for (int i{0}; i<2-lastTime; i++) { // move each distance 2 times
		
	
			// move correct distance
			for (int j{0}; j<moveDistance-lastTime; j++) {
				coord[0] += direction[1];
				coord[1] += direction[0];
				grid[coord[0]][coord[1]] = counter;
				counter++;
			}
			//printGrid(grid);

			// rotate direction
			if (direction[0] == 1 && direction[1] == 0) { // right -> down
				direction = {0,1};
			} else if (direction[0] == 0 && direction[1] == 1) { //down -> left
				direction = {-1,0};
			} else if (direction[0] == -1 && direction[1] == 0) { // left -> up
				direction = {0,-1};
			} else if (direction[0] == 0 && direction[1] == -1) { // up -> right
				direction = {1,0};
			}
		}
	}





	// Total diagonals
	int total{0};
	for (int i{0}; i<1001; i++) {
		total += (grid[i][i] + grid[i][1000-i]);
	}
	total--; // Subtract 1 as will have been counted twice

	std::cout << total << '\n';

	return 0;
}
