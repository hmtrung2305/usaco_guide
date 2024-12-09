#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numStudent;
	std::cin >> numStudent;
	std::vector<int> students(numStudent);
	for (int &student : students) {
		std::cin >> student;
		student--;
	}
	std::vector<int> result(numStudent, -2);
	bool inCycle = false;
	std::function<void(int)> depthFirstSearch = [&](int currentStudent) {
		if (result[currentStudent] != -2) {
			if (result[currentStudent] == -1) {
				inCycle = true;
				result[currentStudent] = currentStudent;
			}
			return;
		}
		result[currentStudent] = -1;
		depthFirstSearch(students[currentStudent]);
		if (result[currentStudent] != -1) {
			inCycle = false;
		} else {
			result[currentStudent] = (inCycle ? currentStudent : result[students[currentStudent]]);
		}
	};
	for (int student = 0; student < numStudent; student++) {
		depthFirstSearch(student);
	}
	for (const int &student : result) {
		std::cout << student + 1 << ' ';
	}
	return 0;
}