#include <bits/stdc++.h>

int main() {
	freopen("shell.in", "r", stdin);
	freopen("shell.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numSwap;
	std::cin >> numSwap;
	std::vector<int> scoreShell(3, 0), shellOriginal(3);
	iota(shellOriginal.begin(), shellOriginal.end(), 0);
	while (numSwap--) {
		int a, b, guess;
		std::cin >> a >> b >> guess;
		a--; b--; guess--;
		std::swap(shellOriginal[a], shellOriginal[b]);
		scoreShell[shellOriginal[guess]]++;
	}
	std::cout << *max_element(scoreShell.begin(), scoreShell.end());
	return 0;
}