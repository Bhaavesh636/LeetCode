class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char c : s)
            freq[c]++;

        vector<string> bucket(s.size() + 1);

        for (auto& [ch, count] : freq)
            bucket[count].append(count, ch);

        string ans;

        for (int i = bucket.size() - 1; i >= 0; i--)
            ans += bucket[i];

        return ans;
    }
};