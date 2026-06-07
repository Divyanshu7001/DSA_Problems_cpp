/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        unordered_map<int, TreeNode*> mp;
        unordered_set<int> childst;

        for (vector<int>& vec : descriptions) {
            int parent = vec[0], child = vec[1], isLeft = vec[2];

            if (!mp.count(parent))
                mp[parent] = new TreeNode(parent);
                
            if (!mp.count(child))
                mp[child] = new TreeNode(child);

            if (isLeft == 1)
                mp[parent]->left = mp[child];
            else
                mp[parent]->right = mp[child];

            childst.insert(child);
        }

        for (vector<int>& vec : descriptions) {
            int parent = vec[0];

            if (!childst.count(parent))
                return mp[parent];
        }

        return NULL; // never reaching here
    }
};