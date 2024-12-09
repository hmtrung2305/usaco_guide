#include <bits/stdc++.h>

const int LOG2 = 31;

int main() {
	freopen("cruise.in", "r", stdin);
	freopen("cruise.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numPort, numDirection, numLoop;
	std::cin >> numPort >> numDirection >> numLoop;
	std::vector<int> leftPort(numPort), rightPort(numPort);
	for (int port = 0; port < numPort; port++) {
		std::cin >> leftPort[port] >> rightPort[port];
		leftPort[port]--; rightPort[port]--;
	}
	std::string path;
	for (int index = 0; index < numDirection; index++) {
		char direction;
		std::cin >> direction;
		path += direction;
	}
	std::vector<std::vector<int>> ancestor(LOG2, std::vector<int>(numPort));
	for (int port = 0; port < numPort; port++) {
		int currentPort = port;
		for (const char &direction : path) {
			if (direction == 'L') {
				currentPort = leftPort[currentPort];
			} else {
				currentPort = rightPort[currentPort];
			}
		}
		ancestor[0][port] = currentPort;
	}
	for (int indexBit = 0; indexBit < LOG2 - 1; indexBit++) {
		for (int port = 0; port < numPort; port++) {
			ancestor[indexBit + 1][port] = ancestor[indexBit][ancestor[indexBit][port]];
		}
	}
	int result = 0;
	for (int indexBit = LOG2 - 1; indexBit >= 0; indexBit--) {
		if (numLoop & (1 << indexBit)) {
			result = ancestor[indexBit][result];
		}
	}
	std::cout << result + 1;
	return 0;
}