#include <bits/stdc++.h>

struct Sportsman {
public:
	int size;
	std::vector<int> minPower, maxPower;

	Sportsman(std::vector<int> &power) : minPower(power), maxPower(power), size(1) {};

	bool operator<(const Sportsman &sportsman) const {
		for (int index = 0; index < (int)maxPower.size(); index++) {
			if (maxPower[index] >= sportsman.minPower[index]) {
				return false;
			}
		}
		return true;
	}

	void merge(const Sportsman &sportsman) {
		size += sportsman.size;
		for (int index = 0; index < (int)maxPower.size(); index++) {
			minPower[index] = std::min(minPower[index], sportsman.minPower[index]);
			maxPower[index] = std::max(maxPower[index], sportsman.maxPower[index]);
		}
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTournament, numKind;
	std::cin >> numTournament >> numKind;
	std::set<Sportsman> setPower;
	while (numTournament--) {
		std::vector<int> power(numKind);
		for (int &pow : power) {
			std::cin >> pow;
		}
		Sportsman powerMan = Sportsman(power);
		auto iterator1 = setPower.lower_bound(powerMan);
		auto iterator2 = setPower.upper_bound(powerMan);
		while (iterator1 != iterator2) {
			powerMan.merge(*iterator1);
			iterator1 = setPower.erase(iterator1);
		}
		setPower.insert(powerMan);
		std::cout << setPower.rbegin()->size << '\n';
	}
	return 0;
}