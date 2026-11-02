
class Solution {
public:
    vector<int> buildLPS(string& s) {
        int n = s.size();
        vector<int> lps(n, 0);

        int len = 0, i = 1;

        while (i < n) {
            if (s[i] == s[len]) {
                lps[i++] = ++len;
            }
            else if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i++] = 0;
            }
        }

        return lps;
    }

    int repeatedStringMatch(string a, string b) {
        string text = a;
        int count = 1;

        while (text.size() < b.size()) {
            text += a;
            count++;
        }

        vector<int> lps = buildLPS(b);

        int i = 0, j = 0;

        while (i < text.size()) {
            if (text[i] == b[j]) {
                i++;
                j++;
            }

            if (j == b.size())
                return count;

            if (i < text.size() && text[i] != b[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        text += a;
        count++;

        i = 0;
        j = 0;

        while (i < text.size()) {
            if (text[i] == b[j]) {
                i++;
                j++;
            }

            if (j == b.size())
                return count;

            if (i < text.size() && text[i] != b[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return -1;
    }
};
