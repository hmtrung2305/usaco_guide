#include <bits/stdc++.h>

const int STUDENT = 1e5;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::vector<std::vector<int>> divisors(STUDENT + 1);
	for (int divisor = 1; divisor <= STUDENT; divisor++) {
		for (int num = divisor; num <= STUDENT; num += divisor) {
			divisors[num].emplace_back(divisor);
		}
	}
	int numTestcase;
	std::cin >> numTestcase;
	while (numTestcase--) {
		int numStudent, numTopic;
		std::cin >> numStudent >> numTopic;
		std::vector<int> smartnessStudent(numStudent);
		for (int &smartness : smartnessStudent) {
			std::cin >> smartness;
		}
		sort(smartnessStudent.begin(), smartnessStudent.end());
		std::vector<int> frequencyTopic(numTopic + 1);
		int result = 1e9, countTopic = numTopic;
		for (int left = 0, right = 0; left < numStudent; left++) {
			while (right <= numStudent && countTopic > 0) {
				if (right < numStudent) {
					for (const int &divisor : divisors[smartnessStudent[right]]) {
						if (divisor <= numTopic) {
							countTopic -= (frequencyTopic[divisor] == 0);
							frequencyTopic[divisor]++;
						}
					}
				}
				right++;
			}
			if (right <= numStudent) {
				result = std::min(result, smartnessStudent[right - 1] - smartnessStudent[left]);
			}
			for (const int &divisor : divisors[smartnessStudent[left]]) {
				if (divisor <= numTopic) {
					frequencyTopic[divisor]--;
					countTopic += (frequencyTopic[divisor] == 0);
				}
			}
		}
		std::cout << (result == 1e9 ? -1 : result) << '\n';
	}
	return 0;
}