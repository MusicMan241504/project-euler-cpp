#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>


class Card {
	public:
		int number{0};
		char suite{0};
		Card(std::string cardStr) {
			int num{0};
			switch (cardStr[0]) {
				case 'T':
					num = 10;
					break;
				case 'J':
					num = 11;
					break;
				case 'Q':
					num = 12;
					break;
				case 'K':
					num = 13;
					break;
				case 'A':
					num = 14;
					break;
				default:
					num = cardStr[0]-'0';
			}
			number = num;
			suite = cardStr[1];
		}

};

void deleteCards(std::unordered_set<Card*>& cards) {
	for (auto card : cards) {
		delete card;
	}
}

void printDeck(std::unordered_set<Card*>& cards) {
	for (auto card : cards) {
		std::cout << card->number << card->suite << ' ';
	}
	std::cout << '\n';
}


int straightFlush(std::unordered_set<Card*>& cards) {
	char suite{(*cards.begin())->suite};
	int minVal{15};
	int maxVal{0};
	for (auto card : cards) {
		if (card->suite != suite) {
			return 0;
		}
		if (card->number > maxVal) {
			maxVal = card->number;
		}
		if (card->number < minVal) {
			minVal = card->number;
		}
	}
	if (maxVal-minVal == 4) {
		return maxVal;
	}
	return 0;
}

int flush(std::unordered_set<Card*>& cards) {
	char suite{(*cards.begin())->suite};
	for (auto card : cards) {
		if (card->suite != suite) {
			return 0;
		}
	}
	return 1;
}

int fourOfKind(std::unordered_set<Card*>& cards) {
	std::vector<int> counts(15,0);
	for (auto card : cards) {
		counts[card->number]++;
	}
	for (size_t i{0}; i < 15; i++) {
		if (counts[i] == 4) {
			return i;
		}
	}
	return 0;
}

int threeOfKind(std::unordered_set<Card*>& cards) {
	std::vector<int> counts(15,0);
	for (auto card : cards) {
		counts[card->number]++;
	}
	for (size_t i{0}; i < 15; i++) {
		if (counts[i] == 3) {
			return i;
		}
	}
	return 0;
}


int fullHouse(std::unordered_set<Card*>& cards) {
	std::vector<int> counts(15,0);
	for (auto card : cards) {
		counts[card->number]++;
	}
	int res{0};
	for (size_t i{0}; i < 15; i++) {
		if (counts[i] == 3) {
			res = 15*i;
			break;
		}
	}
	bool isPairFound{0};
	for (size_t i{0}; i < 15; i++) {
		if (counts[i] == 2) {
			res += i;
			isPairFound = 1;
			break;
		}
	}
	if (res >= 16 && isPairFound) {
		return res;
	} else {
		return 0;
	}
}

int straight(std::unordered_set<Card*>& cards) {
	std::vector<int> counts(15,0);
	for (auto card : cards) {
		counts[card->number]++;
	}
	int counter{0};
	for (size_t i{0}; i < 15; i++) {
		if (counts[i] == 1) {
			counter++;
		} else {
			counter = 0;
		}
		if (counter == 5) {
			return 1;
		}
	}
	return 0;
}

int pairs(std::unordered_set<Card*>& cards) {
	std::vector<int> counts(15,0);
	for (auto card : cards) {
		counts[card->number]++;
	}
	int total{0};
	for (size_t i{14}; i > 0; i--) {
		if (counts[i] == 2) {
			total = total*15+i;
		}
	}
	return total;
}

int highestCard(std::unordered_set<Card*>& cards) {
	std::vector<int> counts(15,0);
	for (auto card : cards) {
		counts[card->number]++;
	}
	int total{0};
	for (size_t i{14}; i > 0; i--) {
		if (counts[i] == 1) {
			total = total*15+i;
		}
	}
	return total;
}

int max(int num1, int num2) {
	if (num1 > num2) {
		return 1;
	} else if (num1 < num2) {
		return 2;
	} else {
		return 0;
	}
}


int getWinner(std::unordered_set<Card*>& player1, std::unordered_set<Card*>& player2) {
	// check straight flush
	{
		int res{max(straightFlush(player1), straightFlush(player2))};
		if (res != 0) {
			return res;
		}
	}
	// check 4 of a kind
	{
		int res{max(fourOfKind(player1), fourOfKind(player2))};
		if (res != 0) {
			return res;
		}
	}
	// check full house
	{
		int res{max(fullHouse(player1), fullHouse(player2))};
		if (res != 0) {
			return res;
		}
	}
	// check flush
	{
		int res{max(flush(player1), flush(player2))};
		if (res != 0) {
			return res;
		}
	}
	// check straight
	{
		int res{max(straight(player1), straight(player2))};
		if (res != 0) {
			return res;
		}
	}
	// check 3 of a kind
	{
		int res{max(threeOfKind(player1), threeOfKind(player2))};
		if (res != 0) {
			return res;
		}
	}
	// check 2 pair and 1 pair
	{
		int res{max(pairs(player1), pairs(player2))};
		if (res != 0) {
			return res;
		}
	}
	// check highest card
	{
		int res{max(highestCard(player1), highestCard(player2))};
		return res;
	}
}

int main() {
	int winCount{0};
	std::ifstream input{"P054_poker.txt"};
	while (input) {
		std::unordered_set<Card*> player1;
		std::unordered_set<Card*> player2;
		std::string line;
		std::getline(input, line, '\n');
		if (line == "") {
			break;
		}
		for (int i{0}; i < 10; i++) {
			std::string cardStr{line.substr(i*3,2)};

			Card* card{new Card{cardStr}};
			if (i < 5) {
				player1.insert(card);
			} else {
				player2.insert(card);
			}
		}
		//printDeck(player1);
		//printDeck(player2);
		int res{getWinner(player1, player2)};
		if (res == 1) {
			winCount++;
		}
		//std::cout << res << '\n';


		deleteCards(player1);
		deleteCards(player2);
	}

	std::cout << winCount << '\n';

	return 0;
}
