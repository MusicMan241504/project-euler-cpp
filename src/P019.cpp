#include <cstddef>
#include <iostream>
#include <unordered_set>
bool isLeapYear(size_t year) {
	return ( year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0;
}


int main() {
	// Months with 30: 4, 6, 9, 11
	// Months with 31: 1, 3, 5, 7, 8, 10, 12
	std::unordered_set<size_t> thirty {4,6,9,11};
	int sundayCount {0};
	int weekDay {2}; // 1 Jan 1901 is Tue
	for (size_t year {1901}; year <= 2000; year++) {
		for (size_t month {1}; month <= 12; month++) {
			size_t maxDay {31};
			if (month == 2) {
				if (isLeapYear(year)) {
					maxDay = 29;
				} else {
					maxDay = 28;
				}
			} else if (thirty.find(month) != thirty.end()) { // if 30 days
				maxDay = 30;
			}

					
			for (size_t day {1}; day <= maxDay; day++) {
				if (day == 1 && weekDay == 0) { // if sunday and 1st
					sundayCount++;
				}
				// increment weekday
				weekDay++;
				weekDay = weekDay % 7;
			}
		}

	}

	std::cout << sundayCount << '\n';

	return 0;
}
