#include <bits/stdc++.h>

int main() {
	freopen("breedflip.in", "r", stdin);
	freopen("breedflip.out", "w", stdout);
	int numCow;
	std::cin >> numCow;
	std::string target, str;
	std::cin >> target >> str;
	int result = 0;
	for (int index = 0; index < numCow; index++) {
		while (index + 1 < numCow && str[index + 1] != target[index + 1]) {
			index++;
		}
		if (index < numCow && str[index] != target[index]) {
			result++;
		}
	}
	std::cout << result;
	return 0;
}