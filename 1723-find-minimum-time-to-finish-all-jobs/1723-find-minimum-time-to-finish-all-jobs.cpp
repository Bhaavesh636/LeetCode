class Solution {
public:
    int ans = INT_MAX;

    void solve(int idx, vector<int>& jobs,
               vector<int>& workers, int maxTime) {
        if (maxTime >= ans)
            return;

        if (idx == jobs.size()) {
            ans = min(ans, maxTime);  
            return;
        }

        for (int i = 0; i < workers.size(); i++) {
            if (workers[i] + jobs[idx] >= ans)
                continue;

            workers[i] += jobs[idx];

            solve(idx + 1, jobs, workers,
                  max(maxTime, workers[i]));

            workers[i] -= jobs[idx];

            if (workers[i] == 0)
                break;
        }
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.rbegin(), jobs.rend());
        vector<int> workers(k, 0);

        solve(0, jobs, workers, 0);
        return ans;
    }
};