class Solution {
public:
    struct Node {
        Node* links[26];
        bool isEnd;

        Node() {
            for (int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
            isEnd = false;
        }
    };

    Node* root = new Node();

    void insert(string& word) {
        Node* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (node->links[idx] == nullptr) {
                node->links[idx] = new Node();
            }

            node = node->links[idx];
        }

        node->isEnd = true;
    }

    string replace(string& word) {
        Node* node = root;
        string prefix = "";

        for (char c : word) {
            int idx = c - 'a';

            if (node->links[idx] == nullptr) {
                return word;
            }

            prefix += c;
            node = node->links[idx];

            if (node->isEnd) {
                return prefix;
            }
        }

        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        for (string& word : dictionary) {
            insert(word);
        }

        stringstream ss(sentence);
        string word, ans = "";

        while (ss >> word) {
            if (!ans.empty()) {
                ans += " ";
            }

            ans += replace(word);
        }

        return ans;
    }
};