#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int numTestcase;
	std::cin >> numTestcase;
	while (numTestcase--) {
		int numField, numEdge;
		std::cin >> numField >> numEdge;
		std::vector<std::vector<int>> adjacent(numField);
		while (numEdge--) {
			int u, v;
			std::cin >> u >> v;
			u--; v--;
			adjacent[u].emplace_back(v);
			adjacent[v].emplace_back(u);
		}
		std::vector<int> componentField(numField, -1);
		std::function<void(int, int)> depthFirstSearch = [&](int currentField, int component) {
			if (componentField[currentField] != -1) {
				return;
			}
			componentField[currentField] = component;
			for (const int &nextField : adjacent[currentField]) {
				depthFirstSearch(nextField, component);
			}
		};
		int currentComponent = 0;
		for (int field = 0; field < numField; field++) {
			if (componentField[field] == -1) {
				depthFirstSearch(field, currentComponent);
				currentComponent++;
			}
		}
		std::vector<std::vector<int>> components(currentComponent);
		for (int index = 0; index < numField; index++) {
			components[componentField[index]].emplace_back(index);
		}
		std::function<long long(int, int)> findCost = [&](int component1, int component2) {
			int distance = 1e9;
			for (const int &field : components[component1]) {
				auto iterator = lower_bound(components[component2].begin(), components[component2].end(), field);
				if (iterator != components[component2].begin()) {
					distance = std::min(distance, abs(*(prev(iterator)) - field));
				}
				if (iterator != components[component2].end()) {
					distance = std::min(distance, abs(*iterator - field));
				}
			}
			return 1ll * distance * distance;
		};
		long long result = findCost(componentField[0], componentField[numField - 1]);
		for (int component = 1; component < currentComponent - 1; component++) {
			result = std::min(result, findCost(component, componentField[0]) + findCost(component, componentField[numField - 1]));
		}
		std::cout << result << '\n';
	}
	return 0;
}