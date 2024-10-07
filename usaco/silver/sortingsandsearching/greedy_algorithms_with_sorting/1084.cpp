#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numApplicant, numApartment, maxDifference;
	std::cin >> numApplicant >> numApartment >> maxDifference;
	std::vector<int> sizeDesired(numApplicant);
	for (int &size : sizeDesired) {
		std::cin >> size;
	}
	std::vector<int> sizeApartment(numApartment);
	for (int &size : sizeApartment) {
		std::cin >> size;
	}
	sort(sizeDesired.begin(), sizeDesired.end());
	sort(sizeApartment.begin(), sizeApartment.end());
	int result = 0;
	for (int indexApplicant = 0, indexApartment = 0; indexApplicant < numApplicant && indexApartment < numApartment; ) {
		if (abs(sizeDesired[indexApplicant] - sizeApartment[indexApartment]) <= maxDifference) {
			result++;
			indexApplicant++;
			indexApartment++;
		} else if (sizeDesired[indexApplicant] < sizeApartment[indexApartment]) {
			indexApplicant++;
		} else {
			indexApartment++;
		}
	}
	std::cout << result;
	return 0;
}