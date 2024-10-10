#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numCow;
	std::cin >> numCow;
	std::vector<std::array<int, 3>> cowsFaceNorth, cowsFaceEast;
	for (int index = 0; index < numCow; index++) {
		char face;
		int x, y;
		std::cin >> face >> x >> y;
		if (face == 'N') {
			cowsFaceNorth.push_back({x, y, index});
		} else {
			cowsFaceEast.push_back({x, y, index});
		}
	}
	sort(cowsFaceNorth.begin(), cowsFaceNorth.end(), [](std::array<int, 3> cow1, std::array<int, 3> cow2) {
		if (cow1[0] == cow2[0]) {
			return cow1[1] < cow2[1];
		}
		return cow1[0] < cow2[0];
	});
	sort(cowsFaceEast.begin(), cowsFaceEast.end(), [](std::array<int, 3> cow1, std::array<int, 3> cow2) {
		if (cow1[1] == cow2[1]) {
			return cow1[0] < cow2[0];
		}
		return cow1[1] < cow2[1];
	});
	std::vector<int> countBlame(numCow, 0);
	std::vector<bool> stopped(numCow, false);
	for (std::array<int, 3> cowFaceNorth : cowsFaceNorth) {
		for (std::array<int, 3> cowFaceEast : cowsFaceEast) {
			if (!stopped[cowFaceNorth[2]] && !stopped[cowFaceEast[2]] && cowFaceNorth[0] >= cowFaceEast[0] && cowFaceNorth[1] <= cowFaceEast[1]) {
				// length to the intersection
				int lengthCowFaceNorth = cowFaceEast[1] - cowFaceNorth[1];
				int lengthCowFaceEast = cowFaceNorth[0] - cowFaceEast[0];
				if (lengthCowFaceNorth < lengthCowFaceEast) {
					stopped[cowFaceEast[2]] = true;
					countBlame[cowFaceNorth[2]] += 1 + countBlame[cowFaceEast[2]];
				} else if (lengthCowFaceNorth > lengthCowFaceEast) {
					stopped[cowFaceNorth[2]] = true;
					countBlame[cowFaceEast[2]] += 1 + countBlame[cowFaceNorth[2]];
				}
			}
		}
	}
	for (int index = 0; index < numCow; index++) {
		std::cout << countBlame[index] << '\n';
	}
	return 0;
}