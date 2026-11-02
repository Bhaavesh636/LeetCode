class Solution {
public:
    int cross(vector<int>& a, vector<int>& b, vector<int>& c) {
        return (b[0] - a[0]) * (c[1] - a[1]) -
               (b[1] - a[1]) * (c[0] - a[0]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(), trees.end());

        trees.erase(unique(trees.begin(), trees.end()), trees.end());

        if (trees.size() <= 2) {
            return trees;
        }

        vector<vector<int>> hull;

        for (auto& p : trees) {
            while (hull.size() >= 2 &&
                   cross(hull[hull.size() - 2], hull.back(), p) < 0) {
                hull.pop_back();
            }

            hull.push_back(p);
        }

        int lowerSize = hull.size();

        for (int i = trees.size() - 2; i >= 0; i--) {
            while (hull.size() > lowerSize &&
                   cross(hull[hull.size() - 2], hull.back(), trees[i]) < 0) {
                hull.pop_back();
            }

            hull.push_back(trees[i]);
        }

        hull.pop_back();

        set<vector<int>> uniquePoints(hull.begin(), hull.end());

        return vector<vector<int>>(uniquePoints.begin(), uniquePoints.end());
    }
};