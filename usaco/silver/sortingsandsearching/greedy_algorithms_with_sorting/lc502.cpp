class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        std::vector<int> order((int)profits.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](const int &index1, const int &index2) {
            return capital[index1] < capital[index2];
        });
        std::priority_queue<int> setCapital;
        int index = 0;
        while (k--) {
            while (index < (int)order.size() && w >= capital[order[index]]) {
                setCapital.emplace(profits[order[index]]);
                index++;
            }
            if (setCapital.empty()) {
                break;
            }
            w += setCapital.top();
            setCapital.pop();
        }
        return w;
    }
};