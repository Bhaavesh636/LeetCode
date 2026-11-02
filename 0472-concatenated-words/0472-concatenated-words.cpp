class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        vector<string> ans;

        sort(words.begin(), words.end(), [](string& a, string& b) {
            return a.size() < b.size();
        });

        for (string& word : words) {
            st.erase(word);

            int n = word.size();
            vector<int> dp(n + 1, 0);
            dp[0] = 1;

            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    if (dp[j] && st.count(word.substr(j, i - j))) {
                        dp[i] = 1;
                        break;
                    }
                }
            }

            if (dp[n]) {
                ans.push_back(word);
            }

            st.insert(word);
        }

        return ans;
    }
};