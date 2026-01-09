/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//T.C=O(N)
//S.C=O(maxDepth)
class Solution {
public:
    unordered_map<int, int> mp;
    int maxDepth = 0;

    TreeNode* LCA(TreeNode* root) {
        if (root == NULL || mp[root->val] == maxDepth)
            return root;

        TreeNode* l = LCA(root->left);
        TreeNode* r = LCA(root->right);

        if (l && r)
            return root;

        return l != NULL ? l : r;
    }

    void depth(TreeNode* root, int d) {
        if (!root)
            return;

        maxDepth = max(maxDepth, d);

        mp[root->val] = d;
        if (root->left)
            depth(root->left, d + 1);
        if (root->right)
            depth(root->right, d + 1);
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        depth(root, 0);
        return LCA(root);
    }
};