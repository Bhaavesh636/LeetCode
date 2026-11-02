class Solution {
public:
    struct Node {
        Node* links[26];
        string word;

        Node() {
            for (int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
            word = "";
        }
    };

    Node* root = new Node();
    vector<string> ans;
    int m, n;

    void insert(string& word) {
        Node* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (node->links[idx] == nullptr) {
                node->links[idx] = new Node();
            }

            node = node->links[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, Node* node) {
        char c = board[i][j];

        if (c == '#' || node->links[c - 'a'] == nullptr) {
            return;
        }

        node = node->links[c - 'a'];

        if (node->word != "") {
            ans.push_back(node->word);
            node->word = "";
        }

        board[i][j] = '#';

        if (i > 0) {
            dfs(board, i - 1, j, node);
        }

        if (j > 0) {
            dfs(board, i, j - 1, node);
        }

        if (i + 1 < m) {
            dfs(board, i + 1, j, node);
        }

        if (j + 1 < n) {
            dfs(board, i, j + 1, node);
        }

        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        for (string& word : words) {
            insert(word);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};