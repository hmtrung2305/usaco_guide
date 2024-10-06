#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numPupil, numFriendShip;
	std::cin >> numPupil >> numFriendShip;
	std::vector<std::vector<int>> adjacent(numPupil);
	while (numFriendShip--) {
		int pupil1, pupil2;
		std::cin >> pupil1 >> pupil2;
		pupil1--; pupil2--;
		adjacent[pupil1].emplace_back(pupil2);
		adjacent[pupil2].emplace_back(pupil1);
	}
	bool satisfyCondition = true;
	std::vector<int> teamPupil(numPupil, 0);
	std::queue<std::pair<int, int>> queuePupil;
	for (int pupil = 0; pupil < numPupil; pupil++) {
		if (teamPupil[pupil] == 0) {
			queuePupil.emplace(pupil, 1);
		}
		while (!queuePupil.empty()) {
			auto [currentPupil, currentTeam] = queuePupil.front();
			queuePupil.pop();
			if (teamPupil[currentPupil] == 0) {
				teamPupil[currentPupil] = currentTeam;
				for (int nextPupil : adjacent[currentPupil]) {
					if (teamPupil[currentPupil] == teamPupil[nextPupil]) {
						satisfyCondition = false;
					}
					if (teamPupil[nextPupil] == 0) {
						queuePupil.emplace(nextPupil, currentTeam ^ 3);
					}
				}
			}
		}
	}
	if (satisfyCondition) {
		for (int team : teamPupil) {
			std::cout << team << ' ';
		}
	} else {
		std::cout << "IMPOSSIBLE";
	}
	return 0;
}