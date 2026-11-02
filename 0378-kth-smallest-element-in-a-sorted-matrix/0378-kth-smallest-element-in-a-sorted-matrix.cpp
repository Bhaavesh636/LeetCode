
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        for (int i = 0; i < n; i++)
            pq.push({matrix[i][0], i, 0});

        while (k > 1) {
            auto [val, row, col] = pq.top();
            pq.pop();

            if (col + 1 < n)
                pq.push({matrix[row][col + 1], row, col + 1});

            k--;
        }

        return get<0>(pq.top());
    }
};
