class Solution {
public:
    struct Node {
        Node* links[26];
        vector<string> suggestions;

        Node() {
            for (int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
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

            if (node->suggestions.size() < 3) {
                node->suggestions.push_back(word);
            }
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());

        for (string& product : products) {
            insert(product);
        }

        vector<vector<string>> ans;
        Node* node = root;

        for (char c : searchWord) {
            int idx = c - 'a';

            if (node != nullptr) {
                node = node->links[idx];
            }

            if (node == nullptr) {
                ans.push_back({});
            } else {
                ans.push_back(node->suggestions);
            }
        }

        return ans;
    }
};