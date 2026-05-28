class Solution {
public:
    struct trieNode {
        int idx;
        trieNode* children[26];
        ~trieNode() {
            for (int i = 0; i < 26; i++)
                delete children[i];
        }
    };

    trieNode*
    getNode(int i) {
        trieNode* temp = new trieNode();
        temp->idx = i;

        for (int i = 0; i < 26; i++)
            temp->children[i] = NULL;

        return temp;
    }

    void insertTrie(trieNode* root, int idx, vector<string>& wordsContainer) {
        string word = wordsContainer[idx];
        int n = word.length();

        for (int j = n - 1; j >= 0; j--) {
            char ch = word[j];
            int ch_idx = ch - 'a';

            if (root->children[ch_idx] == NULL) {
                root->children[ch_idx] = getNode(idx);
            }

            root = root->children[ch_idx];

            if (wordsContainer[root->idx].length() > n) {
                root->idx = idx;
            }
        }
    }

    int searchTrie(trieNode* root, string word) {
        int result_idx = root->idx;

        int n = word.length();

        for (int i = n - 1; i >= 0; i--) {
            int ch_idx = word[i] - 'a';

            root = root->children[ch_idx];
            if (root == NULL)
                return result_idx;

            result_idx = root->idx;
        }

        return result_idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        int m = wordsContainer.size();
        int n = wordsQuery.size();

        vector<int> result(n);

        trieNode* root = getNode(0);

        for (int i = 0; i < m; i++) {
            int idx = root->idx;
            if (wordsContainer[idx].length() > wordsContainer[i].length())
                root->idx = i;

            insertTrie(root, i, wordsContainer);
        }

        for (int i = 0; i < n; i++) {
            result[i] = searchTrie(root, wordsQuery[i]);
        }

        delete root;
        return result;
    }
};