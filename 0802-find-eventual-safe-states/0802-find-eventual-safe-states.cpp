
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++) {
            for (int v : graph[i]) {
                adj[v].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (int prev : adj[node]) {
                indegree[prev]--;

                if (indegree[prev] == 0)
                    q.push(prev);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
