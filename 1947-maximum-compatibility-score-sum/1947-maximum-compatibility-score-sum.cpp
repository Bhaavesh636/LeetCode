class Solution {
public:
    int ans = 0;
    vector<vector<int>> score;
    vector<int> suffixMax;

    void solve(int idx, int curr, int mask, int n) {
        if (curr + suffixMax[idx] <= ans)
            return;

        if (idx == n) {
            ans = max(ans, curr);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (!(mask & (1 << j))) {
                solve(idx + 1, curr + score[idx][j],
                      mask | (1 << j), n);
            }
        }
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = students.size();
        score.assign(n, vector<int>(n, 0));
        suffixMax.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < students[i].size(); k++) {
                    if (students[i][k] == mentors[j][k])
                        score[i][j]++;
                }
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            int best = 0;
            for (int j = 0; j < n; j++)
                best = max(best, score[i][j]);

            suffixMax[i] = suffixMax[i + 1] + best;
        }

        solve(0, 0, 0, n);
        return ans;
    }
};