#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int lengthGarland;
	std::cin >> lengthGarland;
	std::string colorGarland;
	std::cin >> colorGarland;
	std::vector<std::vector<int>> positionColor(26);
	for (int index = 0; index < (int)colorGarland.size(); index++) {
		positionColor[colorGarland[index] - 'a'].emplace_back(index);
	}
	int numPlan;
	std::cin >> numPlan;
	while (numPlan--) {
		int amountRepaint;
		char color;
		std::cin >> amountRepaint >> color;
		int result = 0;
		if (positionColor[color - 'a'].empty()) {
			result = amountRepaint;
		} else if ((int)positionColor[color - 'a'].size() == 1) {
			result = std::min(lengthGarland, amountRepaint + 1);
		} else {
			for (int left = 0, right = 0; right < (int)positionColor[color - 'a'].size(); right++) {
				while (left + 1 <= right && positionColor[color - 'a'][right] - positionColor[color - 'a'][left] - (right - left) > amountRepaint) {
					left++;
				}
				result = std::max(result, std::min(lengthGarland, amountRepaint + right - left + 1));
			}
		}
		std::cout << result << '\n';
	}
	return 0;
}