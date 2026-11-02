class Solution {
public:
    int partition(vector<vector<int>>& points, int left, int right) {
        int pivot = points[right][0] * points[right][0] +
                    points[right][1] * points[right][1];

        int i = left;

        for (int j = left; j < right; j++) {
            int dist = points[j][0] * points[j][0] +
                       points[j][1] * points[j][1];

            if (dist <= pivot) {
                swap(points[i], points[j]);
                i++;
            }
        }

        swap(points[i], points[right]);
        return i;
    }

    void quickSelect(vector<vector<int>>& points, int left, int right, int k) {
        if (left >= right) {
            return;
        }

        int pivot = partition(points, left, right);

        if (pivot == k) {
            return;
        }

        if (pivot < k) {
            quickSelect(points, pivot + 1, right, k);
        } else {
            quickSelect(points, left, pivot - 1, k);
        }
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quickSelect(points, 0, points.size() - 1, k - 1);

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};