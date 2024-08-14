#include <vector>
#include <iostream>

void printArr(std::vector<int>& arr) {
	for (const auto& e : arr) {
		std::cout << e << ' ';
	}
	std::cout << '\n';
}

int main() {
	std::vector<int> coinValues {1,2,5,10,20,50,100,200};


	// array to store number of ways to get x amount
	std::vector<int> arr(201);
	arr[0] = 1;


	// After each iteration the array contains correct values for how to make each amount using one more coin for each iteration
	for (int coin : coinValues) {
		for (int i{coin}; i < 201; i++) {
			arr[i] += arr[i-coin];
		}
		//printArr(arr);
	}


	std::cout << arr[200] << '\n';
}
