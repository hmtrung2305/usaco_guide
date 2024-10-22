class Solution {
public:
    int maxPoints(std::vector<std::vector<int>>& points) {
        int result = 1;
        for (int middle = 0; middle < (int)points.size(); middle++) {
            for (int index1 = middle + 1; index1 < (int)points.size(); index1++) {
                int count = 2;
                for (int index2 = index1 + 1; index2 < (int)points.size(); index2++) {
                    int dx1 = points[middle][0] - points[index2][0];
                    int dy1 = points[middle][1] - points[index2][1];
                    int dx2 = points[index1][0] - points[middle][0];
                    int dy2 = points[index1][1] - points[middle][1];
                    // dy1 / dx1 == dy2 / dx2
                    if (dy1 * dx2 == dy2 * dx1) {
                        count++;
                    }
                }
                result = std::max(result, count);
            }
        }
        return result;
    }
};