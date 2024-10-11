#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numFlat;
	std::cin >> numFlat;
	std::string typePokemon;
	std::cin >> typePokemon;
	std::map<char, bool> hasType;
	int totalTypePokemon = 0;
	for (const char &type : typePokemon) {
		if (!hasType[type]) {
			hasType[type] = true;
			totalTypePokemon++;
		}
	}
	std::map<char, int> frequencyType;
	int result = 1e9;
	int countType = 0;
	for (int left = 0, right = 0; right < numFlat; right++) {
		if (frequencyType[typePokemon[right]] == 0) {
			countType++;
		}
		frequencyType[typePokemon[right]]++;
		if (countType == totalTypePokemon) {
			while (left + 1 <= right && frequencyType[typePokemon[left]] - 1 > 0) {
				frequencyType[typePokemon[left]]--;
				left++;
			}
			result = std::min(result, right - left + 1);
		}
	}
	std::cout << result;
	return 0;
}