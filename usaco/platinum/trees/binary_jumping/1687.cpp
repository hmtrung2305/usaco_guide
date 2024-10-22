#include <bits/stdc++.h>

struct Tree {
private:
	const int log2Distance;
	std::vector<int> parent;
	std::vector<std::vector<int>> power2Ends;

public:
	Tree(const std::vector<int> &parents) :
		log2Distance(std::ceil(std::log2(parents.size() + 1))), 
		parent(parents.size() + 1), 
		power2Ends(parent.size(), std::vector<int>(log2Distance + 1)) {
		parent[0] = -1;
		for (int node = 0; node < parents.size(); node++) {
			parent[node + 1] = parents[node];
		}
		for (int node = 0; node < (int)parent.size(); node++) {
			power2Ends[node][0] = parent[node];
		}
		for (int log2 = 1; log2 <= log2Distance; log2++) {
			for (int node = 0; node < (int)parent.size(); node++) {
				int halfWay = power2Ends[node][log2 - 1];
				if (halfWay == -1) {
					power2Ends[node][log2] = -1;
				} else {
					power2Ends[node][log2] = power2Ends[halfWay][log2 - 1];
				}
			}
		}
	}

	int kthParent(int node, int k) {
		int currentNode = node;
		for (int power = 0; power <= log2Distance; power++) {
			if ((k & (1 << power)) != 0) {
				currentNode = power2Ends[currentNode][power];
				if (currentNode == -1) {
					break;
				}
			}
		}
		return currentNode;
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numEmployee, numQuery;
	std::cin >> numEmployee >> numQuery;
	std::vector<int> bosses(numEmployee - 1);
	for (int &boss : bosses) {
		std::cin >> boss;
		boss--;
	}
	Tree tree(bosses);
	while (numQuery--) {
		int employee, distance;
		std::cin >> employee >> distance;
		employee--;
		int kthBoss = tree.kthParent(employee, distance);
		std::cout << (kthBoss == -1 ? -1 : kthBoss + 1) << '\n';
	}
	return 0;
}