class WordDictionary {
public:
    struct Node {
        Node* links[26];
        bool flag;

        Node() {
            for (int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
            flag = false;
        }
    };

    Node* root;

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (node->links[idx] == nullptr) {
                node->links[idx] = new Node();
            }

            node = node->links[idx];
        }

        node->flag = true;
    }

    bool dfs(string& word, int pos, Node* node) {
        if (pos == word.size()) {
            return node->flag;
        }

        if (word[pos] == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->links[i] && dfs(word, pos + 1, node->links[i])) {
                    return true;
                }
            }

            return false;
        }

        int idx = word[pos] - 'a';

        if (node->links[idx] == nullptr) {
            return false;
        }

        return dfs(word, pos + 1, node->links[idx]);
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */