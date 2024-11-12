#include <bits/stdc++.h>

int main() {
	freopen("censor.in", "r", stdin);
	freopen("censor.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::string str, remove;
	std::cin >> str >> remove;
	std::string censored = "";
	for (const char &letter : str) {
		censored += letter;
		if ((int)censored.size() >= (int)remove.size() && censored.substr((int)censored.size() - (int)remove.size()) == remove) {
			censored.resize((int)censored.size() - (int)remove.size());
		}
	}
	std::cout << censored;
	return 0;
}