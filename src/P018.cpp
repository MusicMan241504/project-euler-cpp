// NOTE
// This was a bad method
// Please see the file names P018-dynamic-programming.cpp


#include <fstream>
#include <iostream>
#include <vector>

struct Node {
	int distance {0};
	int total {0};
};

void calculateMaxPath(std::vector<Node*>& graph, std::vector<int>& triangleNums, size_t len, int nodeID, int total) {
	total += graph[nodeID]->distance;
	if (total > graph[nodeID]->total) {
		graph[nodeID]->total = total;
		
		// Calulate next nodes
		for (size_t i {0}; i<16; i++) {
			if (triangleNums[i] > nodeID) {
				// have gone one past and array is 0 indexed so values needed are i and i+1
				// check if in bounds
				if (i<15) { // if not last row
					calculateMaxPath(graph, triangleNums, len, nodeID+i, total);
					calculateMaxPath(graph, triangleNums, len, nodeID+i+1, total);
				} else { // if last row
					if (total > graph[len]->total) {
						// update final answer
						graph[len]->total = total;
					}
					// End case
					return;
				}
				break;

			}
		}
	} else {
		// not largest so terminate
		return;
	}
	//std::cout << total << '\n';



}


void deleteGraph(std::vector<Node*>& graph) {
	for (auto node : graph) {
		delete node;
	}
}


int main() {


	// Create input file stream
	std::ifstream input{"P018.txt"};
	

	// Calculate how many nodes with n/2 (n+1) and create an array of this length
	// This array will contain all integers in the triangle in order which is the distances between nodes in a graph
	
	size_t len {static_cast<size_t>(15.0/2*16)};
	
	std::vector<Node*> graph(len+1); // Create array this long + 1 to store final answer


	// Read file into array
	for (size_t i{0}; i<len; i++) {
		if (input) {
			int tmp{};
			input >> tmp;
			graph[i] = new Node{tmp};
		}
	}
	// Add final node to be answer value
	graph[len] = new Node{};

	// Perform a recursive algorithm on graph to find greatest path
	// No distance matrix or linked list is required as it can be calculated mathematically
	//
	//       1               0
	//       2             1   2
	//       3           3   4   5
	//       4         6   7   8   9
	// 
	// To find the nodes that can be traversed from any given node add the row number to the node number and then add 1 for the 2nd node
	// Row number can be calculated as
	// First integer on each row is sequence n/2 (n-1)
	// If row number = n, and node = x
	// n/2 (n-1) <= x < n/2 (n+1)
	// 
	// Create an arrow of nth triangle numbers n/2 (n+1)
	
	std::vector<int> triangleNums(16);
	for (size_t i{0}; i<16; i++) {
		triangleNums[i] = static_cast<int>(i*(i+1.0)/2);
	}

	// So that the final values add up manually link the final nodes to a common node

	calculateMaxPath(graph, triangleNums, len, 0, 0);
	std::cout << graph[len]->total << '\n';
	

	deleteGraph(graph);

	return 0;
}
