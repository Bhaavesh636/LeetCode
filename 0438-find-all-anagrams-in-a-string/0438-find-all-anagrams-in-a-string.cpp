
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        int n = s.size();
        int m = p.size();

        if (m > n)
            return ans;

        vector<int> freq(26, 0);

        for (char c : p)
            freq[c - 'a']++;

        int left = 0;

        for (int right = 0; right < n; right++) {
            freq[s[right] - 'a']--;

            if (right - left + 1 > m) {
                freq[s[left] - 'a']++;
                left++;
            }

            if (right - left + 1 == m) {
                bool valid = true;

                for (int x : freq) {
                    if (x != 0) {
                        valid = false;
                        break;
                    }
                }

                if (valid)
                    ans.push_back(left);
            }
        }

        return ans;
    }
};
